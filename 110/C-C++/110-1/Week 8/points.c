#include <stdio.h>

int toQualityPoints (int x);

int main(void) {
    int input;

    scanf("%d", &input);

    while (input != -1) {
        printf("%d\n", toQualityPoints(input));
        scanf("%d", &input);
    }
}

int toQualityPoints(int x) {
    switch (x) {
        case 90 ... 100:
            return 4;
        case 80 ... 89:
            return 3;
        case 70 ... 79:
            return 2;
        case 60 ... 69:
            return 1;
        default:
            return 0;
    }
}