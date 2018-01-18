#include <iostream>
#include <string>

using namespace std;

class A {
public:
    A() = default;
    ~A() = default;

    A(const A&) = delete;
    A(A&&) = delete;
    A& operator=(const A&) = delete;
    A& operator=(const A&&) = delete;

    int init() {
        num = 111;
        cout << "func A::init" << endl;
    }

    int num;
};

void func() {
    cout << "func" << endl;
}

int main() {
    int test_num = 0;
    A a;
    //cout << "func addr: " << (int)func << endl;
    //init(&a);

    return 0;
}
