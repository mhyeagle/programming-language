//构造函数里是可以调用其他构造函数的，只要不引起循环调用就好。
//这里是因为Test(a);被解析为声明语句（即等价于Test a;）而非显示类型转换，所以引起了循环调用。这也是为什么C++11后推荐使用{}初始化代替()初始化，新手遇到这种错误时通常是难以察觉的（一般的教材上也没有写）。
//如果按楼主的意思，这里应该改成Test{a};。
//

#include <iostream>
#include <unistd.h>

using namespace std;

int a = 10;

class Test {
public:
//在C++11之前，你在任何时候都不能显式调用构造函数，只能通过创建对象（在堆上、栈上、指针指定缓冲区，构造新对象）的方式隐式调用构造函数。
//在C++11中出现Delegating Constructor概念，可以在一个构造函数的初始化列表中的第一个位置，调用其它的构造函数。
//C++11的初始化列表如果有委托构造函数，就不能有其他初始化项了。
    Test() : Test(a) {
        cout << "constructor Test() be called" << endl;
        sleep(1);
        //这种方式相当于Test a;即定义了一个Test类的对象,所以下面这条语句会引起循环调用
        //Test(a);
        //method1 c++11, 这样的调用是生成了一个临时对象,不是对对象本身进行构造
        //Test{a};
    }

    Test(int i) {
        cout << "constructor Test(int) be called" << endl;
        m_i = i;
    }

    void output() {
        cout << "value of the object: " << m_i << endl;
    }

private:
    int m_i;
};

int main() {
    Test b;
    b.output();

    return 0;
}
