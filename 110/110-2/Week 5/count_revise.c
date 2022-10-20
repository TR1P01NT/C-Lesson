#include <stdio.h>
#include <ctype.h>

int main(void) {
    char c;
    int line;
    int count = 0;
    int flag = 1;

    while((c = getchar()) != EOF) {
        if (c != '\n') {
            if (isalpha(c)) {
                if (flag == 1) {
                    count++;
                    flag = 0;
                }
            }
            else {
                flag = 1;
            }
        }
        else {
            printf("%d\n", count);
            count = 0;
        }
    }
}