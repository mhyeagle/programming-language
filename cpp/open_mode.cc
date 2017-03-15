//在linux下二进制打开文件和普通打开文件方式相同

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    fstream fs;
    fs.open("testfile", fstream::out|fstream::binary);

    fs << "hello";
    fs.close();

    fs.open("testfile", fstream::in);
    string word;
    fs >> word;
    cout << word;
    fs.close();

    return 0;
}
