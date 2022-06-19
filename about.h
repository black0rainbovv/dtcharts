#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>

#include "CypressUsb.h"
#include "CANChannels.h"
#include "Utility.h"

#include "qcustomplot.h"

namespace Ui {
class about;
}

class about : public QDialog
{
    Q_OBJECT

public:
    explicit about(QWidget *parent = 0);
    ~about();

private slots:
    void on_closeButton_clicked();
    void closeEvent(QCloseEvent *e);

private:
    Ui::about *ui;
    about *aboutform;
};

#endif // ABOUT_H
