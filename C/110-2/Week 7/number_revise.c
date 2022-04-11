#include <stdio.h>

int main(void) {
    char str[26] = "22233344455566677778889999";
    char c;
    int num_count, hyphen_count;

    while((c = getchar()) != EOF) {
        if (c == '\n') {
            printf(" %d %d", num_count, hyphen_count);
            num_count = 0;
            hyphen_count = 0;
        }

        if (c >= 'A' && c <= 'Z') {
            num_count++;
            printf("%c", str[c - 'A']);
        }
        else {
            if (c == '-') {
                hyphen_count++;
            }
            printf("%c", c);
        }
    }
}