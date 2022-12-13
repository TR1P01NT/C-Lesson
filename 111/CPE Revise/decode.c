#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char str[1001] = {0};
    char kb[] = " 234567890-=ertyuiop[]\\dfghjkl;'cvbnm,./";
    char ot[] = " `1234567890qwertyuiop[asdfghjklzxcvbnm,";

    gets(str);

    for (int i = 0; i < strlen(str); i++) {
        for (int j = 0; j < strlen(kb); j++) {
            if (str[i] == kb[j]) {
                printf("%c", ot[j]);
            }
        }
    }

    printf("\n");
}