#include <stdio.h>
#include <string.h>

int main(void) {
    char sentences[100][100] = {0};
    int rows = 0;
    int max_length = 0;

    while(gets(sentences[rows])) {
        if(strlen(sentences[rows]) > max_length) {
            max_length = strlen(sentences[rows]);
        }
        rows++;
    }

    for (int i = 0; i < max_length; i++) {
        for (int j = rows - 1; j >= 0; j--) {
            if (i >= strlen(sentences[j])) {
                printf(" ");
            }
            else {
                printf("%c", sentences[j][i]);
            }
        }
        printf("\n");
    }
}