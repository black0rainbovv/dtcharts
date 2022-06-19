#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "moveitem.h"
#include"selectdeviceform.h"
#include"about.h"
#include"dtsettings.h"

#include <QBitmap>

QList<QSpinBox*> Calib_list;
QList<QSpinBox*> X_list;
QList<QSpinBox*> Y_list;
QList<QLineEdit*> Exp_list;

QPoint p1, p2, pc;
int channels_count = 0;
QList<QColor> channel_color;
QBitmap *videoImage;

MainWindow::MainWindow(QWidget *parent ) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("DTCharts");
    globaltime = new QTime();
    globaltimeison = false;
    xAxisShift = 0.0;

    channel_color << QColor("#2424ff") << QColor("#48ff48") << QColor("#ffc312")
                  << QColor("#9f00c5") << QColor("#e43a00");

    rubberBand = 0;
    m3pressed = false;
    tconnect = new QTimer;
    DTconnected = false;
    isScaled = false;
    plotting = false;
    plottime = 0;
    oldScale = false;
    settingdialodshown = false;
    p = new PlotDialog();
    cycleNumber = 0;
    cycleState = -1;
    newcycleState = -1;
    efficiency_plus = 0;
    efficiency_minus = 0;
    efficiency_plusm = 0;
    efficiency_minusm = 0;
    cycleP = 0;
    cycleM = 0;
    cyclePMeasures = 0;
    cycleMMeasures = 0;
    newindex = 0;
    QPen cpen;
    QVector<qreal> dashes;
    dashes << 20 << 5;
    cpen.setDashPattern(dashes);
    ui->actionDT_setting->setVisible(false);
    ui->dateTimeEdit->setVisible(false);

    for(int i=0; i<20; i++)
        activeChannels[i] = false;

    plot_colors.append(QColor(Qt::magenta).name());
    plot_colors.append(QColor(Qt::blue).name());
    plot_colors.append(QColor(Qt::cyan).name());
    plot_colors.append(QColor(Qt::yellow).name());
    plot_colors.append(QColor(Qt::black).name());
    plot_colors.append(QColor(Qt::red).name());

    plot_colors.append("#006600");
    plot_colors.append("#ff4500");
    plot_colors.append(QColor(Qt::white).name());

    plot_colors.append(QColor(Qt::red).name());
    plot_colors.append(QColor(Qt::black).name());
    plot_colors.append(QColor(Qt::yellow).name());
    plot_colors.append(QColor(Qt::cyan).name());
    plot_colors.append(QColor(Qt::blue).name());
    plot_colors.append(QColor(Qt::magenta).name());

    plot_colors.append("-");

    plot_colors.append("#2424ff");
    plot_colors.append("#48ff48");
    plot_colors.append("#ffc312");
    plot_colors.append("#9f00c5");
    rb = false;

    setTable();
    SetPlot();

    ui->plotwidget->installEventFilter(this);
    ReadFileSettings();
    ReadTermSettings();

    ui->statusBar->addPermanentWidget(ui->versioLabel, 1);
    ui->statusNowLabel->setText("Not connected");

    QTimer *hideBox = new QTimer;
    hideBox->setInterval(300);
    hideBox->start();
    QObject::connect(hideBox, SIGNAL(timeout()), this, SLOT(ChangeGeometry()));

    QObject::connect(p, SIGNAL(setPlotSettings(bool, bool, QColor, QByteArray, int*, QStringList)),
                     this, SLOT(getPlotSettings(bool, bool, QColor, QByteArray, int*, QStringList)));

    QObject::connect(this, SIGNAL(SendFileSettings(bool, bool, QString, QByteArray, int*,QStringList)),
                     p, SLOT(GetFileSettings(bool, bool, QString, QByteArray, int*, QStringList)));

    QObject::connect(ui->plotwidget, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(mousePress(QMouseEvent*)));
    QObject::connect(ui->plotwidget, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(mouseMove(QMouseEvent*)));
    QObject::connect(ui->plotwidget, SIGNAL(mouseRelease(QMouseEvent*)), this, SLOT(mouseRelease(QMouseEvent*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if(event->type() == QEvent::Resize && obj == ui->plotwidget)
    {
        ui->label_W->move(ui->plotwidget->x()+ui->plotwidget->width()-150,
                          ui->plotwidget->y()+10);
    }
    return(QWidget::eventFilter(obj, event));
}

void MainWindow::on_actionDT_setting_triggered()
{
    if(DTconnected){
        dtsettingForm = new dtsettings;
        dtsettingForm->show();
    }
    else
        QMessageBox::critical(this,"Warning!","Device is not connected");
}

void MainWindow::on_actionAbout_triggered()
{
    aboutform = new about();
    aboutform->show();

}

void MainWindow::on_pushButtonStart_clicked()
{
    if(DTconnected)
    {
        if(ui->tableWidget->rowCount() > 1)
        {
            cycleNumber = 0;
            efficiency_plus = 0;
            efficiency_minus = 0;
            efficiency_plusm = 0;
            efficiency_minusm = 0;
            cycleparams.clear();

            QStringList cyclelist;
            for(int i=0; i<ui->tableWidget->rowCount(); i++)
            {
                QDoubleSpinBox *temp = qobject_cast<QDoubleSpinBox*>(ui->tableWidget->cellWidget(i,0));
                if(temp != NULL)
                {
                    QTimeEdit *time = qobject_cast<QTimeEdit*>(ui->tableWidget->cellWidget(i,2));
                    if(time != NULL)
                    {
                        cyclelist.append(QString::number(temp->value()*100.0, 'f', 0)+";"+QString::number(time->time().minute()*60+time->time().second()));
                    }
                }
            }
            QApplication::processEvents();
            mutex.lock();
            QString outs;
            USBCy_RW("XM", outs, usb, Temp_uC);
            QThread::msleep(60);
            double a = 0.0;
            int cycles;
            for(int i=0; i<6; i++)
            {
                a += outs.split(" ")[i].toDouble()/100.0;
            }
            if(a/6 < cyclelist[ui->tableWidget->rowCount()-1].split(";")[0].toDouble())
                cycles = ui->cyc_spinBox->value();
            else
                cycles = ui->cyc_spinBox->value()+1;

            USBCy_RW("HPRESS", outs, usb, Motor_uC);
            QThread::msleep(60);
            USBCy_RW("XPRG 0 35 0", outs, usb, Temp_uC);
            QThread::msleep(60);
            for(int i=0; i<cyclelist.size(); i++)
            {
                USBCy_RW("XLEV "+QString::number(cyclelist[i].split(";")[0].toInt())+" "
                        +QString::number(cyclelist[i].split(";")[1].toInt())
                        +" 0 0 0 0" , outs, usb, Temp_uC);
                QThread::msleep(60);

            }
            USBCy_RW("XCYC "+QString::number(cycles), outs, usb, Temp_uC);
            QThread::msleep(60);
            USBCy_RW("XSAV ThermCycleTest", outs, usb, Temp_uC);
            QThread::msleep(60);
            USBCy_RW("RN", outs, usb, Temp_uC);
            mutex.unlock();
        }
    }
    else
        QMessageBox::critical(this, "Warning", "Device is not connected.");
}

void MainWindow::on_pushButtonStop_clicked()

{
    QString outs;
    mutex.lock();
    USBCy_RW("ST", outs, usb, Temp_uC);
    QThread::msleep(60);
    mutex.unlock();
}
void MainWindow::on_actionConnect_device_2_clicked()
{
    deviceForm = new selectdeviceform();
    deviceForm->show();

    QObject::connect(deviceForm,SIGNAL(getNumber(QString,bool)),this,SLOT(setDevicenumber(QString,bool)));
    QObject::connect(deviceForm,SIGNAL(getIndex(int)),this,SLOT(setIndex(int)));
}

void MainWindow::on_actionDisconnect_device_2_clicked()
{
    if(DTconnected == true){
        if(usb->IsOpen()){
            usb->Close();
            DTconnected = false;
            ui->device_label->setText(" ");
            ui->statusNowLabel->setText("Not connected");

            if(plotting)
                   {
                       emit SendStop();
                       plotting = false;
                   }
        }
        else
            QMessageBox::critical(this,"Warning","USB don't' opened");
    }
    else
        QMessageBox::critical(this,"Warning","Device don't' connected");
}

void MainWindow::setIndex(int index)
{
    usb = new CyDev(NULL);
    newindex = index;
    if(usb->IsOpen()){
        QMessageBox::critical(this,"Warning","Device is already connected");
    }
    else{
        usb->Open(index);
        if(usb->IsOpen()){
            Optic_uC = new CANChannels(usb,2);
            Temp_uC = new CANChannels(usb,3);
            Motor_uC = new CANChannels(usb,4);
            Disp_uC = new CANChannels(usb,5);
            DTconnected = true;
            ReadFromDevice();
            tconnect->start(1000);
            QObject::connect(tconnect, SIGNAL(timeout()), this, SLOT(PCTimeNow()));
            QObject::connect(tconnect, SIGNAL(timeout()), this, SLOT(CheckConnection()));
        }
        else
            QMessageBox::critical(this,"Warning","Can not disconnect device!");
    }
}

void MainWindow::setDevicenumber(QString DTSN, bool connection)
{
    if(connection == true){
        ui->device_label->setText(DTSN);
        this->setWindowTitle("DTCharts - "+DTSN);
        deviceForm->close();
    }
    else
        DTconnected = false;
}

void MainWindow::ReadFileSettings()
{
    int x, y, w, h, chid;
    int top_value, bot_value;

    QFile file("./plugins/data/settings.xml");
    if(file.open(QIODevice::ReadOnly))
    {
        QXmlStreamReader sr(&file);
        while(!sr.atEnd())
        {
            if(sr.isStartElement())
            {
                if(sr.name() == "MainForm")
                {
                    while(!sr.atEnd())
                    {
                        if(sr.isEndElement())
                        {
                            sr.readNext();
                            break;
                        }
                        if(sr.isStartElement())
                        {
                            if(sr.name() == "geometry")
                            {
                                while(!sr.atEnd())
                                {
                                    if(sr.isEndElement())
                                    {
                                        sr.readNext();
                                        break;
                                    }
                                    if(sr.isStartElement())
                                    {
                                        if(sr.name() == "x")
                                        {
                                            while(!sr.atEnd())
                                            {
                                                if(sr.isEndElement())
                                                {
                                                    sr.readNext();
                                                    break;
                                                }
                                                if(sr.isStartElement())
                                                {
                                                    x =  sr.readElementText().toInt();
                                                    sr.readNext();
                                                    break;
                                                }
                                                else
                                                {
                                                    sr.readNext();
                                                }
                                            }
                                        }
                                        if(sr.name() == "y")
                                        {
                                            while(!sr.atEnd())
                                            {
                                                if(sr.isEndElement())
                                                {
                                                    sr.readNext();
                                                    break;
                                                }
                                                if(sr.isStartElement())
                                                {
                                                    y =  sr.readElementText().toInt();
                                                    sr.readNext();
                                                    break;
                                                }
                                                else
                                                {
                                                    sr.readNext();
                                                }
                                            }
                                        }
                                        if(sr.name() == "width")
                                        {
                                            while(!sr.atEnd())
                                            {
                                                if(sr.isEndElement())
                                                {
                                                    sr.readNext();
                                                    break;
                                                }
                                                if(sr.isStartElement())
                                                {
                                                    w =  sr.readElementText().toInt();
                                                    sr.readNext();
                                                    break;
                                                }
                                                else
                                                {
                                                    sr.readNext();
                                                }
                                            }
                                        }
                                        if(sr.name() == "height")
                                        {
                                            while(!sr.atEnd())
                                            {
                                                if(sr.isEndElement())
                                                {
                                                    sr.readNext();
                                                    break;
                                                }
                                                if(sr.isStartElement())
                                                {
                                                    h =  sr.readElementText().toInt();
                                                    sr.readNext();
                                                    break;
                                                }
                                                else
                                                {
                                                    sr.readNext();
                                                }
                                            }
                                        }
                                        sr.readNext();
                                    }
                                    else
                                        sr.readNext();
                                }
                            }
                            if(sr.name() == "teststeps")
                            {
                                while(!sr.atEnd())
                                {
                                    if(sr.isEndElement())
                                    {
                                        sr.readNext();
                                        break;
                                    }
                                    if(sr.isStartElement())
                                    {
                                        if(sr.name() == "V")
                                        {
                                            while(!sr.atEnd())
                                            {
                                                if(sr.isEndElement())
                                                {
                                                    sr.readNext();
                                                    break;
                                                }
                                                if(sr.isStartElement())
                                                {
                                                    break;
                                                }
                                                else
                                                {
                                                    sr.readNext();
                                                }
                                            }
                                        }
                                        if(sr.name() == "H")
                                        {
                                            while(!sr.atEnd())
                                            {
                                                if(sr.isEndElement())
                                                {
                                                    sr.readNext();
                                                    break;
                                                }
                                                if(sr.isStartElement())
                                                {
                                                    break;
                                                }
                                                else
                                                {
                                                    sr.readNext();
                                                }
                                            }
                                        }
                                        if(sr.name() == "LF")
                                        {
                                            while(!sr.atEnd())
                                            {
                                                if(sr.isEndElement())
                                                {
                                                    sr.readNext();
                                                    break;
                                                }
                                                if(sr.isStartElement())
                                                {
                                                    break;
                                                }
                                                else
                                                {
                                                    sr.readNext();
                                                }
                                            }
                                        }
                                        sr.readNext();
                                    }
                                    else
                                        sr.readNext();
                                }
                            }
                            if(sr.name() == "optics")
                            {
                                while(!sr.atEnd())
                                {
                                    if(sr.isEndElement())
                                    {
                                        sr.readNext();
                                        break;
                                    }
                                    if(sr.isStartElement())
                                    {
                                        if(sr.name() == "cycles")
                                        {
                                            while(!sr.atEnd())
                                            {
                                                if(sr.isEndElement())
                                                {
                                                    sr.readNext();
                                                    break;
                                                }
                                                if(sr.isStartElement())
                                                {
                                                    break;
                                                }
                                                else
                                                {
                                                    sr.readNext();
                                                }
                                            }
                                        }
                                        if(sr.name() == "time")
                                        {
                                            while(!sr.atEnd())
                                            {
                                                if(sr.isEndElement())
                                                {
                                                    sr.readNext();
                                                    break;
                                                }
                                                if(sr.isStartElement())
                                                {
                                                    break;
                                                }
                                                else
                                                {
                                                    sr.readNext();
                                                }
                                            }
                                        }
                                        sr.readNext();
                                    }
                                    else
                                        sr.readNext();
                                }
                            }
                            else
                                sr.readNext();
                        }
                        else
                            sr.readNext();
                    }
                }
                if(sr.name() == "PlotDialog")
                {
                    while(!sr.atEnd())
                    {
                        if(sr.isEndElement())
                        {
                            sr.readNext();
                            break;
                        }
                        if(sr.name() == "oldscale")
                        {
                            while(!sr.atEnd())
                            {
                                if(sr.isEndElement())
                                {
                                    sr.readNext();
                                    break;
                                }
                                if(sr.isStartElement())
                                {
                                    if(sr.readElementText().toInt() == 1)
                                        oldScale = true;
                                    else
                                        oldScale = false;
                                    sr.readNext();
                                    break;
                                }
                                else
                                    sr.readNext();
                            }
                        }
                        if(sr.name() == "radinteger")
                        {
                            while(!sr.atEnd())
                            {
                                if(sr.isEndElement())
                                {
                                    sr.readNext();
                                    break;
                                }
                                if(sr.isStartElement())
                                {
                                    if(sr.readElementText().toInt() == 1)
                                        radInteger = true;
                                    else
                                        radInteger = false;
                                    sr.readNext();
                                    break;
                                }
                                else
                                    sr.readNext();
                            }
                        }
                        if(sr.name() == "background")
                        {
                            while(!sr.atEnd())
                            {
                                if(sr.isEndElement())
                                {
                                    sr.readNext();
                                    break;
                                }
                                if(sr.isStartElement())
                                {
                                    plot_background =  sr.readElementText();
                                    sr.readNext();
                                    break;
                                }
                                else
                                    sr.readNext();
                            }
                        }
                        if(sr.name() == "cursors")
                        {
                            while(!sr.atEnd())
                            {
                                if(sr.isEndElement())
                                {
                                    sr.readNext();
                                    break;
                                }
                                if(sr.isStartElement())
                                {
                                    if(sr.name() == "top")
                                    {
                                        while(!sr.atEnd())
                                        {
                                            if(sr.isEndElement())
                                            {
                                                sr.readNext();
                                                break;
                                            }
                                            if(sr.isStartElement())
                                            {
                                                if(sr.name() == "value")
                                                {
                                                    while(!sr.atEnd())
                                                    {
                                                        if(sr.isEndElement())
                                                        {
                                                            sr.readNext();
                                                            break;
                                                        }
                                                        if(sr.isStartElement())
                                                        {
                                                            top_value =  sr.readElementText().toInt();
                                                            sr.readNext();
                                                            break;
                                                        }
                                                        else
                                                            sr.readNext();
                                                    }
                                                }
                                                if(sr.name() == "enabled")
                                                {
                                                    while(!sr.atEnd())
                                                    {
                                                        if(sr.isEndElement())
                                                        {
                                                            sr.readNext();
                                                            break;
                                                        }
                                                        if(sr.isStartElement())
                                                        {

                                                            cursors_parametres[0] = sr.readElementText().toInt();
                                                            sr.readNext();
                                                            break;
                                                        }
                                                        else
                                                            sr.readNext();
                                                    }
                                                }
                                                sr.readNext();
                                            }
                                            else
                                                sr.readNext();
                                        }
                                    }
                                    if(sr.name() == "mid")
                                    {
                                        while(!sr.atEnd())
                                        {
                                            if(sr.isEndElement())
                                            {
                                                sr.readNext();
                                                break;
                                            }
                                            if(sr.isStartElement())
                                            {
                                                if(sr.name() == "enabled")
                                                {
                                                    while(!sr.atEnd())
                                                    {
                                                        if(sr.isEndElement())
                                                        {
                                                            sr.readNext();
                                                            break;
                                                        }
                                                        if(sr.isStartElement())
                                                        {

                                                            cursors_parametres[1] = sr.readElementText().toInt();
                                                            sr.readNext();
                                                            break;
                                                        }
                                                        else
                                                            sr.readNext();
                                                    }
                                                }
                                                sr.readNext();
                                            }
                                            else
                                                sr.readNext();
                                        }
                                    }
                                    if(sr.name() == "bot")
                                    {
                                        while(!sr.atEnd())
                                        {
                                            if(sr.isEndElement())
                                            {
                                                sr.readNext();
                                                break;
                                            }
                                            if(sr.isStartElement())
                                            {
                                                if(sr.name() == "value")
                                                {
                                                    while(!sr.atEnd())
                                                    {
                                                        if(sr.isEndElement())
                                                        {
                                                            sr.readNext();
                                                            break;
                                                        }
                                                        if(sr.isStartElement())
                                                        {
                                                            bot_value =  sr.readElementText().toInt();
                                                            sr.readNext();
                                                            break;
                                                        }
                                                        else
                                                        {
                                                            sr.readNext();
                                                        }
                                                    }
                                                }
                                                if(sr.name() == "enabled")
                                                {
                                                    while(!sr.atEnd())
                                                    {
                                                        if(sr.isEndElement())
                                                        {
                                                            sr.readNext();
                                                            break;
                                                        }
                                                        if(sr.isStartElement())
                                                        {

                                                            cursors_parametres[2] = sr.readElementText().toInt();
                                                            sr.readNext();
                                                            break;
                                                        }
                                                        else
                                                        {
                                                            sr.readNext();
                                                        }
                                                    }
                                                }
                                                sr.readNext();
                                            }
                                            else
                                                sr.readNext();
                                        }
                                    }
                                    if(sr.name() == "anchor")
                                    {
                                        while(!sr.atEnd())
                                        {
                                            if(sr.isEndElement())
                                            {
                                                sr.readNext();
                                                break;
                                            }
                                            if(sr.isStartElement())
                                            {
                                                cursors_parametres[3] = sr.readElementText().toInt();
                                                sr.readNext();
                                                break;
                                            }
                                            else
                                            {
                                                sr.readNext();
                                            }
                                        }
                                    }
                                    sr.readNext();
                                }
                                else
                                    sr.readNext();
                            }
                        }
                        if(sr.name() == "channels")
                        {
                            while(!sr.atEnd())
                            {
                                if(sr.isEndElement())
                                {
                                    sr.readNext();
                                    break;
                                }
                                if(sr.isStartElement())
                                {
                                    if(sr.name() == "channel")
                                    {
                                        chid = sr.attributes().value("id").toInt();
                                        while(!sr.atEnd())
                                        {
                                            if(sr.isEndElement())
                                            {
                                                sr.readNext();
                                                break;
                                            }
                                            if(sr.isStartElement())
                                            {
                                                if(sr.name() == "enabled")
                                                {
                                                    while(!sr.atEnd())
                                                    {
                                                        if(sr.isEndElement())
                                                        {
                                                            sr.readNext();
                                                            break;
                                                        }
                                                        if(sr.isStartElement())
                                                        {
                                                            if(sr.readElementText().toInt() == 1)
                                                                activeChannels[chid] = true;
                                                            else
                                                                activeChannels[chid] = false;
                                                            sr.readNext();
                                                            break;
                                                        }
                                                        else
                                                        {
                                                            sr.readNext();
                                                        }
                                                    }
                                                }
                                                if(sr.name() == "linecolor")
                                                {
                                                    while(!sr.atEnd())
                                                    {
                                                        if(sr.isEndElement())
                                                        {
                                                            sr.readNext();
                                                            break;
                                                        }
                                                        if(sr.isStartElement())
                                                        {
                                                            plot_colors[chid] = sr.readElementText();
                                                            sr.readNext();
                                                            break;
                                                        }
                                                        else
                                                        {
                                                            sr.readNext();
                                                        }
                                                    }
                                                }
                                                sr.readNext();
                                            }
                                            else
                                            {
                                                sr.readNext();
                                            }
                                        }
                                    }
                                    else
                                        sr.readNext();
                                }
                                else
                                    sr.readNext();
                            }
                        }
                        sr.readNext();
                    }
                }
                sr.readNext();
            }
            else
                sr.readNext();
        }
        file.close();
        if(sr.hasError())
        {
            qDebug() << "Error: " << sr.errorString();
        }
    }
    this->move(x,y);
    this->resize(w,h);
    if(oldScale)
    {
        top_value = floor(top_value/39);
        bot_value = floor(bot_value/39);
    }

    getPlotSettings(oldScale, radInteger, QColor(plot_background), activeChannels, &cursors_parametres[0], plot_colors);
}

void MainWindow::WriteFileSettings()
{      
    QFile file("./plugins/data/settings.xml");
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QXmlStreamWriter sw(&file);
        sw.setAutoFormatting(true);
        sw.writeStartDocument();
        sw.writeStartElement("Settings");
        sw.writeStartElement("MainForm");
        sw.writeStartElement("geometry");
        sw.writeTextElement("x", QString::number(this->x()));
        sw.writeTextElement("y", QString::number(this->y()));
        sw.writeTextElement("width", QString::number(this->width()));
        sw.writeTextElement("height", QString::number(this->height()));
        sw.writeEndElement();
        sw.writeStartElement("teststeps");
        sw.writeEndElement();
        sw.writeStartElement("optics");
        sw.writeEndElement();
        sw.writeEndElement();
        sw.writeStartElement("PlotDialog");
        sw.writeTextElement("oldscale", QString::number(oldScale));
        sw.writeTextElement("radinteger", QString::number(radInteger));
        sw.writeTextElement("background", plot_background);
        sw.writeStartElement("cursors");
        sw.writeStartElement("top");
        sw.writeTextElement("enabled", QString::number(cursors_parametres[0]));
        sw.writeEndElement();
        sw.writeStartElement("mid");
        sw.writeTextElement("enabled", QString::number(cursors_parametres[1]));
        sw.writeEndElement();
        sw.writeStartElement("bot");
        sw.writeTextElement("enabled", QString::number(cursors_parametres[2]));
        sw.writeEndElement();
        sw.writeEndElement();
        sw.writeStartElement("channels");
        for(int i=0; i<activeChannels.size(); i++)
        {
            sw.writeStartElement("channel");
            sw.writeAttribute("id", QString::number(i));
            sw.writeTextElement("enabled", QString::number(activeChannels[i]));
            sw.writeTextElement("linecolor", plot_colors[i]);
            sw.writeEndElement();
        }
        sw.writeEndElement();
        sw.writeEndElement();
        sw.writeEndElement();
        sw.writeEndDocument();
        file.close();
    }
}

void MainWindow::ReadTermSettings()
{
    QStringList cyclelist;
    QFile file("./plugins/data/thermcycle.xml");
    if(file.open(QIODevice::ReadOnly))
    {
        QXmlStreamReader sr(&file);
        while(!sr.atEnd())
        {
            if(sr.name() == "thermcycle")
            {
                while(!sr.atEnd())
                {
                    if(sr.isEndElement())
                    {
                        sr.readNext();
                        break;
                    }
                    if(sr.name() == "levels")
                    {
                        while(!sr.atEnd())
                        {
                            if(sr.isEndElement())
                            {
                                sr.readNext();
                                break;
                            }
                            if(sr.isStartElement())
                            {
                                if(sr.name() == "level")
                                {
                                    while(!sr.atEnd())
                                    {
                                        if(sr.isEndElement())
                                        {
                                            sr.readNext();
                                            break;
                                        }
                                        if(sr.isStartElement())
                                        {
                                            if(sr.name() == "value")
                                            {
                                                while(!sr.atEnd())
                                                {
                                                    if(sr.isEndElement())
                                                    {
                                                        sr.readNext();
                                                        break;
                                                    }
                                                    if(sr.isStartElement())
                                                    {
                                                        cyclelist.append(sr.readElementText());
                                                        sr.readNext();
                                                        break;
                                                    }
                                                    else
                                                    {
                                                        sr.readNext();
                                                    }
                                                }
                                            }
                                            sr.readNext();
                                        }
                                        else
                                        {
                                            sr.readNext();
                                        }
                                    }
                                }
                                else
                                    sr.readNext();
                            }
                            else
                                sr.readNext();
                        }
                    }
                    if(sr.name() == "cycle")
                    {
                        while(!sr.atEnd())
                        {
                            if(sr.isEndElement())
                            {
                                sr.readNext();
                                break;
                            }
                            if(sr.isStartElement())
                            {
                                if(sr.name() == "count")
                                {
                                    while(!sr.atEnd())
                                    {
                                        if(sr.isEndElement())
                                        {
                                            sr.readNext();
                                            break;
                                        }
                                        if(sr.isStartElement())
                                        {
                                            ui->cyc_spinBox->setValue(sr.readElementText().toInt());
                                            sr.readNext();
                                            break;
                                        }
                                        else
                                        {
                                            sr.readNext();
                                        }
                                    }
                                }
                                else
                                    sr.readNext();
                            }
                            else
                                sr.readNext();
                        }
                    }
                    else
                        sr.readNext();
                }
            }
            else
                sr.readNext();
        }
        file.close();
        if(sr.hasError())
        {
            qDebug() << "Error: " << sr.errorString();
        }
    }

    for(int i=0; i<cyclelist.size(); i++)
    {
        QDoubleSpinBox *tempcell = new QDoubleSpinBox(ui->tableWidget);
        tempcell->setAlignment(Qt::AlignCenter);
        tempcell->setDecimals(1);
        tempcell->setSingleStep(0.1);
        tempcell->setMinimum(0.0);
        tempcell->setMaximum(99.9);
        tempcell->setValue(cyclelist[i].split(";")[0].toFloat());
        QLabel *l1 = new QLabel(ui->tableWidget);
        l1->setText("°C");
        l1->setAlignment(Qt::AlignCenter);
        QTimeEdit *timecell = new QTimeEdit(ui->tableWidget);
        timecell->setAlignment(Qt::AlignCenter);
        timecell->setDisplayFormat("mm:ss");
        int sec = cyclelist[i].split(";")[1].toInt();
        timecell->setTime(QTime(0,sec/60,sec-(sec/60)*60));
        QLabel *l2 = new QLabel(ui->tableWidget);
        l2->setText("min:sec");
        l2->setAlignment(Qt::AlignCenter);

        int rows;
        rows = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(rows);
        ui->tableWidget->setCellWidget(rows, 0, tempcell);
        ui->tableWidget->setCellWidget(rows, 1, l1);
        ui->tableWidget->setCellWidget(rows, 2, timecell);
        ui->tableWidget->setCellWidget(rows, 3, l2);
        ui->tableWidget->setRowHeight(rows, 33);
    }
}

void MainWindow::WriteTermSettings()
{
    QStringList cyclelist;
    for(int i=0; i<ui->tableWidget->rowCount(); i++)
    {
        QDoubleSpinBox *temp = qobject_cast<QDoubleSpinBox*>(ui->tableWidget->cellWidget(i,0));
        if(temp != NULL)
        {
            QTimeEdit *time = qobject_cast<QTimeEdit*>(ui->tableWidget->cellWidget(i,2));
            if(time != NULL)
            {
                cyclelist.append(QString::number(temp->value(), 'f', 1)+";"+QString::number(time->time().minute()*60+time->time().second()));
            }
        }
    }

    QFile file("./plugins/data/thermcycle.xml");
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QXmlStreamWriter sw(&file);
        sw.setAutoFormatting(true);
        sw.writeStartDocument();
        sw.writeStartElement("thermcycle");
        sw.writeStartElement("levels");
        for(int i=0; i<cyclelist.size(); i++)
        {
            sw.writeStartElement("level");
            sw.writeAttribute("id", QString::number(i));
            sw.writeTextElement("value", cyclelist[i]);
            sw.writeEndElement();
        }
        sw.writeEndElement();
        sw.writeStartElement("cycle");
        sw.writeTextElement("count", QString::number(ui->cyc_spinBox->value()));
        sw.writeEndElement();
        sw.writeEndElement();
        sw.writeEndDocument();
        file.close();
    }
}

