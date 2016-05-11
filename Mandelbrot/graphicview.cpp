#include "graphicview.h"
#include "Mandelbrot.h"
#include "Graphic.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>

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

void GraphicView::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_Plus:
        zoomIn();
        break;
    case Qt::Key_Minus:
        zoomOut();
        break;
    default:
        QGraphicsView::keyPressEvent(event);
        break;
    }
    this->repaint();
}

void GraphicView::scaleView(qreal scaleFactor)
{
    qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor < 0.07 || factor > 100)
        return;
    scale(scaleFactor, scaleFactor);
}

void GraphicView::zoomIn() {
    scaleView(qreal(1.2));
    this->repaint();
}

void GraphicView::zoomOut() {
    scaleView(1 / qreal(1.2));
    this->repaint();
}

void GraphicView::redraw() {
    graph->update();
}
