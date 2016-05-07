#include "complex.hpp"

#include <string>
#include <sstream>
#include <Qstring>

Complex::Complex(double real, double imag):real(real), imag(imag){}

Complex::Complex(Complex *a){
    this->real=a->real;
    this->imag=a->imag;
}

double Complex::Modeule() const {
    return real*real + imag*imag;
}

double Complex::getReal() const {
    return real;
}

double Complex::getImag() const{
    return imag;
}

void Complex::setReal(double real){
    this->real=real;
}

void Complex::setImag(double imag){
    this->imag=imag;
}

void Complex::set(Complex a){
    this->real=a.getReal();
    this->imag=a.getImag();
}

string Complex::tostring(){
    string temp;
    double a = real,b = 0.0;
    temp = imag < 0.0 ? " - " : " + ";
    b = imag < 0.0 ? -imag : imag;
    ostringstream strs;
    strs << a << temp << b << 'i';

    return strs.str();
}