void MainWindow::PCTimeNow()
{
    QTime Ctime = QTime::currentTime();
    QDate CDate = QDate::currentDate();
    QString datetime;
    ui->dateTimeEdit->hide();
    ui->dateTimeEdit->setTime(Ctime);
    ui->dateTimeEdit->setDate(CDate);
    datetime =ui->dateTimeEdit->text();
    ui->datetimeLabel->setText(datetime);
    ui->statusBar->addPermanentWidget(ui->datetimeLabel, 0);
}
void MainWindow::CheckConnection()
{   
    if(DTconnected)
    {
        QString outs;
        mutex.lock();
        if(!USBCy_RW("XGS", outs, usb, Temp_uC))
        {
            DTconnected = false;
        }
        mutex.unlock();
        if(outs.split(" ")[0] == "0")
        {
            ui->pushButtonStart->setEnabled(true);
            ui->pushButtonStop->setEnabled(false);
            ui->label_W->setText(" ");
            ui->tableWidget->setEnabled(true);
            ui->pushButton_Add->setEnabled(true);
            ui->pushButton_Remove->setEnabled(true);
            ui->cyc_spinBox->setEnabled(true);
            ui->statusNowLabel->setText("Connected");
            ui->actionOpen_chart->setEnabled(false);
        }
        if(outs.split(" ")[0] == "1")
        {
            ui->pushButtonStart->setEnabled(false);
            ui->pushButtonStop->setEnabled(true);
            ui->label_W->setText(" ");
            ui->tableWidget->setEnabled(false);
            ui->pushButton_Add->setEnabled(false);
            ui->pushButton_Remove->setEnabled(false);
            ui->cyc_spinBox->setEnabled(false);
            ui->statusNowLabel->setText("Working");
            ui->actionOpen_chart->setEnabled(false);
        }
        if(outs.split(" ")[0] == "4")
        {
            ui->pushButtonStart->setEnabled(false);
            ui->pushButtonStop->setEnabled(true);
            ui->label_W->setText("Warming up!");
            ui->tableWidget->setEnabled(false);
            ui->pushButton_Add->setEnabled(false);
            ui->pushButton_Remove->setEnabled(false);
            ui->cyc_spinBox->setEnabled(false);
            ui->statusNowLabel->setText("Warming up");
            ui->actionOpen_chart->setEnabled(false);
        }
    }
    else
    {
        ui->actionOpen_chart->setEnabled(true);
    }
}

