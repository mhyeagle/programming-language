#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#define PATH "/home/linus/mhyeagle/programming-language/c/access_test.c"

int main() {
    int ret = access(PATH, 0);
    printf("return: %d\n", ret);
    struct stat file_stat;
    ret = stat(PATH, &file_stat);
    printf("stat return: %d\n", ret);
    if (ret == 0) {
        ret = S_ISREG(file_stat.st_mode);
        printf("S_ISREG: %d\n", ret);
    }

    return 0;
}
