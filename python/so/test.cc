#include <iostream>
#include <string>

using namespace std;

#ifdef __cplusplus
extern "C" {
#endif

char* testFunc(char* str) {
    cout << "in so testFunc(string):" << endl;
    cout << str << endl;
    cout << "end" << endl;
    return str;
}

int testFunc1(int num) {
    cout << "in so testFunc1(int):" << endl;
    cout << num << endl;
    cout << "end" << endl;
    return num;
}

#ifdef __cplusplus
}
#endif
