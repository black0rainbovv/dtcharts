#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>
#include <QThread>
#include <QTimer>
#include <QSplashScreen>
#include <QMovie>
#include <QtWidgets>
#include <QRubberBand>
#include <QPoint>
#include <QMutex>
#include <QXmlStreamReader>

#include <QGraphicsAnchorLayout>

#include <QAxBase>
#include <QAxObject>

#include <QTextDocumentFragment>

#include "CypressUsb.h"
#include "CANChannels.h"
#include "Utility.h"

#include "qcustomplot.h"
#include "termcycledialog.h"

#include "plotdialog.h"
#include"selectdeviceform.h"
#include "about.h"
#include"dtsettings.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    //void Diagnostic();
    void ReadFileSettings();
    void ReadTermSettings();
    void WriteFileSettings();
    void WriteTermSettings();
    void ReadFromDevice();
    void CheckConnection();
    void PCTimeNow();
    void setTable();
    void GetData(QStringList Calib, QStringList X, QStringList Y, QStringList Rotate, QStringList Exp, QString tube, QString date);
    void ChangeLightColor(int c);
    void GetMeasured(int, QStringList);
    void SetPlot();
    void GetPlotData(QStringList, QStringList, QStringList, QStringList);
    void mousePress(QMouseEvent *e);
    void mouseMove(QMouseEvent *e);
    void mouseRelease(QMouseEvent *e);
    void closeEvent(QCloseEvent *e);
    void getPlotSettings(bool OldScale, bool, QColor currentColor, QByteArray activeChannels, int* cursors, QStringList);
    void DTConnectionLost();
    void GetEs(QStringList);
    void setDevicenumber(QString DTSN, bool connection);
    void setIndex(int index);
    void GetCMD(QString);
    void ChangeGeometry();

    void on_checkBox_stateChanged(int arg1);

    void on_pushButton_Add_clicked();

    void on_pushButton_Remove_clicked();

    void on_actionClear_opened_chart_triggered();

    void on_actionOpen_chart_triggered();

    void on_actionSave_chart_triggered();

    void on_actionChart_settings_triggered();

    void on_actionAbout_triggered();

    void on_actionDT_setting_triggered();

    void on_pushButtonStart_clicked();

    void on_pushButtonStop_clicked();

    void on_pushButtonEnter_clicked();

    void on_actionConnect_device_2_clicked();

    void on_actionDisconnect_device_2_clicked();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


signals:
    void SendChannelsCount(int c, CyDev *u, CANChannels *o, CANChannels *m);
    void SendMeasureData(int c, CyDev *u, CANChannels *o, CANChannels *m, QStringList, int, int, QStringList);
    void SendFileSettings(bool os, bool, QString c, QByteArray ch, int *cur, QStringList);
    void SendTime(double);
    void SendStop();
    void SendTermCycleParams(QStringList);
    void SendStopEs();
    void writeNumberType(QString, QString);
    void UpdateTime();

private:
    Ui::MainWindow *ui;

    selectdeviceform *deviceForm;
    about *aboutform;
    dtsettings *dtsettingForm;
    CyDev *usb, *usb1;
    CANChannels *Optic_uC;
    CANChannels *Temp_uC;
    CANChannels *Motor_uC;
    CANChannels *Disp_uC;
    QString DTSN, TERMSN, TERMSN2;
    QString FVER_Temp;
    QString FVER_Optic;
    QString FVER_Motor;
    QString FVER_Display;
    QTimer *tconnect;
    bool DTconnected;
    QList<QLineEdit*> fadc3_list;
    QList<QLineEdit*> fadc2_list;
    QList<QLineEdit*> fadc0_list;
    QRubberBand *rubberBand;
    bool isScaled;
    bool m3pressed;
    QPoint origin;
    bool plotting;
    double plottime;
    QMutex mutex;
    PlotDialog *p;
    int cursors_parametres[4]; // [0],[1],[2] - top,mid,bot 1 - enabled 0 - disabled, [3]-привязка к токам 1-да 0-нет
    QString plot_background;
    QStringList plot_colors;
    QByteArray activeChannels; // [6] - радиатор [7] - крышка [8] - заданная
    bool oldScale;
    bool radInteger;
    bool settingdialodshown;
    QString prevDT;
    int prevValue;
    int initStatus; // операция с которой начинается термоциклирование 0-охлаждение 1-нагрев
    bool rb;
    qreal selectedPoint;
    int cycleNumber;
    int cycleState; // 1 - >50 0 - <50
    double cycleP;
    double cycleM;
    int cyclePMeasures;
    int cycleMMeasures;
    int newcycleState;
    double efficiency_plus;
    double efficiency_minus;
    int efficiency_plusm;
    int efficiency_minusm;
    QStringList cycleparams;
    termcycledialog *tcd;

    int cycle_minimum[6];
    QBitmap *Video;

    QTime *globaltime;
    bool globaltimeison;
    double xAxisShift;
    int newindex;



