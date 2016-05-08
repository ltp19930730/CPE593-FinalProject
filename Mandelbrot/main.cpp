#include "mainwindow.h"
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

    QTime time;
    time.start();
    mandelbrot->setDemension(860,720);
    mandelbrot->setIteration(100);
    mandelbrot->calculate();
    int time_Diff = time.elapsed();
    float f = time_Diff/1000.0;

    QString tr_timeDiff = QString{"%1"}.arg(f);

    QApplication a(argc, argv);
    MainWindow w(mandelbrot);
    w.setWindowTitle("MandelbrotSet Calculate Time: " +tr_timeDiff);
    w.show();

    return a.exec();
}
