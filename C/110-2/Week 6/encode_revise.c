#include <stdio.h>

int main(void) {
    int testcase;
    char str[100];

    scanf("%d\n", &testcase);

    while (testcase--) {
        char c;
        int num;

        while((c = getchar())) {
            if (c == '\n') {
                printf("\n");
                break;
            }

            scanf("%d", &num);

            while (num--) {
                printf("%c", c);
            }
        }
    }
}