protected:
    bool eventFilter(QObject*, QEvent*);
};

class ReadDataThread : public QThread
{
    Q_OBJECT

public:
    ReadDataThread(QMutex* mu)
    {
        mutex = mu;
    }

protected:
    void run()
    {
        QString outs = "", tube, date;
        QStringList Calib, X, Y, Rotate, Exp;
        Calib << "0" << "0" << "0" << "0" << "0";
        X << "0" << "0" << "0" << "0" << "0";
        Y << "0" << "0" << "0" << "0" << "0";
        Rotate << "0" << "0" << "0" << "0" << "0";
        Exp << "0" << "0" << "0" << "0" << "0";
        if(usb->IsOpen())
        {
            for(int i=0; i<cc; i++)
            {
                mutex->lock();
                USBCy_RW("FCGET "+QString::number(i), outs, usb, Optic_uC);
                Calib[i] =  outs.split(" ")[2];
                mutex->unlock();
                QThread::msleep(60);

                mutex->lock();
                USBCy_RW("FCRXY "+QString::number(i), outs, usb, Optic_uC);
                X[i] = outs.split(" ")[0];
                Y[i] = outs.split(" ")[1];
                mutex->unlock();
                QThread::msleep(60);

                mutex->lock();
                USBCy_RW("FCEXP "+QString::number(i), outs, usb, Optic_uC);
                Exp[i] = outs.split(" ")[0];
                mutex->unlock();
                QThread::msleep(60);

                mutex->lock();
                USBCy_RW("GMP "+QString::number(i), outs, usb, Motor_uC);
                Rotate[i] = outs.split(" ")[1];
                mutex->unlock();
                QThread::msleep(60);
            }
            mutex->lock();
            USBCy_RW("RTUB", outs, usb, Motor_uC);
            tube = outs.split(" ")[0];
            mutex->unlock();
            mutex->lock();
            USBCy_RW("DATE", outs, usb, Optic_uC);
            date = outs;
            mutex->unlock();
            QThread::msleep(60);

            emit SendData(Calib, X, Y, Rotate, Exp, tube, date);
            emit SendSettings(Calib, Rotate, date);
        }
    }

public slots:
    void GetChannelsCount(int c, CyDev *u, CANChannels *o, CANChannels *m)
    {
        usb = u;
        cc = c;
        Optic_uC = o;
        Motor_uC = m;
    }

signals:
    void SendSettings(QStringList Calib, QStringList Rotate, QString date);
    void SendData(QStringList Calib, QStringList X, QStringList Y,
                  QStringList Rotate, QStringList Exp, QString tube, QString date);


private:
    int cc;
    CyDev *usb;
    CANChannels *Optic_uC;
    CANChannels *Motor_uC;
    QMutex *mutex;
};

