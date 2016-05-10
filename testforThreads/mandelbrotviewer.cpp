#include "mandelbrotviewer.hpp"

#include <math.h>
#include <thread>
#include <QTime>
#include <limits>
#include <iostream>

// construct of MandelbrotViewer to initial the object
MandelbrotViewer::MandelbrotViewer(int width,int height,QWidget *parent) : QWidget(parent){
    //init
    image = NULL;
    iterationVal = NULL;
    this->ValuesAreVaild =false;
    setViewParameters(width,height);
    this->resize(width, height);
    setMandelLocation(MandelLocation(MandelPoint(-0.85,0.0),0.0035));
    setMaxIterations(DEFAULT_MAX_ITERATIONS);


    connect(this, SIGNAL(signalZoom()), this, SLOT(slotZoomEvent()));
}
// set the static variable MaxIterations
int MandelbrotViewer::MaxIterations = DEFAULT_MAX_ITERATIONS;


// set the static variable IMAGE_VALUE_IN_SET as the max of double
double MandelbrotViewer::IMAGE_VALUE_IN_SET = std::numeric_limits<double>::max();


double MandelbrotViewer::zoomMultiplier = DEFAULT_ZOOM;

// insert the view parameters into a instance of a ViewParameter class
void MandelbrotViewer::setViewParameters(int width,int height){
    deinit();
    viewParameters.width = width;
    viewParameters.height = height;
    viewParameters.origin.x = width /2;
    viewParameters.origin.y = height /2;

    image = new QImage(width,height, QImage::Format_RGB888);

    iterationVal = new double*[width];
    for(int i = 0;i < width;i++){
        iterationVal[i] = new double[height];
    }
    ValuesAreVaild = false;
}

// set the mandelbrot location
void MandelbrotViewer::setMandelLocation(MandelLocation location){
    this->mandelLocation = location;
}

void MandelbrotViewer::setMaxIterations(int maxIterations){
    this->MaxIterations = maxIterations;}

MandelbrotViewer::~MandelbrotViewer(){
    deinit();
}
// Deconstruct the instance
void MandelbrotViewer::deinit(){
    if(iterationVal != NULL){
        for(int i = 0;i< viewParameters.width;i++){
            delete iterationVal[i];
        }
    }
    delete iterationVal;
    iterationVal = NULL;
    delete image;
    image = NULL;
}

// transform the view point to a mandelpoint which is a complex number
MandelPoint MandelbrotViewer::transformViewPointToMandelPoint(ViewPoint point,ViewParmeters viewParameters,MandelLocation mandelLocation){
    int xviewdiff = point.x - viewParameters.origin.x;
    int yviewdiff = viewParameters.origin.y-point.y;
    double scaledX = xviewdiff*mandelLocation.pixelDelta;
    double scaledY = yviewdiff*mandelLocation.pixelDelta;

    double Newx = scaledX + (double)mandelLocation.origin.x;
    double Newy = scaledY + (double)mandelLocation.origin.y;
    return MandelPoint(Newx,Newy);
}

// calculate escaping value of the mandelbrot point
double MandelbrotViewer::calculateMandelPointIterateValue(MandelPoint point){
    double x = 0;
    double y = 0;
    int i;
    for(i=0;i<MaxIterations;i++){
        if(x*x+y*y > 4){
            break;
        }
        double xtemp = x*x-y*y+point.x;
        y = 2*x*y + point.y;
        x=xtemp;
    }


    if(i>=MaxIterations){
        return IMAGE_VALUE_IN_SET;
    }
    double distance = sqrt(x*x+y*y);
    double imagevalue = (double)i - (log(log(distance)) / log(2.0));

    return imagevalue;
}

