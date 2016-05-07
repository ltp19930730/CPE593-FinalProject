#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPoint>
#include <QColor>


#include "Mandelbrot.h"

#define DEEP_COLOR 6

class Graphic : public QGraphicsItem {
private:
    int ColorType[DEEP_COLOR][3] = {
       {30, 0, 50}
      ,{60, 0, 0}
      ,{0, 60, 10}
      ,{45, 50, 0}
      ,{0, 0, 30}
      ,{75, 30, 0}
    };
        int *color_temp;
        QRect bRect;
        Mandelbrot *model;
public:
        Graphic(Mandelbrot *model);

        void paint(QPainter *painter,const QStyleOptionGraphicsItem *item,QWidget *widget);
        void setColourForIteration(QColor &color, int iter);
        int makeColorDifByRatio(double ratio,int diff);
        QRectF boundingRect()const;
        void setBoundingRect(int x1,int y1,int x2,int y2);
        void setcolor(int index);
};
#endif // GRAPHIC_H
