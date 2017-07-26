#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
    char str[] = "this, a sample string";
    char * pch;
    cout << str << endl;
    pch = strtok(str, " ,.-");
    cout << "***" << endl;
    cout << pch << endl;
    cout << "***" << endl;
    while(pch != NULL) {
        cout << pch << endl;
        pch = strtok(NULL, " ,.-");
    }

    return 0;
}