void MainWindow::ReadFromDevice() // Чтение данных с устройства
{
    QEventLoop loop;
    ReadDataThread *t = new ReadDataThread(&mutex);
    QObject::connect(t, SIGNAL(finished()), &loop, SLOT(quit()));
    QObject::connect(t, SIGNAL(SendData(QStringList,QStringList,QStringList,QStringList, QStringList, QString, QString))
                     ,SLOT(GetData(QStringList,QStringList,QStringList,QStringList, QStringList, QString, QString)));
    QObject::connect(this, SIGNAL(SendChannelsCount(int, CyDev*, CANChannels*, CANChannels*)), t, SLOT(GetChannelsCount(int, CyDev*, CANChannels*, CANChannels*)));
    emit SendChannelsCount(channels_count, usb, Optic_uC, Motor_uC);
    t->start();
    loop.exec();
}

void MainWindow::GetData(QStringList Calib, QStringList X, QStringList Y, QStringList Rotate, QStringList Exp, QString tube, QString date)
{
    if(!plotting)
    {
        if(DTSN != prevDT)
        {
            plottime = 0;
            on_actionClear_opened_chart_triggered();
        }
        PlotThread *p = new PlotThread(&mutex, newindex);
        QObject::connect(p, SIGNAL(finished()), p, SLOT(deleteLater()));
        QObject::connect(p, SIGNAL(sendData(QStringList, QStringList, QStringList, QStringList)),
                         SLOT(GetPlotData(QStringList, QStringList, QStringList,QStringList)));
        QObject::connect(p, SIGNAL(lostConnection()), this, SLOT(DTConnectionLost()));
        QObject::connect(this, SIGNAL(SendTime(double)), p, SLOT(GetTime(double)));
        QObject::connect(this, SIGNAL(SendStop()), p, SLOT(GetStop()));
        p->start();
        if(!globaltimeison)
        {
            globaltimeison = true;
            globaltime->start();
        }
        plotting = true;
    }
}

