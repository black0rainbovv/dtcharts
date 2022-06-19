#include "plotdialog.h"
#include "ui_plotdialog.h"

QPoint p;
QColor currentColor;

PlotDialog::PlotDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlotDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Settings");
    this->setAttribute(Qt::WA_ShowModal);
    ui->groupBox_4->hide();
    ui->groupBox_2->hide();
    ui->groupBox_6->hide();
    ui->groupBox_7->hide();
    ui->checkBox_Set->hide();
    ui->checkBox_Delta->hide();

    plotcolors.append("#ffffff");
    plotcolors.append("#ffffff");
    plotcolors.append("#ffffff");
    plotcolors.append("#ffffff");
    plotcolors.append("#ffffff");
    plotcolors.append("#ffffff");

    plotcolors.append("#ffffff");
    plotcolors.append("#ffffff");
    plotcolors.append("#ffffff");
    plotcolors.append("#ffffff");
    plotcolors.append("#ffffff");
    plotcolors.append("#ffffff");

    plotcolors.append("#ffffff");
    plotcolors.append("#ffffff");
    plotcolors.append("#ffffff");
    plotcolors.append("-");

    plotcolors.append("#ffffff");
    plotcolors.append("#ffffff");
    plotcolors.append("#ffffff");
    plotcolors.append("#ffffff");

    QObject::connect(ui->checkBox_AllTemp, SIGNAL(stateChanged(int)), this, SLOT(changeAllTemp()));
    QObject::connect(ui->checkBox_AllTok, SIGNAL(stateChanged(int)), this, SLOT(changeAllTok()));
    QObject::connect(ui->color_widget, SIGNAL(colorChanged(QColor)), this, SLOT(setColor(QColor)));
}

PlotDialog::~PlotDialog()
{
    delete ui;
}

