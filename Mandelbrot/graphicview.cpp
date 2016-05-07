#include "graphicview.h"
#include "Mandelbrot.h"
#include "Graphic.h"

#include <QGraphicsScene>
#include <QGraphicsView>

GraphicView::GraphicView(Mandelbrot *model, QWidget *parent): QGraphicsView(parent) {
    this->model = model;
    graph = new Graphic(model);
    scene = new QGraphicsScene();

    scene->addItem(graph);

    setScene(scene);
}

GraphicView::~GraphicView() {
    delete graph;
    delete scene;
}

void GraphicView::setSize(int width, int height) {
    scene->setSceneRect(0,0,width-2,height-2);
    setGeometry(0,0,width,height);
}
