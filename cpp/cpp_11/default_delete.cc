#include <iostream>

using namespace std;

class A {
public:
    A() = default;
    A(int i);

    int add(int i);
    int operator*(int i);
    double operator/(int i) = delete;

    virtual ~A() = default;

private:
    int x;

};

A::A(int i) {
    x = i;
}

int A::add(int i) {
    x += i;
    return x;
}

int A::operator*(int i) {
    return x * i;
}

int main() {
    A x;
    A y(10);

    cout << x.add(5) << endl;
    cout << y.add(5) << endl;

    int num = y * 5;
    cout << num << endl;

    //double f = y / 5;
    

    return 0;
}
