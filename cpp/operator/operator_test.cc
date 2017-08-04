#include <iostream>

using namespace std;

class A {
public:
    A(): real(0), imag(0) {
    }
    A(double a, double b): real(a), imag(b) {
    }

    ~A(){}

    A operator+(const A& a);

    friend A operator-(const A& a, const A& b);
    

public:
    double real, imag;
};

inline A A::operator+(const A& a) {
    return A(real+a.real, imag+a.imag);
}

A operator-(const A& a, const A& b) {
    return A(a.real-b.real, a.imag-b.imag);
}


int main() {
    A a1;
    A a2(10, 10.1);

    A c;
    c = a1 + a2;

    cout << c.real << "\t" << c.imag << endl;

    //******friend function******
    A d(5, 5.0);
    A e;
    e = a2 - d;
    cout << e.real << "\t" << e.imag << endl;
    
    return 0;
}
