#include "graphic.h"
#include "Mandelbrot.h"

#include <QGraphicsItem>
#include <QPainter>
#include <QPoint>
#include <QColor>


Graphic::Graphic(Mandelbrot *model){
    this->model = model;
    color_temp = ColorType[4];
    setBoundingRect(0,0, model->getWide()-2,model->getHeight()-2);
}
void Graphic::paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget){
    (void)(item);
    (void)(widget);

    QPoint point(0,0);
    QColor color( 0, 0, 0);
    int iter = 0;
    for(int i = 0;i<model->getWide();++i){
        for(int j = 0;j< model->getHeight();j++){
            iter = model->getIterationOfPixel(i,j);

            point.setX(i);
            point.setY(j);

            setColourForIteration(color, iter);
            painter->setPen(color);
            painter->drawPoint(point);
        }
    }
}

void Graphic::setColourForIteration(QColor &color, int iter){
    if(model->getIteration()== iter){
        color.setRed(0);
        color.setGreen(0);
        color.setBlue(0);
        return;
    }

    double ratio = (double)iter/(double)model->getIteration();

    int r = makeColorDifByRatio(ratio,color_temp[0]);
    int g = makeColorDifByRatio(ratio,color_temp[1]);
    int b = makeColorDifByRatio(ratio,color_temp[2]);

    color.setRed(r);
    color.setGreen(g);
    color.setBlue(b);
}

int Graphic::makeColorDifByRatio(double ratio,int diff){
    return (int)(ratio*(255-diff)+diff);
}

QRectF Graphic::boundingRect()const{
    return bRect;
}

void Graphic::setBoundingRect(int x1,int y1,int x2,int y2){
    bRect= QRect(x1,y1,x2,y2);
}

void Graphic::setcolor(int index){
    if(index >=0 && index < DEEP_COLOR){
        color_temp=ColorType[index];
        update();
    }
}