void MainWindow::ChangeLightColor(int c)
{
    fadc3_list[c]->clear();
    fadc2_list[c]->clear();
    fadc0_list[c]->clear();
    QPalette palette;
    palette.setColor(QPalette::Base, channel_color[c]);
    fadc3_list[c]->setPalette(palette);
    fadc2_list[c]->setPalette(palette);
    fadc0_list[c]->setPalette(palette);
}

void MainWindow::GetMeasured(int c, QStringList fadc_list)
{
    QPalette whitepalette;
    whitepalette.setColor(QPalette::Base, Qt::white);
    fadc3_list[c]->setPalette(whitepalette);
    fadc3_list[c]->setText(fadc_list[0]);
    fadc2_list[c]->setPalette(whitepalette);
    fadc2_list[c]->setText(QString::number(fadc_list[1].toInt()*2));
    fadc0_list[c]->setPalette(whitepalette);
    fadc0_list[c]->setText(fadc_list[2]);
}

void MainWindow::SetPlot()
{
    ui->plotwidget->xAxis->setLabel("seconds");
    ui->plotwidget->yAxis->setRange(0, 120);
    ui->plotwidget->yAxis->setLabel("°C");
    ui->plotwidget->setBackground(QColor(Qt::gray));

    ui->plotwidget->yAxis2->setVisible(true);
    ui->plotwidget->yAxis2->setRange(0, 306);

    ui->plotwidget->xAxis->setRange(0, 300);

    QPen p;
    p.setColor(QColor(Qt::red));
    p.setWidth(1);
    ui->plotwidget->addGraph();
    ui->plotwidget->graph(0)->setPen(p);
    ui->plotwidget->graph(0)->setAntialiasedFill(false);
    ui->plotwidget->graph(0)->setLineStyle(QCPGraph::lsLine);

    ui->plotwidget->addGraph();
    p.setColor(QColor(Qt::black));
    ui->plotwidget->graph(1)->setPen(p);
    ui->plotwidget->graph(1)->setAntialiasedFill(false);
    ui->plotwidget->graph(1)->setLineStyle(QCPGraph::lsLine);

    ui->plotwidget->addGraph();
    p.setColor(QColor(Qt::yellow));
    ui->plotwidget->graph(2)->setPen(p);
    ui->plotwidget->graph(2)->setAntialiasedFill(false);
    ui->plotwidget->graph(2)->setLineStyle(QCPGraph::lsLine);

    ui->plotwidget->addGraph();
    p.setColor(QColor(Qt::cyan));
    ui->plotwidget->graph(3)->setPen(p);
    ui->plotwidget->graph(3)->setAntialiasedFill(false);
    ui->plotwidget->graph(3)->setLineStyle(QCPGraph::lsLine);

    ui->plotwidget->addGraph();
    p.setColor(QColor(Qt::blue));
    ui->plotwidget->graph(4)->setPen(p);
    ui->plotwidget->graph(4)->setAntialiasedFill(false);
    ui->plotwidget->graph(4)->setLineStyle(QCPGraph::lsLine);

    ui->plotwidget->addGraph();
    p.setColor(QColor(Qt::magenta));
    ui->plotwidget->graph(5)->setPen(p);
    ui->plotwidget->graph(5)->setAntialiasedFill(false);
    ui->plotwidget->graph(5)->setLineStyle(QCPGraph::lsLine);

    ui->plotwidget->addGraph(); // Заданная температура
    p.setColor(QColor(Qt::white));
    ui->plotwidget->graph(6)->setPen(p);
    ui->plotwidget->graph(6)->setAntialiasedFill(false);
    ui->plotwidget->graph(6)->setLineStyle(QCPGraph::lsLine);

    ui->plotwidget->addGraph();
    p.setColor(QColor(Qt::magenta));
    ui->plotwidget->graph(7)->setPen(p);
    ui->plotwidget->graph(7)->setAntialiasedFill(false);
    ui->plotwidget->graph(7)->setLineStyle(QCPGraph::lsLine);

    ui->plotwidget->addGraph();
    p.setColor(QColor(Qt::blue));
    ui->plotwidget->graph(8)->setPen(p);
    ui->plotwidget->graph(8)->setAntialiasedFill(false);
    ui->plotwidget->graph(8)->setLineStyle(QCPGraph::lsLine);

    ui->plotwidget->addGraph();
    p.setColor(QColor(Qt::cyan));
    ui->plotwidget->graph(9)->setPen(p);
    ui->plotwidget->graph(9)->setAntialiasedFill(false);
    ui->plotwidget->graph(9)->setLineStyle(QCPGraph::lsLine);

    ui->plotwidget->addGraph();
    p.setColor(QColor(Qt::yellow));
    ui->plotwidget->graph(10)->setPen(p);
    ui->plotwidget->graph(10)->setAntialiasedFill(false);
    ui->plotwidget->graph(10)->setLineStyle(QCPGraph::lsLine);

    ui->plotwidget->addGraph();
    p.setColor(QColor(Qt::black));
    ui->plotwidget->graph(11)->setPen(p);
    ui->plotwidget->graph(11)->setAntialiasedFill(false);
    ui->plotwidget->graph(11)->setLineStyle(QCPGraph::lsLine);

    ui->plotwidget->addGraph();
    p.setColor(QColor(Qt::red));
    ui->plotwidget->graph(12)->setPen(p);
    ui->plotwidget->graph(12)->setAntialiasedFill(false);
    ui->plotwidget->graph(12)->setLineStyle(QCPGraph::lsLine);

    ui->plotwidget->addGraph(); //температура радиатора
    p.setColor(QColor("#006600"));
    ui->plotwidget->graph(13)->setPen(p);
    ui->plotwidget->graph(13)->setAntialiasedFill(false);
    ui->plotwidget->graph(13)->setLineStyle(QCPGraph::lsLine);

    ui->plotwidget->addGraph(); //температура крышки
    p.setColor(QColor("#ff4500"));
    ui->plotwidget->graph(14)->setPen(p);
    ui->plotwidget->graph(14)->setAntialiasedFill(false);
    ui->plotwidget->graph(14)->setLineStyle(QCPGraph::lsLine);

    ui->plotwidget->addGraph(); //дельта 1 канала
    p.setColor(QColor(Qt::red));
    ui->plotwidget->graph(15)->setPen(p);
    ui->plotwidget->graph(15)->setAntialiasedFill(false);
    ui->plotwidget->graph(15)->setLineStyle(QCPGraph::lsLine);

    ui->plotwidget->addGraph(); //дельта 2 канала
    p.setColor(QColor(Qt::black));
    ui->plotwidget->graph(16)->setPen(p);
    ui->plotwidget->graph(16)->setAntialiasedFill(false);
    ui->plotwidget->graph(16)->setLineStyle(QCPGraph::lsLine);

    ui->plotwidget->addGraph(); //дельта 3 канала
    p.setColor(QColor(Qt::yellow));
    ui->plotwidget->graph(17)->setPen(p);
    ui->plotwidget->graph(17)->setAntialiasedFill(false);
    ui->plotwidget->graph(17)->setLineStyle(QCPGraph::lsLine);

    ui->plotwidget->addGraph(); //дельта 4 канала
    p.setColor(QColor(Qt::cyan));
    ui->plotwidget->graph(18)->setPen(p);
    ui->plotwidget->graph(18)->setAntialiasedFill(false);
    ui->plotwidget->graph(18)->setLineStyle(QCPGraph::lsLine);

    ui->plotwidget->addGraph(); //дельта 5 канала
    p.setColor(QColor(Qt::blue));
    ui->plotwidget->graph(19)->setPen(p);
    ui->plotwidget->graph(19)->setAntialiasedFill(false);
    ui->plotwidget->graph(19)->setLineStyle(QCPGraph::lsLine);

    ui->plotwidget->addGraph(); //дельта 6 канала
    p.setColor(QColor(Qt::magenta));
    ui->plotwidget->graph(20)->setPen(p);
    ui->plotwidget->graph(20)->setAntialiasedFill(false);
    ui->plotwidget->graph(20)->setLineStyle(QCPGraph::lsLine);

    ui->plotwidget->addGraph(); //FADC 0
    p.setColor(QColor("#2424ff"));
    ui->plotwidget->graph(21)->setPen(p);
    ui->plotwidget->graph(21)->setAntialiasedFill(false);
    ui->plotwidget->graph(21)->setLineStyle(QCPGraph::lsLine);

    ui->plotwidget->addGraph(); //FADC 1
    p.setColor(QColor("#48ff48"));
    ui->plotwidget->graph(22)->setPen(p);
    ui->plotwidget->graph(22)->setAntialiasedFill(false);
    ui->plotwidget->graph(22)->setLineStyle(QCPGraph::lsLine);

    ui->plotwidget->addGraph(); //FADC 2
    p.setColor(QColor("#ffc312"));
    ui->plotwidget->graph(23)->setPen(p);
    ui->plotwidget->graph(23)->setAntialiasedFill(false);
    ui->plotwidget->graph(23)->setLineStyle(QCPGraph::lsLine);

    ui->plotwidget->addGraph(); //FADC 3
    p.setColor(QColor("#9f00c5"));
    ui->plotwidget->graph(24)->setPen(p);
    ui->plotwidget->graph(24)->setAntialiasedFill(false);
    ui->plotwidget->graph(24)->setLineStyle(QCPGraph::lsLine);

    ui->plotwidget->addLayer("cursortext", 0, QCustomPlot::limAbove);
}

