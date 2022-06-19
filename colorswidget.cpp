#include "colorswidget.h"

ColorsWidget::ColorsWidget(QWidget *parent):
    QWidget(parent)
{
    colors << QColor("#ffffff") << QColor("#dadada") << QColor("#a0a0a4")
           << QColor("#98af5b") << QColor("#8dbebe") << QColor("#d4a77a");
    currentcolor = -2;
}

ColorsWidget::~ColorsWidget()
{

}

void ColorsWidget::paintEvent(QPaintEvent *)
{
    int w = this->width();
//    int h = this->height();
    w -= 5*(colors.size()   );
    while(w%colors.size()!=0)
        w-=1;
    QPainter painter(this);

    for(int i=0; i<colors.size(); i++)
    {
        if(i == currentcolor)
            painter.setPen(QPen(QColor("#f37a00"), 1));
        else
            painter.setPen(QPen(QColor(Qt::gray), 1));
        if(i == currentcolor)
            painter.setBrush(QBrush(Qt::red));
        else
            painter.setBrush(QBrush(Qt::white));
        painter.drawRect(5*i+i*w/colors.size(),0,w/colors.size()+2, w/colors.size()+2);
        painter.setPen(QPen(QColor(Qt::gray), 1));
        painter.setBrush(QBrush(colors[i]));
        painter.drawRect(2+5*i+i*w/colors.size(),2+0,w/colors.size()-2, w/colors.size()-2);
    }
}

void ColorsWidget::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        int w = this->width();
        int h = this->height();
        QPointF pos = e->pos();
        for(int i=0; i<colors.size(); i++)
        {
            if((pos.x() > i*w/colors.size() && pos.x() < (i+1)*w/colors.size()) && (pos.y() > 0 && pos.y() < h-1))
            {
                emit colorChanged(colors[i]);
                currentcolor = i;
            }
        }
        this->repaint();
    }
}

void ColorsWidget::SetCurrentColor(QString c)
{
    for(int i=0; i<colors.size(); i++)
    {
        if(colors[i].name() == c)
        {
            currentcolor = i;
            emit colorChanged(colors[i]);
            this->repaint();
        }
    }
}
