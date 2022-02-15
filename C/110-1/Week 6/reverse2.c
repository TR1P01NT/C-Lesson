#include <stdio.h>
#include <string.h>

int main(void) {
    int left, right, l = 0, i = 0;
    char str[25], temp;

    while (scanf("%s", str) != EOF) {
        l = strlen(str);

        left = 0;
        right = l - 1;

        for (i = left; i < right; i++) {
            temp = str[i];
            str[i] = str[right];
            str[right] = temp;
            right--;
        }

        printf("%s\n", str);
    }
}