void PlotDialog::GetFileSettings(bool os, bool ri, QString c, QByteArray ch, int* cur, QStringList colors)
{
    if(os)
        ui->checkBox_oldscale->setChecked(true);
    else
        ui->checkBox_oldscale->setChecked(false);

    if(ri)
    {
        ui->rad_checkBox->setChecked(true);
        ui->rad_checkBox_1->setChecked(false);
    }
    else
    {
        ui->rad_checkBox->setChecked(false);
        ui->rad_checkBox_1->setChecked(true);
    }

    ui->color_widget->SetCurrentColor(c);

    if(cur[0] == 1)
        ui->checkBox_topC->setChecked(true);
    if(cur[0] == 0)
        ui->checkBox_topC->setChecked(false);

    if(cur[1] == 1)
        ui->checkBox_midC->setChecked(true);
    if(cur[1] == 0)
        ui->checkBox_midC->setChecked(false);

    if(cur[2] == 1)
        ui->checkBox_botC->setChecked(true);
    if(cur[2] == 0)
        ui->checkBox_botC->setChecked(false);
    if(cur[3] == 1)
        ui->checkBox_Attach->setChecked(true);
    if(cur[3] == 0)
        ui->checkBox_Attach->setChecked(false);

    int t = 0, cu = 0;
    for(int i=0; i<ch.size(); i++)
    {
        if(i>=0 && i<6)
            if(ch[i])
                t++;
        if(i>=9 && i<15)
            if(ch[i])
                cu++;
    }
    if(t != 0)
        ui->checkBox_AllTemp->setChecked(true);
    else
        ui->checkBox_AllTemp->setChecked(false);

    if(cu != 0)
        ui->checkBox_AllTok->setChecked(true);
    else
        ui->checkBox_AllTok->setChecked(false);

    ui->checkBox_1Temp->setChecked(ch[0]);
    ui->checkBox_2Temp->setChecked(ch[1]);
    ui->checkBox_3Temp->setChecked(ch[2]);
    ui->checkBox_4Temp->setChecked(ch[3]);
    ui->checkBox_5Temp->setChecked(ch[4]);
    ui->checkBox_6Temp->setChecked(ch[5]);
    ui->checkBox_Rad->setChecked(ch[6]);
    ui->checkBox_Cap->setChecked(ch[7]);
    ui->checkBox_Set->setChecked(ch[8]);
    ui->checkBox_1Tok->setChecked(ch[9]);
    ui->checkBox_2Tok->setChecked(ch[10]);
    ui->checkBox_3Tok->setChecked(ch[11]);
    ui->checkBox_4Tok->setChecked(ch[12]);
    ui->checkBox_5Tok->setChecked(ch[13]);
    ui->checkBox_6Tok->setChecked(ch[14]);
    ui->checkBox_Delta->setChecked(ch[15]);
    ui->checkBox_FADC0->setChecked(ch[16]);
    ui->checkBox_FADC1->setChecked(ch[17]);
    ui->checkBox_FADC2->setChecked(ch[18]);
    ui->checkBox_FADC3->setChecked(ch[19]);

    for(int i=0; i<plotcolors.size(); i++)
    {
        plotcolors[i] = colors[i];
    }
    ui->t1color_pushButton->setStyleSheet("background-color: "+plotcolors[0]+";border-radius: 3px;");
    ui->t2color_pushButton->setStyleSheet("background-color: "+plotcolors[1]+";border-radius: 3px;");
    ui->t3color_pushButton->setStyleSheet("background-color: "+plotcolors[2]+";border-radius: 3px;");
    ui->t4color_pushButton->setStyleSheet("background-color: "+plotcolors[3]+";border-radius: 3px;");
    ui->t5color_pushButton->setStyleSheet("background-color: "+plotcolors[4]+";border-radius: 3px;");
    ui->t6color_pushButton->setStyleSheet("background-color: "+plotcolors[5]+";border-radius: 3px;");

    ui->radcolor_pushButton->setStyleSheet("background-color: "+plotcolors[6]+";border-radius: 3px;");
    ui->lidcolor_pushButton->setStyleSheet("background-color: "+plotcolors[7]+";border-radius: 3px;");

    ui->c1color_pushButton->setStyleSheet("background-color: "+plotcolors[9]+";border-radius: 3px;");
    ui->c2color_pushButton->setStyleSheet("background-color: "+plotcolors[10]+";border-radius: 3px;");
    ui->c3color_pushButton->setStyleSheet("background-color: "+plotcolors[11]+";border-radius: 3px;");
    ui->c4color_pushButton->setStyleSheet("background-color: "+plotcolors[12]+";border-radius: 3px;");
    ui->c5color_pushButton->setStyleSheet("background-color: "+plotcolors[13]+";border-radius: 3px;");
    ui->c6color_pushButton->setStyleSheet("background-color: "+plotcolors[14]+";border-radius: 3px;");

    ui->fadc0color_pushButton->setStyleSheet("background-color: "+plotcolors[16]+";border-radius: 3px;");
    ui->fadc1color_pushButton->setStyleSheet("background-color: "+plotcolors[17]+";border-radius: 3px;");
    ui->fadc2color_pushButton->setStyleSheet("background-color: "+plotcolors[18]+";border-radius: 3px;");
    ui->fadc3color_pushButton->setStyleSheet("background-color: "+plotcolors[19]+";border-radius: 3px;");
}

void PlotDialog::changeAllTemp()
{
    if(ui->checkBox_AllTemp->isChecked())
    {
        ui->checkBox_1Temp->setChecked(true);
        ui->checkBox_2Temp->setChecked(true);
        ui->checkBox_3Temp->setChecked(true);
        ui->checkBox_4Temp->setChecked(true);
        ui->checkBox_5Temp->setChecked(true);
        ui->checkBox_6Temp->setChecked(true);
    }
    else
    {
        ui->checkBox_1Temp->setChecked(false);
        ui->checkBox_2Temp->setChecked(false);
        ui->checkBox_3Temp->setChecked(false);
        ui->checkBox_4Temp->setChecked(false);
        ui->checkBox_5Temp->setChecked(false);
        ui->checkBox_6Temp->setChecked(false);
    }
}

