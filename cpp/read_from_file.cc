#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream ifs("read_from_file.cc");
    string line;
    while(getline(ifs, line, ' ')) {
        cout << line << endl;
    }

    return 0;
}