class OpticMeasureThread : public QThread
{
    Q_OBJECT

public:
    OpticMeasureThread(QMutex* mu)
    {
        mutex = mu;
    }

protected:
    void run()
    {
        if(usb->IsOpen())
        {
            for(int j=0; j<cycles; j++)
            {
                QString outs;
                double fadc3, fadc2, fadc0;
                int m;
                for(int i=0; i<cc; i++)
                {
                    fadc3 = 0.0;
                    fadc2 = 0.0;
                    fadc0 = 0.0;
                    m = 0;
                    QTime *t = new QTime;
                    mutex->lock();
                    if(USBCy_RW("MP "+QString::number(i), outs, usb, Motor_uC))
                    {
                        mutex->unlock();
                        emit LightChanged(i);
                        QThread::msleep(60);
                        mutex->lock();
                        USBCy_RW("FLT "+flt_list[i], outs, usb, Optic_uC);
                        mutex->unlock();
                        //                    qDebug() << flt_list[i];
                        QThread::msleep(60);
                        mutex->lock();
                        USBCy_RW("FLED "+QString::number(i+1), outs, usb, Optic_uC);
                        mutex->unlock();
                        QThread::msleep(1000);
                        t->start();
                        while(t->elapsed() < exp_list[i].toDouble())
                        {
                            mutex->lock();
                            USBCy_RW("FADC 3", outs, usb, Optic_uC);
                            fadc3 += outs.split(" ")[0].toDouble();
                            mutex->unlock();
                            QThread::msleep(60);
                            mutex->lock();
                            USBCy_RW("FADC 2", outs, usb, Optic_uC);
                            fadc2 += outs.split(" ")[0].toDouble();
                            mutex->unlock();
                            QThread::msleep(60);
                            mutex->lock();
                            USBCy_RW("FADC 0", outs, usb, Optic_uC);
                            fadc0 += outs.split(" ")[0].toDouble();
                            mutex->unlock();
                            QThread::msleep(60);
                            m++;
                        }
                        mutex->lock();
                        USBCy_RW("FLED 0", outs, usb, Optic_uC);
                        mutex->unlock();
                        QThread::msleep(60);
                        fadc_list << QString::number(floor(fadc3/double(m)));
                        fadc_list << QString::number(floor(fadc2/double(m)));
                        fadc_list << QString::number(floor(fadc0/double(m)));
                        emit SendMeasured(i, fadc_list);
                        fadc_list.clear();
                        mutex->lock();
                    }
                    mutex->unlock();
                }
                if(j < cycles-1)
                    QThread::msleep(time_span*1000);
            }
            emit MeasuresEnded();
        }
    }

private slots:
    void GetMeasureData(int c, CyDev* u, CANChannels* o, CANChannels* m, QStringList l, int cyc, int t, QStringList expl)
    {
        cc = c;
        usb = u;
        Optic_uC = o;
        Motor_uC = m;
        flt_list = l;
        cycles = cyc;
        time_span = t;
        exp_list = expl;
    }

signals:
    void LightChanged(int c);
    void SendMeasured(int, QStringList);
    void MeasuresEnded();

private:
    int cc;
    CyDev *usb;
    CANChannels *Optic_uC;
    CANChannels *Motor_uC;
    QStringList fadc_list;
    QStringList flt_list;
    int cycles;
    int time_span;
    QStringList exp_list;
    QMutex* mutex;
};

class TestSplash : public QThread
{
    Q_OBJECT

protected:
    void run()
    {
        QThread::sleep(10);
    }

};

class PlotThread : public QThread
{
    Q_OBJECT

public:
    PlotThread(QMutex* mu, int ind)
    {
        mutex = mu;
        index = ind;
    }

protected:
    void run()
    {
        stopplot = false;
        QString outs;
        usb = new CyDev(NULL);
        usb->Open(index);
        QTime *t = new QTime;
        if(usb->IsOpen())
        {
            Optic_uC = new CANChannels(usb,2);
            Temp_uC = new CANChannels(usb,3);
            while(!stopplot)
            {
                connected = true;
                t->start();
                mutex->lock();

                if(USBCy_RW("XM", outs, usb, Temp_uC))
                    temp = outs.split(" ");
                else
                    connected = false;
                mutex->unlock();
                QThread::msleep(60);

                mutex->lock();
                if(USBCy_RW("XS", outs, usb, Temp_uC))
                    cur = outs.split(" ");
                else
                    connected = false;
                mutex->unlock();
                QThread::msleep(60);

                mutex->lock();
                if(USBCy_RW("XTP", outs, usb, Temp_uC))
                    xtp = outs.split(" ");
                else
                    connected = false;
                mutex->unlock();
                QThread::msleep(60);

                mutex->lock();
                if(USBCy_RW("XR", outs, usb, Temp_uC))
                    xr = outs.split(" ");
                else
                    connected = false;
                mutex->unlock();
                QThread::msleep(60);

                if(connected) emit sendData(temp, cur, xtp, xr);

                int timeleft = t->elapsed();
                if(timeleft < 200)
                    QThread::msleep(200-timeleft);

                temp.clear();
                cur.clear();
                xtp.clear();
                xr.clear();
                DTtime.clear();
            }
            emit lostConnection();
        }
    }

private slots:
    void GetTime(double t)
    {
        time = t;
    }

