#include <iostream>
#include "complex_.h"
using namespace std;

int main()
{
    Complex_ c1(1,3);
    Complex_ c2(2,4);
    Complex_ c3 = c1.add(c2);  //default copy constructor
    c1.display();
    cout << " + ";
    c2.display();
    cout << " = ";
    c3.display();
    cout << endl;
    
    c3 = c1.mul(c2);  //묵시적 형변환
    c1.display();
    cout << " * c2 = ";
    c3.display();
    cout << endl;
    
    return 0;
}