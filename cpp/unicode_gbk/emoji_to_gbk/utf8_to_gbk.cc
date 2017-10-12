#include "utf8_to_gbk.h"

Utf8ToGbk::Utf8ToGbk() {
    _cc = new CodeConverter("UTF-8", "WCHAR_T");
    if (_cc == NULL) {
        perror("Utf8ToGbk construct error.");
    }
    _swap = new char[BUFLEN];
    if (_swap == NULL) {
        perror("Utf8ToGbk construct failed.");
    } else {
        memset(_swap, 0, BUFLEN);
    }
    _swap_2 = new char[BUFLEN];
    if (_swap_2 == NULL) {
        perror("Utf8ToGbk construct failed.")
    } else {
        memset(_swap_2, 0, BUFLEN);
    }

    _emoji_base[0] = L'[';
    _emoji_base[1] = L'e';
    _emoji_base[2] = L'm';
    _emoji_base[3] = L'o';
    _emoji_base[4] = L'j';
    _emoji_base[5] = L'i';
    _emoji_base[6] = L']';
}

Utf8ToGbk::~Utf8ToGbk() {
    if (_cc != NULL) {
        delete _cc;
    }
    if (_swap != NULL) {
        delete[] _swap;
    }
    if (_swap_2 != NULL) {
        delete[] _swap_2;
    }
}

int Utf8ToGbk::convert(const char * source, char * dest, bool & has_emoji) {
    //step 1, convert utf8 to unicode
    strcpy(_swap, source);
    int ret = _cc.convert(_swap, strlen(_swap), _swap_2, BUFLEN);
    if (ret == (size_t)-1) {
        perror("iconvert error");
        return -1;
    }

    //step 2, travel unicode and exchange emoji
    //emoji to [emoji]1F3BF[emoji]
    int * dest_p = (int *)dest;
    has_emoji = false;
    int * p = _swap_2;
    while(*p != 0) {
        bool flag = is_emoji(*p);
        if (flag) {
            //need exchange emoji
            int ret = exchange_emoji(*p);
            for (int i = 0; i < ret; ++i) {
                *dest_p++ = _emoji[i];
            }
            p++;
        } else {
            //do not need to exchange
            *dest_p++ = *p++;
        }
    }
}

bool Utf8ToGbk::is_emoji(int code_point) {
    return (code_point >= 0x2600 && code_point <= 0x27BF)
            || code_point == 0x303D
            || code_point == 0x2049
            || code_point == 0x203C
            || (code_point >= 0x2000 && code_point <= 0x200F)
            || (code_point >= 0x2028 && code_point <= 0x206F)
            || (code_point >= 0x2100 && code_point <= 0x214F)
            || (code_point >= 0x2300 && code_point <= 0x23FF)
            || (code_point >= 0x2B00 && code_point <= 0x2BFF)
            || (code_point >= 0x2900 && code_point <= 0x297F)
            || (code_point >= 0x3200 && code_point <= 0x32FF)
            || (code_point >= 0xD800 && code_point <= 0xDFFF)
            || (code_point >= 0xE000 && code_point <= 0xF8FF)
            || (code_point >= 0xFE00 && code_point <= 0xFE0F)
            || code_point >= 0x10000;
}

int Utf8ToGbk::exchange_emoji(int code_point) {
    //first '[emoji]'
    memset((char*)_emoji, 0, 4*EMOJILEN);
    int i = 0;
    for (; i < EMOJIBASELEN; ++i) {
        _emoji[i++] = _emoji_base[i];
    } 
    
    //emoji to 8 wchar_t
    bool not_zero = false;
    char * p_char = (char *)&code_point;
    for (int j = 0; j < 4; ++j) {
        int value = (*p_char & 0xF0) >> 4;
        if (value != 0) {
            not_zero = true;
        }
        if (not_zero) {
            if (value < 10) {
                _emoji[i++] = L'0' + value;
            } else {
                _emoji[i++] = L'A' + (value-10);
            }
        }

        int value2 = *p_char & 0x0F;
        if (value2 != 0) {
            not_zero = true;
        }
        if (not_zero) {
            if (value < 10) {
                _emoji[i++] = L'0' + value;
            } else {
                _emoji[i++] = L'A' + (value-10);
            }
        }
    } 

    for (int k = 0; k < EMOJIBASELEN; ++k) {
        _emoji[i++] = _emoji_base[k];
    }

    return i;
}