void PlotDialog::changeAllTok()
{
    if(ui->checkBox_AllTok->isChecked())
    {
        ui->checkBox_1Tok->setChecked(true);
        ui->checkBox_2Tok->setChecked(true);
        ui->checkBox_3Tok->setChecked(true);
        ui->checkBox_4Tok->setChecked(true);
        ui->checkBox_5Tok->setChecked(true);
        ui->checkBox_6Tok->setChecked(true);
    }
    else
    {
        ui->checkBox_1Tok->setChecked(false);
        ui->checkBox_2Tok->setChecked(false);
        ui->checkBox_3Tok->setChecked(false);
        ui->checkBox_4Tok->setChecked(false);
        ui->checkBox_5Tok->setChecked(false);
        ui->checkBox_6Tok->setChecked(false);
    }
}

void PlotDialog::setColor(QColor c)
{
    currentColor = c;
}

void PlotDialog::closeEvent(QCloseEvent *e)
{
    //on_pushButton_clicked();
    //e->accept();
}

void PlotDialog::on_pushButton_clicked()
{
    QByteArray activeCh;
    activeCh[0] = ui->checkBox_1Temp->isChecked();
    activeCh[1] = ui->checkBox_2Temp->isChecked();
    activeCh[2] = ui->checkBox_3Temp->isChecked();
    activeCh[3] = ui->checkBox_4Temp->isChecked();
    activeCh[4] = ui->checkBox_5Temp->isChecked();
    activeCh[5] = ui->checkBox_6Temp->isChecked();
    activeCh[6] = ui->checkBox_Rad->isChecked();
    activeCh[7] = ui->checkBox_Cap->isChecked();
    activeCh[8] = ui->checkBox_Set->isChecked();
    activeCh[9] = ui->checkBox_1Tok->isChecked();
    activeCh[10] = ui->checkBox_2Tok->isChecked();
    activeCh[11] = ui->checkBox_3Tok->isChecked();
    activeCh[12] = ui->checkBox_4Tok->isChecked();
    activeCh[13] = ui->checkBox_5Tok->isChecked();
    activeCh[14] = ui->checkBox_6Tok->isChecked();
    activeCh[15] = ui->checkBox_Delta->isChecked();
    activeCh[16] = ui->checkBox_FADC0->isChecked();
    activeCh[17] = ui->checkBox_FADC1->isChecked();
    activeCh[18] = ui->checkBox_FADC2->isChecked();
    activeCh[19] = ui->checkBox_FADC3->isChecked();

    int cursors[5];
    if(ui->checkBox_topC->isChecked())
        cursors[0] = 1;
    else
        cursors[0] = 0;   

    if(ui->checkBox_midC->isChecked())
        cursors[1] = 1;
    else
        cursors[1] = 0;

    if(ui->checkBox_botC->isChecked())
        cursors[2] = 1;
    else
        cursors[2] = 0;
    if(ui->checkBox_Attach->isChecked())
        cursors[3] = 1;
    else
        cursors[3] = 0;

    emit setPlotSettings(ui->checkBox_oldscale->isChecked(), ui->rad_checkBox->isChecked(), currentColor, activeCh, &cursors[0], plotcolors);
    this->hide();
}


void PlotDialog::on_rad_checkBox_1_stateChanged(int c)
{
    if(c == 0)
    {
        ui->rad_checkBox->setChecked(true);
        ui->rad_checkBox_1->setChecked(false);
    }
    else if(c == 2)
    {
        ui->rad_checkBox->setChecked(false);
        ui->rad_checkBox_1->setChecked(true);
    }
}


void PlotDialog::on_rad_checkBox_stateChanged(int c)
{
    if(c == 2)
    {
        ui->rad_checkBox->setChecked(true);
        ui->rad_checkBox_1->setChecked(false);
    }
    else if(c == 0)
    {
        ui->rad_checkBox->setChecked(false);
        ui->rad_checkBox_1->setChecked(true);
    }
}