// transfrom the escaping value to a color
QColor MandelbrotViewer::calculateImageValueColor(int value){
    if(value >MaxIterations || value == IMAGE_VALUE_IN_SET){
        return DEFAULT_QCOLOR_IN_SET;
    }
    value = fmod(value,256);
    return QColor(0,value,0);
//another way to color the pixel
   /* if (value < MaxIterations && value > 0) {
        int i = value % 16;
        QColor mapping[16];
        mapping[0].setRgb(66, 30, 15);
        mapping[1].setRgb(25, 7, 26);
        mapping[2].setRgb(9, 1, 47);
        mapping[3].setRgb(4, 4, 73);
        mapping[4].setRgb(0, 7, 100);
        mapping[5].setRgb(12, 44, 138);
        mapping[6].setRgb(24, 82, 177);
        mapping[7].setRgb(57, 125, 209);
        mapping[8].setRgb(134, 181, 229);
        mapping[9].setRgb(211, 236, 248);
        mapping[10].setRgb(241, 233, 191);
        mapping[11].setRgb(248, 201, 95);
        mapping[12].setRgb(255, 170, 0);
        mapping[13].setRgb(204, 128, 0);
        mapping[14].setRgb(153, 87, 0);
        mapping[15].setRgb(106, 52, 3);
        return mapping[i];
    }
    else return Qt::black;
*/
}
// Multi-Threads algorithm for generating the image
// separate the view into the number of the threads and then give each thread a job
// in the end ,join the threads togother
void MandelbrotViewer::MultiThreadtask(MandelLocation mandelLocation,
                 ViewParmeters viewParameters,double **iterateVal){
    vector<std::thread*> threads;
    for(int i=0; i<MAX_WORKER_THREADS; i++){
        int start = i*(viewParameters.width / MAX_WORKER_THREADS);
        int end = (i+1)*(viewParameters.width / MAX_WORKER_THREADS);
        std::thread *thread = new std::thread(singleThreadTask, mandelLocation, viewParameters, iterateVal, start, end);
        threads.push_back(thread);
    }
    for(uint i=0; i < threads.size(); i++){
        threads[i]->join();
        delete threads[i];
    }
}

// each thread call this static function to do their works
void MandelbrotViewer::singleThreadTask(MandelLocation mandelLocation,ViewParmeters viewParmeters,double **imageVal,int start,int end){
    for(int i=start;i<end;i++){
        for(int j=0;j<viewParmeters.height;j++){
            MandelPoint mandelPoint = transformViewPointToMandelPoint(ViewPoint(i,j),viewParmeters,mandelLocation);
            double value = calculateMandelPointIterateValue(mandelPoint);
            imageVal[i][j] = value;
        }
    }
}

// change the value into a real color on the image view of Qimage
void MandelbrotViewer::mapImagValtoQimage(double **imageVal){
    for(int i=0; i<viewParameters.width; i++){
        for(int j=0; j<viewParameters.height; j++){
            image->setPixel(i, j, calculateImageValueColor(imageVal[i][j]).rgb());
        }
    }
}



void MandelbrotViewer::paintEvent(QPaintEvent *event){
    paintImage(this->image);
}

void MandelbrotViewer::paintImage(QImage *image){
     QTime time;
     time.start();
    if(!ValuesAreVaild){
        // multiThread to calculate
        setWindowTitle(tr("Rendering..."));
        MultiThreadtask(mandelLocation,viewParameters,iterationVal);
        ValuesAreVaild = true;
    }
    mapImagValtoQimage(iterationVal);

    QPainter painter(this);
    painter.drawImage(0, 0, *image);

    // to calculate the time to render this image and print it on the windowTitle
    int time_Diff = time.elapsed();
    float f = time_Diff/1000.0;

    QString tr_timeDiff = QString{"%1"}.arg(f);

    setWindowTitle("MandelbrotSet Calculate Time: " +tr_timeDiff);
}

void MandelbrotViewer::mousePressEvent(QMouseEvent *event){
    this->latestQMouseEvent = event;
    emit signalZoom();
}

// press left button to zoom in and press right button to zoom out
void MandelbrotViewer::slotZoomEvent(){
    ViewPoint point(latestQMouseEvent->x(), latestQMouseEvent->y());

    if(latestQMouseEvent->button() == Qt::LeftButton){
        mandelLocation.pixelDelta /= zoomMultiplier;
        MandelLocation newMandelLocation(transformViewPointToMandelPoint(point, viewParameters, mandelLocation), mandelLocation.pixelDelta);
        setMandelLocation(newMandelLocation);
        if(zoomTime>=5){
            setMaxIterations(MaxIterations*2);
        }
        zoomTime++;
        std::cout<<"zoom time:"<<zoomTime<<'\t'<<"Iterations:"<<MaxIterations << endl;
    }else if(latestQMouseEvent->button() == Qt::RightButton){
        MandelLocation newMandelLocation(transformViewPointToMandelPoint(point, viewParameters, mandelLocation), mandelLocation.pixelDelta);
        setMandelLocation(newMandelLocation);
        mandelLocation.pixelDelta *= zoomMultiplier;
        if(zoomTime>=5){
            setMaxIterations(MaxIterations/2);
        }
        zoomTime--;
    }
    ValuesAreVaild = false;
    this->update();
}




