    void GetStop()
    {
        stopplot = true;
    }

signals:
    void sendData(QStringList, QStringList, QStringList, QStringList);
    void lostConnection();

private:
    QMutex* mutex;
    QString DTtime;
    QStringList temp, cur, xtp, xr;
    CyDev *usb;
    CANChannels *Temp_uC, *Optic_uC;
    volatile bool stopplot;
    double time;
    bool connected;
    int index;
};


class TubeMeasure : public QThread
{
    Q_OBJECT

public:
    TubeMeasure(QMutex* mu, int ind)
    {
        mutex = mu;
        index = ind;
    }

protected:
    void run()
    {
        QString outs;
        usb = new CyDev(NULL);
        usb->Open(index);
        if(usb->IsOpen())
        {
            QTime *t = new QTime;
            t->start();
            Motor_uC = new CANChannels(usb,4);
            mutex->lock();
            USBCy_RW("htube", outs, usb, Motor_uC);
            QThread::msleep(60);
            mutex->unlock();
            while(outs != "0")
            {
                mutex->lock();
                USBCy_RW("hsts", outs, usb, Motor_uC);
                mutex->unlock();
                QThread::msleep(500);
                if(t->elapsed() > 66000)
                {
                    emit sendDriverActionMsg("Выполненеи операции аварийно остановленно!");
                    break;
                }

            }
            mutex->lock();
            USBCy_RW("hdist", outs, usb, Motor_uC);
            QThread::msleep(60);
            mutex->unlock();

            emit sendTube(outs);
        }
    }

signals:
    void sendTube(QString);
    void sendDriverActionMsg(QString);

private:
    QMutex* mutex;
    CyDev *usb;
    CANChannels *Motor_uC;
    int index;
};

class CMDPush : public QThread
{
    Q_OBJECT

public:
    CMDPush(QString answer, int ind, QMutex* mu)
    {
        enteredCMD = answer;
        index = ind;
        mutex = mu;
    }
protected:
    void run()
    {
        QString outs;
        usb = new CyDev(NULL);
        usb->Open(index);
        if(usb->IsOpen())
        {
            Temp_uC = new CANChannels(usb, 3);
            mutex->lock();
            USBCy_RW(enteredCMD, outs, usb, Temp_uC);
            QThread::msleep(60);
            mutex->unlock();
            emit SendCMD(outs);
        }
    }
signals:
    void SendCMD(QString);

private:
    CyDev *usb;
    CANChannels *Temp_uC;
    QString enteredCMD;
    int index;
    QMutex* mutex;
};

class EsThread : public QThread
{
    Q_OBJECT

public:
    EsThread(QMutex* mu, int ind)
    {
        mutex = mu;
        index = ind;
    }

protected:
    void run()
    {
        stop = false;
        QString outs;
        usb = new CyDev(NULL);
        usb->Open(index);
        if(usb->IsOpen())
        {
            Motor_uC = new CANChannels(usb,4);
            while(!stop)
            {
                es.clear();
                mutex->lock();
                USBCy_RW("MBUSY", outs, usb, Motor_uC);
                QThread::msleep(60);
                mutex->unlock();
                if(outs == "0")
                {
                    mutex->lock();
                    USBCy_RW("MSEL 0", outs, usb, Motor_uC);
                    QThread::msleep(60);

                    USBCy_RW("ES", outs, usb, Motor_uC);
                    QThread::msleep(60);
                    es << outs;

                    USBCy_RW("MSEL 1", outs, usb, Motor_uC);
                    QThread::msleep(60);

                    USBCy_RW("ES", outs, usb, Motor_uC);
                    QThread::msleep(60);
                    es << outs;

                    USBCy_RW("MSEL 2", outs, usb, Motor_uC);
                    QThread::msleep(60);

                    USBCy_RW("ES", outs, usb, Motor_uC);
                    QThread::msleep(60);
                    es << outs;
                    mutex->unlock();
                    if(!stop)
                        emit SendEs(es);
                }
                QThread::msleep(1000);
            }
        }
    }

private slots:
    void StopEs()
    {
        stop = true;
    }

signals:
    void SendEs(QStringList);
    void on_checkBox_stateChanged(int);

private:
    QMutex* mutex;
    QStringList es;
    CyDev *usb;
    CANChannels *Motor_uC;
    volatile bool stop;
    int index;
};

#endif // MAINWINDOW_H
