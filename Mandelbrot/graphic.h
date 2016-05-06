#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPoint>
#include <QColor>


#include "Mandelbrot.h"

using namespace mandelbrot;
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
        Graphic(Mandelbrot *model){
            this->model = model;
            color_temp = ColorType[4];
            setBoundingRect(0,0, model->getWide()-2,model->getHeight()-2);
        }

        void paint(QPainter *painter,const QStyleOptionGraphicsItem *item,QWidget *widget){
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
        void setColourForIteration(QColor &color, int iter){
            if(model->getInteration()== iter){
                color.setRed(0);
                color.setGreen(0);
                color.setBlue(0);
                return;
            }

            double ratio = (double)iter/(double)model->getInteration();

            int r = makeColorDifByRatio(ratio,color_temp[0]);
            int g = makeColorDifByRatio(ratio,color_temp[1]);
            int b = makeColorDifByRatio(ratio,color_temp[2]);

            color.setRed(r);
            color.setGreen(g);
            color.setBlue(b);

        }

        int makeColorDifByRatio(double ratio,int diff){
            return (int)(ratio*(255-diff)+diff);
        }

        QRectF boundingRect()const{
            return bRect;
        }

        void setBoundingRect(int x1,int y1,int x2,int y2){
            bRect= QRect(x1,y1,x2,y2);
        }

        void setcolor(int index){
            if(index >=0 && index < DEEP_COLOR){
                color_temp=ColorType[index];
                update();
            }
        }
};
#endif // GRAPHIC_H
