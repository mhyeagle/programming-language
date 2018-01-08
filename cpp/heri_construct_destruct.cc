#include <iostream>

using namespace std;

class A {
public:
    A() {
        cout << "A construct" << endl;
    }
    ~A() {
        cout << "A destruct" << endl;
    }
};

class B: public A {
public:
    B() {
        cout << "B construct" << endl;
    }
    ~B() {
        cout << "B destruct" << endl;
    }
};


int main() {
    B b;
}
