#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream ifs("read_from_file_noexist.cc");

    //ifstream ifs;
    //ifs.open("file_not_exist");
    //if (!ifs) {
    //    cout << "ifs open failed" << endl;
    //    return -1;
    //}

    string line;
    while(getline(ifs, line, ' ')) {
        cout << line << endl;
    }

    return 0;
}
