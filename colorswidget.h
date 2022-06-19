#ifndef COLORSWIDGET
#define COLORSWIDGET
#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QPointF>
#include <QList>


class ColorsWidget : public QWidget
{
    Q_OBJECT

public:
    ColorsWidget(QWidget *parent = 0);
    ~ColorsWidget();

protected:
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent *e);
    //void mouseReleaseEvent(QMouseEvent *e);

public slots:
    void SetCurrentColor(QString c);    

private:
    QList<QColor> colors;
    int currentcolor;

signals:
   void colorChanged(QColor c);
};

#endif // COLORSWIDGET