void MainWindow::setTable()
{
    ui->tableWidget->horizontalHeader()->hide();
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->tableWidget->setColumnWidth(0, 60);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    ui->tableWidget->setColumnWidth(2, 60);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);
    ui->tableWidget->setColumnWidth(3, 60);
}

void MainWindow::on_pushButton_Add_clicked()
{
    ui->tableWidget->scrollToTop();

    QDoubleSpinBox *tempcell = new QDoubleSpinBox(ui->tableWidget);
    tempcell->setAlignment(Qt::AlignCenter);
    tempcell->setDecimals(1);
    tempcell->setSingleStep(0.1);
    tempcell->setMinimum(0.0);
    tempcell->setMaximum(99.9);
    tempcell->setValue(50.0);
    QLabel *l1 = new QLabel(ui->tableWidget);
    l1->setText("°C");
    l1->setAlignment(Qt::AlignCenter);
    QTimeEdit *timecell = new QTimeEdit(ui->tableWidget);
    timecell->setAlignment(Qt::AlignCenter);
    timecell->setDisplayFormat("mm:ss");
    timecell->setTime(QTime(0,0,5));
    QLabel *l2 = new QLabel(ui->tableWidget);
    l2->setText("min:sec");
    l2->setAlignment(Qt::AlignCenter);

    int rows;
    rows = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(rows);
    ui->tableWidget->setCellWidget(rows, 0, tempcell);
    ui->tableWidget->setCellWidget(rows, 1, l1);
    ui->tableWidget->setCellWidget(rows, 2, timecell);
    ui->tableWidget->setCellWidget(rows, 3, l2);
    ui->tableWidget->setRowHeight(rows, 33);
}

void MainWindow::on_pushButton_Remove_clicked()
{
    if(ui->tableWidget->rowCount() > 1)
        ui->tableWidget->removeRow(ui->tableWidget->rowCount()-1);
}

