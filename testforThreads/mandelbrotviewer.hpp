#ifndef MANDELBROTVIEWER_HPP
#define MANDELBROTVIEWER_HPP

#include "others.hpp"

#include <vector>
#include <QGraphicsView>
#include <QColor>


using namespace std;

#define DEFAULT_QCOLOR_IN_SET       (QColor(0, 0, 0))
#define MAX_WORKER_THREADS          (1)
#define DEFAULT_MAX_ITERATIONS      (10000)

class MandelbrotViewer : public QWidget{
    Q_OBJECT

public:
    MandelbrotViewer(int width,int height,QWidget *parent = NULL);
    ~MandelbrotViewer();
    void setViewParameters(int width,int height);
    void deinit();
    void setMaxIteration(int maxIteration);
    void setMaxIterations(int maxIterations);
    void setMandelLocation(MandelLocation location);
    QColor calculateImageValueColor(double value);
    void paintImage(QImage *image);
    void paintEvent(QPaintEvent *event);
    void mapImagValtoQimage(double **imageVal);

    static MandelPoint transformViewPointToMandelPoint(ViewPoint point,
            ViewParmeters viewParameters, MandelLocation mandelLocation);
    static double calculateMandelPointIterateValue(MandelPoint point);
    static void MultiThreadtask(MandelLocation mandelLocation,ViewParmeters viewParameters,double **iterateVal);
    static void singleThreadTask(MandelLocation mandelLocation,ViewParmeters viewParmeters,double **imageVal,int start,int end);



private:
    QImage *image;
    double **iterationVal;
    bool ValuesAreVaild;
    ViewParmeters viewParameters;
    MandelLocation mandelLocation;
    static int MaxIterations;
    static double IMAGE_VALUE_IN_SET;

};









#endif // MANDELBROTVIEWER_HPP
