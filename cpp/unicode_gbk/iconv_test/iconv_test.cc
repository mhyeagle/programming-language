#include <iostream>
#include <string.h>
#include <iconv.h>
#include <stdlib.h>

#define OUTLEN 255

using namespace std;

class CodeConverter {
public:
    CodeConverter(const char * from_charset, const char * to_charset) {
        _cd = iconv_open(to_charset, from_charset);
    }

    ~CodeConverter() {
        iconv_close(_cd);
    }

    int convert(char * inbuf, int inlen, char * outbuf, int outlen) {
        char ** pin = &inbuf;
        char ** pout = &outbuf;
    
        memset(outbuf, 0, outlen);
        return iconv(_cd, pin, (size_t *)&inlen, pout, (size_t *)&outlen);
    }

private:
    iconv_t _cd;
};


int main(int argc, char ** argv) {
    char * in_utf8 = "中国人";
    char * in_gb2312 = "正在安装";
    char out[OUTLEN];

    //utf-8 --> gb2312
    CodeConverter cc = CodeConverter("utf-8", "WCHAR_T");
    cc.convert(in_utf8, strlen(in_utf8), out, OUTLEN);
    cout << "utf-8--> unicode in=" << in_utf8 << " ,out=" << out << endl;
    wchar_t w_str[256] = {'\0'};
    int ret = mbstowcs(w_str, out, OUTLEN);
    cout << "num str: " << strlen(out) << endl;
    cout << "num w_str: " << ret << endl;

    //gb2312 --> utf-8
    //CodeConverter cc2 = CodeConverter("gb2312", "utf-8");
    //cc2.convert(in_gb2312, strlen(in_gb2312), out, OUTLEN);
    //cout << "gb2312 --> utf-8 in=" << in_gb2312 << " ,out=" << out << endl;
    //unicode --> utf8
    char out2[OUTLEN];
    CodeConverter cc2 = CodeConverter("WCHAR_T", "utf-8");
    cc2.convert(out, strlen(out), out2, OUTLEN);
    cout << "unicode to utf8: " << out2 << endl;

    return 0;
}