void MainWindow::GetPlotData(QStringList temp, QStringList cur, QStringList xtp, QStringList xr)
{
    plottime = globaltime->elapsed()/1000.0;
    bool alarm = false;

    for(int i=0; i<6; i++)
    {
        ui->plotwidget->graph(i)->addData(QString::number(plottime, 'f', 2).toDouble(),
                                          QString::number(temp[i].toDouble()/100.0, 'f', 2).toDouble());

        if(temp[i].toInt() > 10400)
            alarm = true;
    }
    if(alarm)
        ui->plotwidget->graph(6)->addData(QString::number(plottime, 'f', 2).toDouble(),
                                          QString::number(xr[0].toDouble()/100.0, 'f', 2).toDouble());

    for(int i=0; i<6; i++)
    {
        ui->plotwidget->graph(15+i)->addData(QString::number(plottime, 'f', 2).toDouble(),
                                             QString::number((xr[0].toDouble()-temp[i].toDouble())/100.0+50.0, 'f', 2).toDouble());
    }

    for(int i=0; i<6; i++)
    {

        ui->plotwidget->graph(12-i)->addData(QString::number(plottime, 'f', 2).toDouble(),
                                             QString::number(cur[i].toDouble()/2.55, 'f', 2).toDouble());
        if(cur[i].toInt() < cycle_minimum[i])
            cycle_minimum[i] = cur[i].toInt();

    }

    if(radInteger)
        ui->plotwidget->graph(13)->addData(QString::number(plottime, 'f', 2).toDouble(),
                                           xtp[0].toInt()/100);
    else
        ui->plotwidget->graph(13)->addData(QString::number(plottime, 'f', 2).toDouble(),
                                           QString::number(xtp[0].toDouble()/100.0, 'f', 2).toDouble());

    ui->plotwidget->graph(14)->addData(QString::number(plottime, 'f', 2).toDouble(),
                                       QString::number(xtp[1].toDouble()/100.0, 'f', 2).toDouble());


    if(!isScaled)
    {
        ui->plotwidget->xAxis->setRange(0, globaltime->elapsed()/1000.0);
    }
    ui->plotwidget->replot();


    if(!ui->pushButtonStart->isEnabled())
    {
        QStringList cyclelist;
        for(int i=0; i<ui->tableWidget->rowCount(); i++)
        {
            QDoubleSpinBox *temp = qobject_cast<QDoubleSpinBox*>(ui->tableWidget->cellWidget(i,0));
            if(temp != NULL)
            {
                QTimeEdit *time = qobject_cast<QTimeEdit*>(ui->tableWidget->cellWidget(i,2));
                if(time != NULL)
                {
                    cyclelist.append(QString::number(temp->value(), 'f', 1)+";"+QString::number(time->time().minute()*60+time->time().second()));
                }
            }
        }

        double average_temp = 0.0;
        for(int i=0; i<6; i++)
        {
            average_temp+=temp[i].toDouble()/100.0;
        }
        average_temp/=6.0;
        if(average_temp > cyclelist[ui->tableWidget->rowCount()-1].split(";")[0].toDouble()+2.0)
            newcycleState = 1;
        if(average_temp < cyclelist[ui->tableWidget->rowCount()-1].split(";")[0].toDouble()+2.0)
            newcycleState = 0;
        if(cycleState == 0) // начало нового цикла
        {
            if(newcycleState == 1)
            {
                if( cycleNumber < ui->cyc_spinBox->value())
                {
                    for(int i=0; i<6; i++)
                        qDebug() << QString::number(cycle_minimum[i]);
                    int min = 255, max = 0;
                    for(int i=0; i<6; i++)
                    {
                        if(cycle_minimum[i] > max)
                            max = cycle_minimum[i];
                        if(cycle_minimum[i] < min)
                            min = cycle_minimum[i];
                    }
                    cycleparams << QString::number(cycleNumber)+" "+QString::number(cycleP/cyclePMeasures, 'f', 2)
                                   +" "+QString::number(cycleM/cycleMMeasures, 'f', 2)+" "+QString::number(max-min);
                }
                cycleP = 0;
                cycleM = 0;
                cyclePMeasures = 0;
                cycleMMeasures = 0;
                for(int i=0; i<6; i++)
                    cycle_minimum[i] = 255;
                cycleNumber++;
                QCPItemLine *l = new QCPItemLine(ui->plotwidget);
                ui->plotwidget->addItem(l);
                l->setPen(QPen(Qt::blue, 1, Qt::DashLine, Qt::SquareCap, Qt::BevelJoin));
                l->start->setCoords(plottime, 0);
                l->end->setCoords(plottime, 200);

                QCPItemText *tnumber = new QCPItemText(ui->plotwidget);
                ui->plotwidget->addItem(tnumber);
                tnumber->position->setCoords(plottime+20, 13);
                tnumber->setText(QString::number(cycleNumber));
                tnumber->setFont(QFont(font().family(), 12));
            }
        }
        if(cycleNumber < ui->cyc_spinBox->value())
        {
            for(int i=0; i<6; i++)
            {
                if(cur[i].toInt()>127)
                {
                    efficiency_plus += cur[i].toInt()-127;
                    cycleP += cur[i].toInt()-127;
                    cyclePMeasures++;
                    efficiency_plusm++;
                }
                if(cur[i].toInt()<128)
                {
                    efficiency_minus += 128-cur[i].toInt();
                    cycleM += 128-cur[i].toInt();
                    cycleMMeasures++;
                    efficiency_minusm++;
                }
            }
        }
        cycleState = newcycleState;
    }
}

void MainWindow::DTConnectionLost()
{
    qDebug() << "lostConnection";
    plotting = false;
    DTconnected = false;
    this->setWindowTitle("DTCharts - Not Connected");
    prevDT = DTSN;
    ui->device_label->setText(" ");
}

void MainWindow::mousePress(QMouseEvent *e) // Масштабирование графика
{
    if(e->button() == Qt::LeftButton)
    {
        p1 = e->pos();
        origin = e->pos();
        if(!rubberBand)
        {
            rubberBand = new QRubberBand(QRubberBand::Rectangle, ui->plotwidget);
        }
        rubberBand->setGeometry(QRect(origin, QSize()));
        rubberBand->show();
    }
    if(e->button() == Qt::RightButton)
    {
        QPoint mp;
        mp.setX(e->globalX()-3.5);
        mp.setY(e->globalY()-50);
        QToolTip::showText(mp,
                           QString::number(ui->plotwidget->yAxis->pixelToCoord(e->pos().y()), 'f', 2)+
                           " °C"+" : "+QString::number(floor(ui->plotwidget->yAxis2->pixelToCoord(e->pos().y())+0.5))+
                           " c.u.\r\n" + QString::number(ui->plotwidget->xAxis->pixelToCoord(e->pos().x()), 'f', 1)+" sec", this, rect() );
        QWidget::mousePressEvent(e);
    }
    if(e->button() == Qt::MidButton)
    {
        if(rubberBand)
        {
            if(rubberBand->isHidden())
            {
                p1 = e->pos();
                m3pressed = true;
            }
        }
    }
    ui->plotwidget->replot();

}

void MainWindow::mouseRelease(QMouseEvent *e)
{    

    if(rubberBand)
    {
        if (e->button() == Qt::LeftButton)
        { p2 = e->pos();
            double w = (p2.x()-p1.x());
            double h = (p2.y()-p1.y());


            xAxisShift = 0.0;
            if(w>10 && h>10)
            {
                isScaled = true;
                double deltax = 0.0;
                double deltay = 0.0;
                deltax = w/ui->plotwidget->axisRect()->width();
                deltay = h/ui->plotwidget->axisRect()->height();
                ui->plotwidget->yAxis->setRange(ui->plotwidget->yAxis->pixelToCoord(p1.y()),
                                                ui->plotwidget->yAxis->pixelToCoord(p2.y()));
                ui->plotwidget->xAxis->setRange(ui->plotwidget->xAxis->pixelToCoord(p1.x()),
                                                ui->plotwidget->xAxis->pixelToCoord(p2.x()));
                if(oldScale)
                    ui->plotwidget->yAxis2->setRange(ui->plotwidget->yAxis->range().lower*9945/100,
                                                     ui->plotwidget->yAxis->range().upper*9945/100);
                else
                    ui->plotwidget->yAxis2->setRange(ui->plotwidget->yAxis->range().lower*255/100,
                                                     ui->plotwidget->yAxis->range().upper*255/100);

            }
            if(w<-10 && (h<-10 || h>10))
            {
                ui->plotwidget->xAxis->setRange(0, globaltime->elapsed()/1000.0);
                ui->plotwidget->yAxis->setRange(0, 120);

                if(oldScale)
                    ui->plotwidget->yAxis2->setRange(0, 11934);
                else
                    ui->plotwidget->yAxis2->setRange(0, 306);

                if(!DTconnected){
                    ui->plotwidget->xAxis->rescale();
                }
                ui->plotwidget->replot();
                isScaled = false;
            }
            rubberBand->hide();
        }
    }
    if(e->button() == Qt::MidButton)
    {
        m3pressed = false;
    }

    ui->plotwidget->replot();
}

void MainWindow::mouseMove(QMouseEvent *e)
{
    if(rubberBand)
        rubberBand->setGeometry(QRect(origin, e->pos()).normalized());

    if(isScaled)
    {
        if(m3pressed)
        {
            pc = e->pos();
            ui->plotwidget->xAxis->moveRange(ui->plotwidget->xAxis->pixelToCoord(p1.x())-
                                             ui->plotwidget->xAxis->pixelToCoord(pc.x()));
            ui->plotwidget->yAxis->moveRange(ui->plotwidget->yAxis->pixelToCoord(p1.y())-
                                             ui->plotwidget->yAxis->pixelToCoord(pc.y()));
            ui->plotwidget->yAxis2->moveRange(ui->plotwidget->yAxis2->pixelToCoord(p1.y())-
                                              ui->plotwidget->yAxis2->pixelToCoord(pc.y()));
            ui->plotwidget->replot();
            p1 = e->pos();
        }
    }

    ui->plotwidget->replot();
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    WriteFileSettings();
    WriteTermSettings();
    e->accept();
}

