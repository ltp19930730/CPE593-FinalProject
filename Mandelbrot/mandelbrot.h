#ifndef MANDELBROT_H
#define MANDELBROT_H

#include <string>
#include <sstream>
#include <vector>
#include <QObject>

#include "complex.hpp"

using namespace std;

namespace mandelbrot {

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
    Mandelbrot(Complex *ca, Complex *ce, int iteration, int wide, int height){
        this->ca = ca;
        this->ce = ce;
        this->wide = wide;
        this->height = height;
        this->iteration = iteration;
        start = new Complex(ca);
        end = new Complex(ce);
    }
    ~Mandelbrot(){
        if(pixel) delete [] pixel;
    }

    void calculate(){
        pixel = new int [wide * height];

        for(int i = 0; i < wide ; ++i){
            for(int j = 0 ; j < height; ++j){
                pixel[i+j*wide]= getIterationForPixel(PixelofComplex(i,j));
            }
        }

    }

    int getIterationForPixel(Complex z){
        Complex c = z;

        for(int i = 0;i < iteration; i++){
            // when the point escape return the iteration times
            if(z.Modeule() > 4){
                return i;
            }
            // x = x*x-y*y + C.x
            double x = (z.getReal()*z.getReal() - z.getImag()*z.getImag())+ c.getReal();
            // y = 2*x*y + C.y
            double y = (2 * z.getReal()* z.getImag()+c.getImag());

            z = Complex(x,y);
        }
        return iteration;
    }



    Complex PixelofComplex(int w,int h){
        double a = ((ce->getReal()-ca->getReal()) / wide)*w + ca->getReal();
        double b = ((ce->getImag()-ca->getImag()) / height)*(height-h) + ca->getImag();
        return Complex(a,b);
    }
    void setIteration(int newIteration){
        if(newIteration>=0){
            this->iteration = newIteration;
        }
    }
    Complex *getCa()const{
        return ca;
    }
    Complex *getCe()const{
        return ce;
    }

    int getInteration()const{
        return iteration;
    }

    int getWide()const{
        return wide;
    }

    int getHeight()const{
        return height;
    }
    int getIterationOfPixel(int i,int j)const{
        return pixel[i+j*wide];
    }
    string toString(){
        string str = "";

        for(int i = 0; i < height;++i){
            for(int j = 0; j < wide; ++j){
                int iter = getIterationOfPixel(j,i);
                char temp =  iteration == iter ? ' ' : (char)(iter % 26 +65);

                str += temp;
            }
            str += "\n";
        }
        return str;
    }
    void setDemension(int wide,int height){
        if(wide >= 0 && height >= 0){
            this->wide = wide;
            this->height = height;
        }
    }



};

}


#endif // MANDELBROT_H
