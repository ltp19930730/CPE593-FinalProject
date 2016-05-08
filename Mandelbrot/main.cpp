#include "mainwindow.h"
#include "mandelbrotparallel.h"
#include <QApplication>
#include <iostream>
#include <QTime>

#include "Mandelbrot.h"
#include "Complex.hpp"

using namespace std;


int main(int argc, char *argv[])
{
    Complex ca(-2, -1);
    Complex ce(0.5, 1);
    Mandelbrot *mandelbrot = new Mandelbrot(&ca,&ce,80,80,32);

    mandelbrot->calculate();

    cout<< mandelbrot->toString()<<endl;

    QTime parallelTime;
    parallelTime.start();
    parallelMandelbrot();
    int time_Diff = parallelTime.elapsed();
    float f = time_Diff/1000.0;
    cout << f << endl;

    QTime time;
    time.start();
    mandelbrot->setDemension(860,720);
    mandelbrot->setIteration(100);
    mandelbrot->calculate();
    time_Diff = time.elapsed();
    f = time_Diff/1000.0;

    QString tr_timeDiff = QString{"%1"}.arg(f);

    QApplication a(argc, argv);
    MainWindow w(mandelbrot);
    w.setWindowTitle("MandelbrotSet Calculate Time: " +tr_timeDiff);
    w.show();

    return a.exec();
}
