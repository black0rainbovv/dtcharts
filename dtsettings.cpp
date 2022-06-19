#include "dtsettings.h"
#include "ui_dtsettings.h"
#include"mainwindow.h"

QList<QLineEdit*> Rotate_list;
QList<QLineEdit*> Max_list;

dtsettings::dtsettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dtsettings)
{
    ui->setupUi(this);
    this->setWindowTitle("DT Settings");
    this->setAttribute(Qt::WA_ShowModal);


    Rotate_list << ui->spinBox_r0 << ui->spinBox_r1 << ui->spinBox_r2
                << ui->spinBox_r3 << ui->spinBox_r4;
    Max_list << ui->maxlineEdit_0 << ui->lineEdit << ui->maxlineEdit_2
             << ui->maxlineEdit_3 << ui->maxlineEdit_4;

    ReadDataThread *t = new ReadDataThread(&mutex);
    qDebug()<<"try to connect signal/slot";
    QObject::connect(t,SIGNAL(SendSettings(QStringList ,QStringList, QString)),this,SLOT(Data(QStringList, QStringList, QString)));
    qDebug()<<"connect";
}

dtsettings::~dtsettings()
{
    delete ui;
}

void dtsettings::on_pushButton_sync_clicked()
{
    if(usb->IsOpen()){

    }
    else
        QMessageBox::critical(this,"Warning!", "Device is not connected");
}

void dtsettings::on_pushButton_3_clicked()
{
    this->close();
}


void dtsettings::Data(QStringList Calib, QStringList Rotate, QString date)
{
    qDebug()<<"getdata working";
    for(int i=0; i<5; i++)
        {
            Max_list[i]->setText(Calib[i]);
            Rotate_list[i]->setText(Rotate[i]);
        }
    ui->dateEdit->setDate(QDate::fromString(date, ("dd/MM/yy")));
}

