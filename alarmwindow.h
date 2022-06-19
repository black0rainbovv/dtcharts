#ifndef ALARMWINDOW_H
#define ALARMWINDOW_H

#include <QDialog>
#include <QTimer>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QCloseEvent>
#include <QShowEvent>

namespace Ui {
class alarmwindow;
}

class alarmwindow : public QDialog
{
    Q_OBJECT

public:
    explicit alarmwindow(QWidget *parent = 0);
    ~alarmwindow();

private slots:
    void ChangeWindowState();

    void closeEvent(QCloseEvent *e);
    void showEvent(QShowEvent *e);

    void on_pushButton_clicked();

private:
    Ui::alarmwindow *ui;
    QTimer *state_timer;
    int windowstate;

    QMediaPlaylist *playlist;
    QMediaPlayer *player;
};

#endif // ALARMWINDOW_H
