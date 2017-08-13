#include <stdio.h>
#include <string.h>

int main() {
    char sentence[] = "this is a sentence with 7 tokens";
    char *tokenPtr = strtok(sentence, " ");
    while(tokenPtr != NULL) {
        printf("%s\n", tokenPtr);
        tokenPtr = strtok(NULL, " ");
    }

    return 0;
}
