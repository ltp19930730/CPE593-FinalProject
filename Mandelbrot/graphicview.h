#ifndef GRAPHICVIEW_H
#define GRAPHICVIEW_H

#include <QGraphicsScene>
#include <QGraphicsView>

#include "Mandelbrot.h"
#include "Graphic.h"

using namespace mandelbrot;

class GraphicView: public QGraphicsView{
    Q_OBJECT
private:

    QGraphicsScene* scene;
    Graphic* graph;

    Mandelbrot *model;
public:
    GraphicView(Mandelbrot *model, QWidget *parent = 0): QGraphicsView(parent) {
        this->model = model;
        graph = new Graphic(model);
        scene = new QGraphicsScene();

        scene->addItem(graph);

        setScene(scene);
    }
    ~GraphicView(){
        delete graph;
        delete scene;
    }
    void setSize(int width,int height){
        scene->setSceneRect(0,0,width-2,height-2);
        setGeometry(0,0,width,height);
    }

};


#endif // GRAPHICVIEW_H