//температура
void PlotDialog::on_t1color_pushButton_clicked()
{
    QColor color = QColorDialog::getColor(QColor(plotcolors[0]), this, "Selecting the color of line 1 of the internal temperature sensor");
    if(color.isValid())
    {
        ui->t1color_pushButton->setStyleSheet("background-color: "+color.name()+";border-radius: 3px;");
        plotcolors[0] = color.name();
    }
    this->show();
}

void PlotDialog::on_t2color_pushButton_clicked()
{
    QColor color = QColorDialog::getColor(QColor(plotcolors[1]), this, "Selecting the color of line 2 of the internal temperature sensor");
    if(color.isValid())
    {
        ui->t2color_pushButton->setStyleSheet("background-color: "+color.name()+";border-radius: 3px;");
        plotcolors[1] = color.name();
    }
    this->show();
}

void PlotDialog::on_t3color_pushButton_clicked()
{
    QColor color = QColorDialog::getColor(QColor(plotcolors[2]), this, "Selecting the color of line 3 of the internal temperature sensor");
    if(color.isValid())
    {
        ui->t3color_pushButton->setStyleSheet("background-color: "+color.name()+";border-radius: 3px;");
        plotcolors[2] = color.name();
    }
    this->show();
}

void PlotDialog::on_t4color_pushButton_clicked()
{
    QColor color = QColorDialog::getColor(QColor(plotcolors[3]), this, "Selecting the color of line 4 of the internal temperature sensor");
    if(color.isValid())
    {
        ui->t4color_pushButton->setStyleSheet("background-color: "+color.name()+";border-radius: 3px;");
        plotcolors[3] = color.name();
    }
    this->show();
}

void PlotDialog::on_t5color_pushButton_clicked()
{
    QColor color = QColorDialog::getColor(QColor(plotcolors[4]), this, "Selecting the color of line 5 of the internal temperature sensor");
    if(color.isValid())
    {
        ui->t5color_pushButton->setStyleSheet("background-color: "+color.name()+";border-radius: 3px;");
        plotcolors[4] = color.name();
    }
    this->show();
}

void PlotDialog::on_t6color_pushButton_clicked()
{
    QColor color = QColorDialog::getColor(QColor(plotcolors[5]), this, "Selecting the color of line 6 of the internal temperature sensor");
    if(color.isValid())
    {
        ui->t6color_pushButton->setStyleSheet("background-color: "+color.name()+";border-radius: 3px;");
        plotcolors[5] = color.name();
    }
    this->show();
}

//ток
void PlotDialog::on_c1color_pushButton_clicked()
{
    QColor color = QColorDialog::getColor(plotcolors[9], this, "Selecting the color of line 1 peltier");
    if(color.isValid())
    {
        ui->c1color_pushButton->setStyleSheet("background-color: "+color.name()+";border-radius: 3px;");
        plotcolors[9] = color.name();
    }
    this->show();
}

void PlotDialog::on_c2color_pushButton_clicked()
{
    QColor color = QColorDialog::getColor(plotcolors[10], this, "Selecting the color of line 2 peltier");
    if(color.isValid())
    {
        ui->c2color_pushButton->setStyleSheet("background-color: "+color.name()+";border-radius: 3px;");
        plotcolors[10] = color.name();
    }
    this->show();
}

void PlotDialog::on_c3color_pushButton_clicked()
{
    QColor color = QColorDialog::getColor(plotcolors[11], this, "Selecting the color of line 3 peltier");
    if(color.isValid())
    {
        ui->c3color_pushButton->setStyleSheet("background-color: "+color.name()+";border-radius: 3px;");
        plotcolors[11] = color.name();
    }
    this->show();
}

