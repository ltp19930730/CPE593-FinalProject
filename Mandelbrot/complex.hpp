#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include<string>
#include<sstream>

#include<Qstring>

using namespace std;

namespace mandelbrot {

class Complex{
private:
    double real;
    double imag;
public:
    Complex(double real,double imag):real(real),imag(imag){}
    Complex(Complex *a){
        this->real=a->real;
        this->imag=a->imag;
    }
    double Modeule() const{
        return real*real+imag*imag;
    }
    double getReal() const{
        return real;
    }
    double getImag() const{
        return imag;
    }
    void setReal(double real){
        this->real=real;
    }
    void setImag(double imag){
        this->imag=imag;
    }
    void set(Complex a){
        this->real=a.getReal();
        this->imag=a.getImag();
    }
    string tostring(){
        string temp;
        double a = real,b = 0.0;
        temp = imag < 0.0 ? " - " : " + ";
        b = imag < 0.0 ? -imag : imag;
        ostringstream strs;
        strs << a << temp << b << 'i';

        return strs.str();
    }

};
}

#endif // COMPLEX_HPP
