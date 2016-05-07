#ifndef GRAPHICVIEW_H
#define GRAPHICVIEW_H

#include <QGraphicsScene>
#include <QGraphicsView>

#include "Mandelbrot.h"
#include "Graphic.h"

class GraphicView: public QGraphicsView{
    Q_OBJECT
private:

    QGraphicsScene* scene;
    Graphic* graph;

    Mandelbrot *model;
public:
    GraphicView(Mandelbrot *model, QWidget *parent = 0);
    ~GraphicView();
    void setSize(int width,int height);
};


#endif // GRAPHICVIEW_H