void MainWindow::getPlotSettings(bool OldScale, bool RadInteger, QColor currentColor, QByteArray aC, int* cursors, QStringList linecolors)
{
    activeChannels = aC;
    radInteger = RadInteger;
    for(int i=0; i<4; i++)
    {
        cursors_parametres[i] = cursors[i];
    }
    if(OldScale)
    {
        if(!isScaled)
            ui->plotwidget->yAxis2->setRange(0, 11934);
        else
        {
            if(!oldScale)
            {
                ui->plotwidget->yAxis2->setRange(ui->plotwidget->yAxis2->range().lower*39,
                                                 ui->plotwidget->yAxis2->range().upper*39);
            }
        }
        oldScale = true;
    }
    else
    {
        if(!isScaled)
            ui->plotwidget->yAxis2->setRange(0, 306);
        else
        {
            if(oldScale)
            {
                ui->plotwidget->yAxis2->setRange(ui->plotwidget->yAxis2->range().lower/39,
                                                 ui->plotwidget->yAxis2->range().upper/39);
            }
        }
        oldScale = false;
    }

    plot_background = currentColor.name();
    ui->plotwidget->setBackground(QColor(plot_background));

    for(int i=0; i<plot_colors.size(); i++)
        plot_colors[i] = linecolors[i];
    QPen p;
    for(int i=0; i<6; i++)//температура
    {
        ui->plotwidget->graph(i)->setVisible(activeChannels[i]);
        p.setColor(QColor(plot_colors[i]));
        ui->plotwidget->graph(i)->setPen(p);
    }
    ui->plotwidget->graph(13)->setVisible(activeChannels[6]);//радиатор
    p.setColor(QColor(plot_colors[6]));
    ui->plotwidget->graph(13)->setPen(p);
    ui->plotwidget->graph(14)->setVisible(activeChannels[7]);//крышка
    p.setColor(QColor(plot_colors[7]));
    ui->plotwidget->graph(14)->setPen(p);
    ui->plotwidget->graph(6)->setVisible(activeChannels[8]);//заданная
    p.setColor(QColor(plot_colors[8]));
    ui->plotwidget->graph(6)->setPen(p);
    for(int i=0; i<6; i++)//ток
        ui->plotwidget->graph(12-i)->setVisible(activeChannels[9+i]);
    if(activeChannels[15])//дельта
    {
        for(int i=0; i<6; i++)
        {
            ui->plotwidget->graph(20-i)->setVisible(activeChannels[i]);
            p.setColor(QColor(plot_colors[i]));
            ui->plotwidget->graph(20-i)->setPen(p);
        }
    }
    else
    {
        for(int i=0; i<6; i++)
            ui->plotwidget->graph(20-i)->setVisible(false);
    }
    for(int i=0; i<4; i++)//FADC2
    {
        ui->plotwidget->graph(21+i)->setVisible(activeChannels[16+i]);
        p.setColor(QColor(plot_colors[16+i]));
        ui->plotwidget->graph(21+i)->setPen(p);
    }
    ui->plotwidget->replot();
}

bool bisChecked = false;

void MainWindow::on_checkBox_stateChanged(int arg)
{
    if(arg == 2)
    {
        EsThread *es = new EsThread(&mutex, newindex);
        QObject::connect(es, SIGNAL(finished()), es, SLOT(deleteLater()));
        QObject::connect(es, SIGNAL(SendEs(QStringList)), SLOT(GetEs(QStringList)));
        QObject::connect(this, SIGNAL(SendStopEs()), es, SLOT(StopEs()));
        es->start();
    }
    if(arg == 0)
    {
        emit SendStopEs();
    }
}

void MainWindow::GetEs(QStringList es)
{
    qDebug() << es;
}

void MainWindow::on_actionClear_opened_chart_triggered()
{
    for(int i=0; i<6; i++)
    {
        ui->plotwidget->graph(i)->clearData();
        ui->plotwidget->graph(12-i)->clearData();
        ui->plotwidget->graph(15+i)->clearData();
    }
    ui->plotwidget->graph(13)->clearData();
    ui->plotwidget->graph(14)->clearData();
    ui->plotwidget->graph(6)->clearData();
    for(int i=0; i<4; i++)
        ui->plotwidget->graph(21+i)->clearData();
    globaltime->start();
}

void MainWindow::on_actionOpen_chart_triggered()
{
    QString fileopen = QFileDialog::getOpenFileName(this, tr("Open chart"),
                                                    QDir::currentPath(),
                                                    tr("Text Files(*.txt);;CSV Files(*.csv)"));

    if(fileopen != "")
    {
        QFile file(fileopen);
        if(!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(this, tr("Error!"), tr("Can not open file."));
            return;
        }

        if(file.fileName().right(3) == "csv")
        {
            QTextStream in(&file);
            QString s;
            QStringList sensorslist, datalist;
            s = in.readAll();
            datalist = s.split("\r\n");
            if(!datalist.isEmpty())
                datalist.pop_front();
            if(!datalist.isEmpty())
                datalist.pop_back();

            on_actionClear_opened_chart_triggered();
            this->setWindowTitle("DTCharts - "+file.fileName());
            for(int i=0; i<datalist.size(); i++)
            {
                sensorslist = datalist[i].split(";");

                if(sensorslist[0] != NULL)
                {
                    if(sensorslist[1] != NULL)
                        ui->plotwidget->graph(0)->addData(sensorslist[0].replace(",", ".").toDouble(), sensorslist[1].replace(",", ".").toDouble());//температура по каналам
                    if(sensorslist[2] != NULL)
                        ui->plotwidget->graph(1)->addData(sensorslist[0].replace(",", ".").toDouble(), sensorslist[2].replace(",", ".").toDouble());
                    if(sensorslist[3] != NULL)
                        ui->plotwidget->graph(2)->addData(sensorslist[0].replace(",", ".").toDouble(), sensorslist[3].replace(",", ".").toDouble());
                    if(sensorslist[4] != NULL)
                        ui->plotwidget->graph(3)->addData(sensorslist[0].replace(",", ".").toDouble(), sensorslist[4].replace(",", ".").toDouble());
                    if(sensorslist[5] != NULL)
                        ui->plotwidget->graph(4)->addData(sensorslist[0].replace(",", ".").toDouble(), sensorslist[5].replace(",", ".").toDouble());
                    if(sensorslist[6] != NULL)
                        ui->plotwidget->graph(5)->addData(sensorslist[0].replace(",", ".").toDouble(), sensorslist[6].replace(",", ".").toDouble());

                    if(sensorslist[7] != NULL)
                        ui->plotwidget->graph(12)->addData(sensorslist[0].replace(",", ".").toDouble(), sensorslist[7].replace(",", ".").toDouble());//токи по каналам
                    if(sensorslist[8] != NULL)
                        ui->plotwidget->graph(11)->addData(sensorslist[0].replace(",", ".").toDouble(), sensorslist[8].replace(",", ".").toDouble());
                    if(sensorslist[9] != NULL)
                        ui->plotwidget->graph(10)->addData(sensorslist[0].replace(",", ".").toDouble(), sensorslist[9].replace(",", ".").toDouble());
                    if(sensorslist[10] != NULL)
                        ui->plotwidget->graph(9)->addData(sensorslist[0].replace(",", ".").toDouble(), sensorslist[10].replace(",", ".").toDouble());
                    if(sensorslist[11] != NULL)
                        ui->plotwidget->graph(8)->addData(sensorslist[0].replace(",", ".").toDouble(), sensorslist[11].replace(",", ".").toDouble());
                    if(sensorslist[12] != NULL)
                        ui->plotwidget->graph(7)->addData(sensorslist[0].replace(",", ".").toDouble(), sensorslist[12].replace(",", ".").toDouble());

                    if(sensorslist[13] != NULL)
                        ui->plotwidget->graph(13)->addData(sensorslist[0].replace(",", ".").toDouble(), sensorslist[13].replace(",", ".").toDouble());//температура радиатора

                    if(sensorslist[14] != NULL)
                        ui->plotwidget->graph(14)->addData(sensorslist[0].replace(",", ".").toDouble(), sensorslist[14].replace(",", ".").toDouble());//температура крышки

                    if(sensorslist[15] != NULL)
                        ui->plotwidget->graph(6)->addData(sensorslist[0].replace(",", ".").toDouble(), sensorslist[15].replace(",", ".").toDouble());//температура заданная

                    if(sensorslist[16] != NULL)
                        ui->plotwidget->graph(15)->addData(sensorslist[0].replace(",", ".").toDouble(), sensorslist[16].replace(",", ".").toDouble());//дельта по каналам
                    if(sensorslist[17] != NULL)
                        ui->plotwidget->graph(16)->addData(sensorslist[0].replace(",", ".").toDouble(), sensorslist[17].replace(",", ".").toDouble());
                    if(sensorslist[18] != NULL)
                        ui->plotwidget->graph(17)->addData(sensorslist[0].replace(",", ".").toDouble(), sensorslist[18].replace(",", ".").toDouble());
                    if(sensorslist[19] != NULL)
                        ui->plotwidget->graph(18)->addData(sensorslist[0].replace(",", ".").toDouble(), sensorslist[19].replace(",", ".").toDouble());
                    if(sensorslist[20] != NULL)
                        ui->plotwidget->graph(19)->addData(sensorslist[0].replace(",", ".").toDouble(), sensorslist[20].replace(",", ".").toDouble());
                    if(sensorslist[21] != NULL)
                        ui->plotwidget->graph(20)->addData(sensorslist[0].replace(",", ".").toDouble(), sensorslist[21].replace(",", ".").toDouble());
                }
            }
            ui->plotwidget->xAxis->rescale();
            ui->plotwidget->replot();
            file.close();
        }
        else if(file.fileName().right(3) == "txt")
        {

            QTextStream in(&file);
            QString s;
            QStringList sensorslist, datalist, vklist;
            s = in.readAll();
            sensorslist = s.split("|");
            on_actionClear_opened_chart_triggered();
            if(sensorslist[0] == "$ProtocolPlot")
            {
                sensorslist.pop_front();
                sensorslist.pop_back();
                qDebug() << sensorslist.size();
                qDebug() << sensorslist;
                if(sensorslist.size() == 21)
                {
                    on_actionClear_opened_chart_triggered();
                    this->setWindowTitle("DTCharts - "+file.fileName());
                    plottime = 0;
                    for(int j=0; j<6; j++)
                    {
                        datalist = sensorslist[j].split(";");
                        datalist.pop_back();
                        for(int i=0; i<datalist.size(); i++)
                        {
                            vklist = datalist[i].split(",");
                            ui->plotwidget->graph(j)->addData(vklist[0].toDouble(), vklist[1].toDouble());
                        }
                        datalist = sensorslist[6+j].split(";");
                        datalist.pop_back();
                        for(int i=0; i<datalist.size(); i++)
                        {
                            vklist = datalist[i].split(",");
                            ui->plotwidget->graph(12-j)->addData(vklist[0].toDouble(), vklist[1].toDouble());
                        }
                    }
                    datalist = sensorslist[12].split(";"); // радиатор
                    datalist.pop_back();
                    for(int i=0; i<datalist.size(); i++)
                    {
                        vklist = datalist[i].split(",");
                        ui->plotwidget->graph(13)->addData(vklist[0].toDouble(), vklist[1].toDouble());
                    }
                    datalist = sensorslist[13].split(";"); // крышка
                    datalist.pop_back();
                    for(int i=0; i<datalist.size(); i++)
                    {
                        vklist = datalist[i].split(",");
                        ui->plotwidget->graph(14)->addData(vklist[0].toDouble(), vklist[1].toDouble());
                    }

                    datalist = sensorslist[14].split(";"); // заданная
                    datalist.pop_back();
                    for(int i=0; i<datalist.size(); i++)
                    {
                        vklist = datalist[i].split(",");
                        ui->plotwidget->graph(6)->addData(vklist[0].toDouble(), vklist[1].toDouble());
                    }
                    for(int j=0; j<6; j++)
                    {
                        datalist = sensorslist[15+j].split(";");
                        datalist.pop_back();
                        for(int i=0; i<datalist.size(); i++)
                        {
                            vklist = datalist[i].split(",");
                            ui->plotwidget->graph(15+j)->addData(vklist[0].toDouble(), vklist[1].toDouble());
                        }
                    }
                    ui->plotwidget->rescaleAxes();
                    ui->plotwidget->replot();
                }
                else if(sensorslist.size() == 15)
                {
                    on_actionClear_opened_chart_triggered();
                    this->setWindowTitle("DTCharts - "+file.fileName());
                    plottime = 0;
                    for(int j=0; j<6; j++)
                    {
                        datalist = sensorslist[j].split(";");
                        datalist.pop_back();
                        for(int i=0; i<datalist.size(); i++)
                        {
                            vklist = datalist[i].split(",");
                            ui->plotwidget->graph(j)->addData(vklist[0].toDouble(), vklist[1].toDouble());
                        }
                        datalist = sensorslist[6+j].split(";");
                        datalist.pop_back();
                        for(int i=0; i<datalist.size(); i++)
                        {
                            vklist = datalist[i].split(",");
                            ui->plotwidget->graph(12-j)->addData(vklist[0].toDouble(), vklist[1].toDouble());
                        }
                    }
                    datalist = sensorslist[12].split(";"); // радиатор
                    datalist.pop_back();
                    for(int i=0; i<datalist.size(); i++)
                    {
                        vklist = datalist[i].split(",");
                        ui->plotwidget->graph(13)->addData(vklist[0].toDouble(), vklist[1].toDouble());
                    }
                    datalist = sensorslist[13].split(";"); // крышка
                    datalist.pop_back();
                    for(int i=0; i<datalist.size(); i++)
                    {
                        vklist = datalist[i].split(",");
                        ui->plotwidget->graph(14)->addData(vklist[0].toDouble(), vklist[1].toDouble());
                    }

                    ui->plotwidget->rescaleAxes();
                    ui->plotwidget->replot();
                }
                else
                    QMessageBox::critical(this, tr("Error!"), tr("File is damaged!"));

                file.close();
            }
            else
                QMessageBox::critical(this, tr("Error!"), tr("Invalid file format!"));
        }
    }
}

