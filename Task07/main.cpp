#include <cmath>
#include <iostream>
#include <stdexcept>
class Complex {
    double re, im;
public:
    Complex():re(0),im(0){}
    Complex(double r):re(r),im(0){}
    Complex(double r,double i):re(r),im(i){}
    Complex operator+(const Complex& z) const { return {re+z.re,im+z.im}; }
    Complex operator-(const Complex& z) const { return {re-z.re,im-z.im}; }
    Complex operator*(const Complex& z) const { return {re*z.re-im*z.im,re*z.im+im*z.re}; }
    Complex operator/(const Complex& z) const {
        double d=z.re*z.re+z.im*z.im;
        if(d==0) throw std::domain_error("division by zero impedance");
        return {(re*z.re+im*z.im)/d,(im*z.re-re*z.im)/d};
    }
    bool operator==(const Complex& z) const { return std::abs(re-z.re)<1e-9 && std::abs(im-z.im)<1e-9; }
    double magnitude() const { return std::sqrt(re*re+im*im); }
    friend std::ostream& operator<<(std::ostream& o,const Complex& z) { return o << z.re << (z.im<0?" - j":" + j") << std::abs(z.im); }
};
int main() {
    Complex resistor(10,0), inductor(0,5), capacitor(0,-2);
    Complex series=resistor+inductor+capacitor;
    Complex parallel=(resistor*inductor)/(resistor+inductor);
    std::cout << "Series impedance: " << series << ", magnitude=" << series.magnitude() << '\n';
    std::cout << "Parallel R-L: " << parallel << ", magnitude=" << parallel.magnitude() << '\n';
    try { Complex bad=resistor/Complex(); (void)bad; }
    catch(const std::domain_error& e) { std::cout << "Safe error: " << e.what() << '\n'; }
}