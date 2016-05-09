#include <QApplication>
#include "mandelbrotviewer.hpp"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //set the dimension as 800*600
    MandelbrotViewer mandelbrot(800,600);

    //show the widget of the mandelbrot viewer
    mandelbrot.show();
    return a.exec();
}
