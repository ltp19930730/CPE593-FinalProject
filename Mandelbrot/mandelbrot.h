#ifndef MANDELBROT_H
#define MANDELBROT_H

#include <string>
#include <sstream>
#include <vector>
#include <QObject>

#include "complex.hpp"

using namespace std;

class Mandelbrot : public QObject{
    Q_OBJECT
private:
    int wide;
    int height;
    Complex *start;
    Complex *end;

    Complex *ca;
    Complex *ce;

    int iteration;
    int *pixel;
public:
    Mandelbrot(Complex *ca, Complex *ce, int iteration, int wide, int height);
    ~Mandelbrot();

    void calculate();
    int getIterationForPixel(Complex z);

    Complex PixelofComplex(int w,int h);
    void setIteration(int newIteration);

    Complex *getCa()const;
    Complex *getCe()const;
    int getIteration()const;
    int getWide()const;
    int getHeight()const;

    int getIterationOfPixel(int i,int j)const;
    string toString();
    void setDemension(int wide,int height);

};


#endif // MANDELBROT_H
