#ifndef DTSETTINGS_H
#define DTSETTINGS_H

#include <QDialog>
#include<QMutex>

#include "CypressUsb.h"
#include "CANChannels.h"
#include "Utility.h"

namespace Ui {
class dtsettings;
}

class dtsettings : public QDialog
{
    Q_OBJECT

public:
    explicit dtsettings(QWidget *parent = 0);
    ~dtsettings();

private slots:
    void on_pushButton_sync_clicked();

    void on_pushButton_3_clicked();

    void Data(QStringList Calib, QStringList Rotate, QString date);

private:
    Ui::dtsettings *ui;
    dtsettings *dtsettingForm;
    QMutex mutex;
    CyDev *usb;
    CANChannels *Optic_uC;
    CANChannels *Temp_uC;
    CANChannels *Motor_uC;
    CANChannels *Disp_uC;

};



#endif // DTSETTINGS_H
