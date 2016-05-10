#ifndef MandelbrotThread_HPP
#define MandelbrotThread_HPP

#include "others.hpp"

#include <vector>
#include <QGraphicsView>
#include <QColor>
#include <QResizeEvent>

using namespace std;

#define DEFAULT_QCOLOR_IN_SET       (QColor(0, 0, 0))
#define MAX_WORKER_THREADS          (100)
#define DEFAULT_MAX_ITERATIONS      (1000)
#define DEFAULT_ZOOM                 (2.0)
class MandelbrotThread : public QWidget{
    Q_OBJECT

public:
    MandelbrotThread(int width,int height,QWidget *parent = NULL);
    MandelbrotThread(int width,int height,int iter,QWidget *parent = NULL);
    ~MandelbrotThread();
    void setViewParameters(int width,int height);
    void deinit();
    void setMaxIteration(int maxIteration);
    void setMaxIterations(int maxIterations);
    void setMandelLocation(MandelLocation location);


    QColor calculateImageValueColor(int value);
    void paintImage(QImage *image);
    void paintEvent(QPaintEvent *event);
    void mapImagValtoQimage(double **imageVal);
    static MandelPoint transformViewPointToMandelPoint(ViewPoint point,
            ViewParmeters viewParameters, MandelLocation mandelLocation);
    static double calculateMandelPointIterateValue(MandelPoint point);
    static void MultiThreadtask(MandelLocation mandelLocation,ViewParmeters viewParameters,double **iterateVal);
    static void singleThreadTask(MandelLocation mandelLocation,ViewParmeters viewParmeters,double **imageVal,int start,int end);
    QString calculateTime();

    void mousePressEvent(QMouseEvent *event);

signals:
    void signalZoom();

public slots:
    void slotZoomEvent();
private:
    QImage *image;
    double **iterationVal;
    bool ValuesAreVaild;
    ViewParmeters viewParameters;
    MandelLocation mandelLocation;
    static int MaxIterations;
    static double IMAGE_VALUE_IN_SET;
    static double zoomMultiplier;

    QMouseEvent *latestQMouseEvent;
    int zoomTime = 0;
};









#endif // MandelbrotThread_HPP
