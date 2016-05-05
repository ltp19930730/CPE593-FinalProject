#include "mainwindow.h"
#include <QApplication>
#include <iostream>

#include "Mandelbrot.h"
#include "Complex.hpp"

using namespace mandelbrot;
using namespace std;


int main(int argc, char *argv[])
{
    Complex ca(-2, -1);
    Complex ce(0.5, 1);
    Mandelbrot *mandelbrot = new Mandelbrot(&ca,&ce,80,80,32);

    mandelbrot->calculate();

    cout<< mandelbrot->toString()<<endl;

    mandelbrot->setDemension(750,600);
    mandelbrot->calculate();


    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
