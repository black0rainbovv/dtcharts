#ifndef TERMCYCLEDIALOG_H
#define TERMCYCLEDIALOG_H

#include <QDialog>

namespace Ui {
class termcycledialog;
}

class termcycledialog : public QDialog
{
    Q_OBJECT

public:
    explicit termcycledialog(QWidget *parent = 0);
    ~termcycledialog();

private slots:
    void SetTable(QStringList params);
    void CopySelected();

private:
    Ui::termcycledialog *ui;
};

#endif // TERMCYCLEDIALOG_H
