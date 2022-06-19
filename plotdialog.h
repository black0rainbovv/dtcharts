#ifndef PLOTDIALOG_H
#define PLOTDIALOG_H

#include <QDialog>
#include <QMouseEvent>
#include <QDebug>
#include <QColorDialog>
#include <QWidget>
#include <QColorDialog>
#include <QColor>

#include "colorswidget.h"
#include "math.h"

namespace Ui {
class PlotDialog;
}

class PlotDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PlotDialog(QWidget *parent = 0);
    ~PlotDialog();

private slots:
    void on_pushButton_clicked();
    void changeAllTemp();
    void changeAllTok();
    void setColor(QColor);
    void closeEvent(QCloseEvent *e);
    void GetFileSettings(bool, bool, QString, QByteArray, int*, QStringList);


    void on_rad_checkBox_1_stateChanged(int arg1);

    void on_rad_checkBox_stateChanged(int arg1);

    void on_t1color_pushButton_clicked();

    void on_t2color_pushButton_clicked();

    void on_t3color_pushButton_clicked();

    void on_t4color_pushButton_clicked();

    void on_t5color_pushButton_clicked();

    void on_t6color_pushButton_clicked();

    void on_c1color_pushButton_clicked();

    void on_c2color_pushButton_clicked();

    void on_c3color_pushButton_clicked();

    void on_c4color_pushButton_clicked();

    void on_c5color_pushButton_clicked();

    void on_c6color_pushButton_clicked();

    void on_lidcolor_pushButton_clicked();

    void on_radcolor_pushButton_clicked();

    void on_setcolor_pushButton_clicked();

    void on_fadc0color_pushButton_clicked();

    void on_fadc1color_pushButton_clicked();

    void on_fadc2color_pushButton_clicked();

    void on_fadc3color_pushButton_clicked();

    void on_pushButton_2_clicked();

signals:
    void setPlotSettings(bool OldScale, bool, QColor currentColor, QByteArray activeChannels, int* cursors, QStringList);

private:
    Ui::PlotDialog *ui;
    QStringList plotcolors;
};

#endif // PLOTDIALOG_H
