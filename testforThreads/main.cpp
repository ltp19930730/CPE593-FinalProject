#include <QApplication>
#include "mandelbrotviewer.hpp"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MandelbrotViewer mandelbrot(800,600);
    mandelbrot.show();

    return a.exec();
}
