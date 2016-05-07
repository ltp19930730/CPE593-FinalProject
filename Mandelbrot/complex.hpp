#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include<string>
#include<sstream>

#include<Qstring>

using namespace std;

class Complex{
private:
    double real;
    double imag;
public:
    Complex(double real,double imag);
    Complex(Complex *a);


    double Modeule() const;
    double getReal() const;
    double getImag() const;
    void setReal(double real);
    void setImag(double imag);
    void set(Complex a);
    string tostring();

};

#endif // COMPLEX_HPP
