#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <iconv.h>
#include <errno.h>

using namespace std;

int main() {
    extern int errno;
    ifstream ifs("/home/linus/mhyeagle/programming-language/cpp/unicode_gbk/source_file_utf8");
    string line;
    char arr[256];

    iconv_t cd = iconv_open("UTF-8", "WCHAR_T");
    char ** inbuf = NULL;
    char ** outbuf = NULL;

    while(getline(ifs, line)) {
        cout << line << endl;
        memset(arr, 0, 256);

        //outbuf = (char**)(&arr);
        char * arr_char = arr;
        outbuf = &arr_char;
        int outlen = 256;

        int inlen = line.length();
        cout << "length of line: " << inlen << endl;
        char line_arr[inlen+1];
        char * line_arr_p = line_arr;
        memset(line_arr, 0, inlen+1);
        line.copy(line_arr, inlen, 0);

        inbuf = &line_arr_p;
        int ret = iconv(cd, inbuf, (size_t*)&inlen, outbuf, (size_t*)&outlen);
        cout << "iconv return: " << ret << endl;
        cout << "errno: " << errno << endl;
    }

    return 0;
}