void PlotDialog::on_c4color_pushButton_clicked()
{
    QColor color = QColorDialog::getColor(plotcolors[12], this, "Selecting the color of line 4 peltier");
    if(color.isValid())
    {
        ui->c4color_pushButton->setStyleSheet("background-color: "+color.name()+";border-radius: 3px;");
        plotcolors[12] = color.name();
    }
    this->show();
}

void PlotDialog::on_c5color_pushButton_clicked()
{
    QColor color = QColorDialog::getColor(plotcolors[13], this, "Selecting the color of line 5 peltier");
    if(color.isValid())
    {
        ui->c5color_pushButton->setStyleSheet("background-color: "+color.name()+";border-radius: 3px;");
        plotcolors[13] = color.name();
    }
    this->show();
}

void PlotDialog::on_c6color_pushButton_clicked()
{
    QColor color = QColorDialog::getColor(plotcolors[14], this, "Selecting the color of line 6 peltier");
    if(color.isValid())
    {
        ui->c6color_pushButton->setStyleSheet("background-color: "+color.name()+";border-radius: 3px;");
        plotcolors[14] = color.name();
    }
    this->show();
}


//Xtp
void PlotDialog::on_radcolor_pushButton_clicked()
{
    QColor color = QColorDialog::getColor(plotcolors[6], this, "Selecting the color of radiator line");
    if(color.isValid())
    {
        ui->radcolor_pushButton->setStyleSheet("background-color: "+color.name()+";border-radius: 3px;");
        plotcolors[6] = color.name();
    }
    this->show();
}

void PlotDialog::on_lidcolor_pushButton_clicked()
{
    QColor color = QColorDialog::getColor(plotcolors[7], this, "Selecting the color of lid line");
    if(color.isValid())
    {
        ui->lidcolor_pushButton->setStyleSheet("background-color: "+color.name()+";border-radius: 3px;");
        plotcolors[7] = color.name();
    }
    this->show();
}

void PlotDialog::on_setcolor_pushButton_clicked()
{/*
    QColor color = QColorDialog::getColor(plotcolors[8], this, "Выбор цвета линии заданной температуры");
    if(color.isValid())
    {
        ui->setcolor_pushButton->setStyleSheet("background-color: "+color.name()+";border-radius: 3px;");
        plotcolors[8] = color.name();
    }
    this->show();*/
}

//FADC
void PlotDialog::on_fadc0color_pushButton_clicked()
{
    /*QColor color = QColorDialog::getColor(plotcolors[16], this, "Выбор цвета линии тока FADC 0");
    if(color.isValid())
    {
        ui->fadc0color_pushButton->setStyleSheet("background-color: "+color.name()+";border-radius: 3px;");
        plotcolors[16] = color.name();
    }
    this->show()*/;
}

void PlotDialog::on_fadc1color_pushButton_clicked()
{
//    QColor color = QColorDialog::getColor(plotcolors[17], this, "Выбор цвета линии тока FADC 1");
//    if(color.isValid())
//    {
//        ui->fadc1color_pushButton->setStyleSheet("background-color: "+color.name()+";border-radius: 3px;");
//        plotcolors[17] = color.name();
//    }
//    this->show();
}

void PlotDialog::on_fadc2color_pushButton_clicked()
{
//    QColor color = QColorDialog::getColor(plotcolors[18], this, "Выбор цвета линии тока FADC 2");
//    if(color.isValid())
//    {
//        ui->fadc2color_pushButton->setStyleSheet("background-color: "+color.name()+";border-radius: 3px;");
//        plotcolors[18] = color.name();
//    }
//    this->show();
}

void PlotDialog::on_fadc3color_pushButton_clicked()
{
//    QColor color = QColorDialog::getColor(plotcolors[19], this, "Выбор цвета линии тока FADC 3");
//    if(color.isValid())
//    {
//        ui->fadc3color_pushButton->setStyleSheet("background-color: "+color.name()+";border-radius: 3px;");
//        plotcolors[19] = color.name();
//    }
//    this->show();
}

void PlotDialog::on_pushButton_2_clicked()
{
    this->close();
}
