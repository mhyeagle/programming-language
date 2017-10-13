#ifndef __UTF8_TO_GBK__
#define __UTF8_TO_GBK__

#include <string.h>
#include <stdlib.h>
#include <iconv.h>

#define BUFLEN 65535
#define EMOJILEN 22
#define EMOJIBASELEN 7

class CodeConverter {
public:
    CodeConverter(const char * from_charset, const char * to_charset) {
        _cd = iconv_open(to_charset, from_charset);
        if (_cd == (iconv_t)-1) {
            perror("iconv_open error: ");
        }
    }

    ~CodeConverter() {
        iconv_close(_cd);
    }

    int convert(char * inbuf, int inlen, char * outbuf, int outlen) {
        char ** pin = &inbuf;
        char **pout = &outbuf;

        memset(outbuf, 0, outlen);
        size_t ret = iconv(_cd, pin, (size_t *)&inlen, pout, (size_t *)&outlen);
        if (ret == -1) {
            perror("iconv() error: ");
        }
        return ret;
    }

private:
    iconv_t _cd;
};

//utf8 to gbk include emoji
class Utf8ToGbk {
public:
    Utf8ToGbk(); 
    ~Utf8ToGbk(); 

    int convert(const char * source, char * dest);

private:
    bool is_emoji(int code_point);
    int exchange_emoji(int code_point);
private:
    CodeConverter * _cc;
    CodeConverter * _cc2;
    char * _swap[3];
    int _emoji[EMOJILEN];
    wchar_t _emoji_base[EMOJIBASELEN];
};

#endif //__UTF8_TO_GBK__
