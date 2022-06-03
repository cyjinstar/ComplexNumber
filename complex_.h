#include <iostream>
using namespace std;

class Complex_{
    double rPart, iPart; //실수부, 허수부
public:
    //생성자
    Complex_(double r=0, double i=0) : rPart(r), iPart(i) {}
    
    Complex_ conj() const {
        return Complex_(rPart, -iPart);
    }
    
    Complex_ add(const Complex_& c) const {
        return Complex_(rPart + c.rPart, iPart + c.iPart);
    }
    
    Complex_ sub(const Complex_& c) const {
        return Complex_(rPart - c.rPart, iPart - c.iPart);
    }
    
    Complex_ mul(const Complex_& c) const
    {
        double r = rPart * c.rPart - iPart * c.iPart;
        double i = rPart * c.iPart + iPart * c.rPart;
        return Complex_(r, i);
    }
    
    Complex_ div(const Complex_& c) const
    {
        double d = c.rPart * c.rPart + c.iPart * c.iPart;
        Complex_ c1 = mul(c.conj());
        return Complex_(c1.rPart/d, c1.iPart/d);
    }
    
    void display() const
    {
        cout << "[" << rPart;
        if (iPart > 0)
            cout << "+i" << iPart;
        else if (iPart < 0)
            cout << "-i" << -iPart;
        cout << "]";
    }
};