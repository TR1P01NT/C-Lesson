#include <stdio.h>
#include <string.h>

int main(void) {
    char line[100];
    char c;
    int flag = 1;

    while ((c = getchar()) != EOF) {
        if (c == '"') {
            if (flag) {
                flag = 0;
                printf("``");
            }
            else {
                flag = 1;
                printf("''");
            }
        }
        else {
            printf("%c", c);
        }
    }
}