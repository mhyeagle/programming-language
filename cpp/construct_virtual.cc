#include <iostream>

using namespace std;

class A {
public:
    A() {
        cout << "in A constructor: ";
        Test();
    }

    virtual ~A() {
        cout << "A destruct" << endl;
        Test();
    }

    virtual void Test() {
        cout << "A's Test function" << endl;
    }

};

class B: public A {
public:
    B() {
        cout << "in B constructor: ";
        Test();
    }

    ~B() {
        cout << "B destruct" << endl;
        Test();
    }

    void Test() {
        cout << "B's Test function" << endl;
    }
};

int main() {
    A* p_a = new B;
    delete p_a;

    return 0;
}


