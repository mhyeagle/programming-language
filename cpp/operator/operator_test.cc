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
    

public:
    double real, imag;
};

inline A A::operator+(const A& a) {
    return A(real+a.real, imag+a.imag);
}


int main() {
    A a1;
    A a2(10, 10.1);

    A c;
    c = a1 + a2;

    cout << c.real << "\t" << c.imag << endl;
    
    return 0;
}
