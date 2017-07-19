#include <iostream>

using namespace std;

int func(void) {
    static int count = 10;
    return count--;
}

int count = 1;

int main() {
    for(; count <= 10; ++count) {
        cout << count << "\t\t" << func() << endl;
    }

    return 0;
}
