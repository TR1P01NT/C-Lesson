#include <stdio.h>

int main() {
    int a, b, c;

    scanf("%d%d%d", &a, &b, &c);

    if (a > 0 && b > 0 && c > 0) {
        if (a + b <= c || a + c <= b || b + c <= a) {
            printf("False\n");
        }
        else {
            printf("True\n");
        }  

    }

    return 0;
}