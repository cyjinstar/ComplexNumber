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
    
    Complex_ operator+(const Complex_& c) const {
        return Complex_(rPart + c.rPart, iPart + c.iPart);
    }

    Complex_& operator++(){
        rPart = rPart+1;
        iPart = iPart+1;
        return *this;
    }
    
    Complex_ operator-(const Complex_& c) const {
        return Complex_(rPart - c.rPart, iPart - c.iPart);
    }
    
    Complex_& operator--(){
        rPart = rPart-1;
        iPart = iPart-1;
        return *this;
    }

    Complex_ operator*(const Complex_& c) const
    {
        double r = rPart * c.rPart - iPart * c.iPart;
        double i = rPart * c.iPart + iPart * c.rPart;
        return Complex_(r, i);
    }
    
    Complex_ operator/(const Complex_& c) const
    {
        double d = c.rPart * c.rPart + c.iPart * c.iPart;
        double r = rPart * c.rPart + iPart * c.iPart;
        double i = iPart * c.rPart - rPart * c.iPart;
        return Complex_(r/d, i/d);
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