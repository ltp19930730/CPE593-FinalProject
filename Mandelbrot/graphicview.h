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
    void redraw();

public slots:
    void zoomIn();
    void zoomOut();

protected:
    void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
    void scaleView(qreal scaleFactor);
};


#endif // GRAPHICVIEW_H