void MainWindow::on_actionSave_chart_triggered()
{
    QDate date = QDate::currentDate();
    QString filesave = QFileDialog::getSaveFileName(this, tr("Save chart"),
                                                    "Chart "+DTSN+"-"+date.toString("dd.MM.yyyy")+".txt",
                                                    tr("Plot Files(*.txt *.csv);;Text File(*.txt);;CSV File(*.csv)"));
    if(filesave != "")
    {
        QFile file(filesave);
        if(!file.open(QIODevice::WriteOnly))
        {
            QMessageBox::critical(this, tr("Error"), tr("Could not save file"));
            return;
        }
        else
        {
            QTextStream out(&file);
            QStringList slist;
            if(filesave.right(3) == "csv")
            {
                QList<QCPData> d;
                slist.append("время;1 t°C;2 t°C;3 t°C;4 t°C;5 t°C;6 t°C;");
                slist.append("1 Ток;2 Ток;3 Ток;4 Ток;5 Ток;6 Ток;радиатор t°C;крышка t°C;заданная t°C;");
                slist.append("1 Дельта;2 Дельта;3 Дельта;4 Дельта;5 Дельта;6 Дельта;");
                slist.append("\r\n");
                d = ui->plotwidget->graph(0)->data()->values();
                int rows = d.size();
                for(int i=0; i<rows; i++)
                {
                    for(int j=0; j<6; j++)
                    {
                        d = ui->plotwidget->graph(j)->data()->values(); // температура по каналам
                        slist.append(QString::number((d.value(i).key), 'f', 2).replace(".", ",")+";");
                        slist.append(QString::number((d.value(i).value), 'f', 2).replace(".", ",")+";");
                    }
                    for(int j=0; j<6; j++)
                    {
                        d = ui->plotwidget->graph(12-j)->data()->values(); // токи по каналам
                        slist.append(QString::number((d.value(i).value), 'f', 2).replace(".", ",")+";");
                    }
                    d = ui->plotwidget->graph(13)->data()->values(); // температура радиатора
                    slist.append(QString::number((d.value(i).value), 'f', 2).replace(".", ",")+";");

                    d = ui->plotwidget->graph(14)->data()->values(); // температура крышки
                    slist.append(QString::number((d.value(i).value), 'f', 2).replace(".", ",")+";");

                    d = ui->plotwidget->graph(6)->data()->values(); // температура заданная
                    slist.append(QString::number((d.value(i).value), 'f', 2).replace(".", ",")+";");

                    for(int j=0; j<6; j++)
                    {
                        d = ui->plotwidget->graph(15+j)->data()->values(); // дельта по каналам
                        slist.append(QString::number((d.value(i).value), 'f', 2).replace(".", ",")+";");
                    }
                    slist.append("\r\n");
                }
            }
            else if(filesave.right(3) == "txt")
            {
                QList<QCPData> d;
                slist.append("$ProtocolPlot|");
                for(int i=0; i<6; i++)
                {
                    d = ui->plotwidget->graph(i)->data()->values(); // температура по каналам
                    for(int i=0; i<d.size(); i++)
                    {
                        slist.append(QString::number((d.value(i).key), 'f', 2)+",");
                        slist.append(QString::number((d.value(i).value), 'f', 2)+";");
                    }
                    slist.append("|");
                }
                for(int i=0; i<6; i++) // токи по каналам
                {
                    d = ui->plotwidget->graph(12-i)->data()->values();
                    for(int i=0; i<d.size(); i++)
                    {
                        slist.append(QString::number((d.value(i).key), 'f', 2)+",");
                        slist.append(QString::number((d.value(i).value), 'f', 2)+";");
                    }
                    slist.append("|");
                }
                d = ui->plotwidget->graph(13)->data()->values(); // температура радитора
                for(int i=0; i<d.size(); i++)
                {
                    slist.append(QString::number((d.value(i).key), 'f', 2)+",");
                    slist.append(QString::number((d.value(i).value), 'f', 2)+";");
                }
                slist.append("|");
                d = ui->plotwidget->graph(14)->data()->values();// температура крышки
                for(int i=0; i<d.size(); i++)
                {
                    slist.append(QString::number((d.value(i).key), 'f', 2)+",");
                    slist.append(QString::number((d.value(i).value), 'f', 2)+";");
                }
                slist.append("|");
                d = ui->plotwidget->graph(6)->data()->values(); // температура заданная
                for(int i=0; i<d.size(); i++)
                {
                    slist.append(QString::number((d.value(i).key), 'f', 2)+",");
                    slist.append(QString::number((d.value(i).value), 'f', 2)+";");
                }
                slist.append("|");
                for(int i=0; i<6; i++)// дельта по каналам
                {
                    d = ui->plotwidget->graph(15+i)->data()->values();
                    for(int i=0; i<d.size(); i++)
                    {
                        slist.append(QString::number((d.value(i).key), 'f', 2)+",");
                        slist.append(QString::number((d.value(i).value), 'f', 2)+";");
                    }
                    slist.append("|");
                }
            }
            out << slist.join("");
            out.flush();
            file.close();
        }
    }
}

void MainWindow::on_actionChart_settings_triggered()
{
    p->show();
    if(!settingdialodshown) emit SendFileSettings(oldScale, radInteger, plot_background, activeChannels, &cursors_parametres[0], plot_colors);
    settingdialodshown = true;
}



void MainWindow::on_pushButtonEnter_clicked()
{
    if(DTconnected){
        QString enteredCMD;
        if(ui->lineEditCommand->text() != NULL){
            enteredCMD = ui->lineEditCommand->text();
            CMDPush *push = new CMDPush(enteredCMD, newindex, &mutex);
            QObject::connect(push, SIGNAL(finished()), push, SLOT(deleteLater()));
            QObject::connect(push, SIGNAL(SendCMD(QString)), this, SLOT(GetCMD(QString)));
            push->start();
        }
    }
    else
        QMessageBox::critical(this,"Warning", "Device is not connected.");
}

void MainWindow::GetCMD(QString outs)
{
    ui->lineEditCommandRead->setText(outs);
}

void MainWindow::ChangeGeometry()
{
    if(this->geometry().width() < 800)
    {
        ui->groupBox_3->hide();
        ui->groupBox_5->hide();
        ui->groupBox_2->hide();
    }
    if(this->geometry().width() >= 800)
    {
        ui->groupBox_3->show();
        ui->groupBox_5->show();
        ui->groupBox_2->show();
    }
}
