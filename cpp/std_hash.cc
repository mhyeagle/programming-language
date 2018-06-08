#include <iostream>
#include <string>
#include <functional>

using namespace std;

int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "usage: " << argv[0] << " string" << endl;
        return -1;
    }

    std::hash<std::string> h;
    size_t n = h(argv[1]);

    cout << "string: " << argv[1] << endl;
    cout << "hash code: " << n << endl;

    return 0;
}
