#include <stdio.h>
#include <math.h>

int main(void) {
    int a, b, c;

    for (c = 1; c < 500; ++c) {
        for (b = c + 1; b < 500; ++b) {
            for (a = 1; a <= 500; ++a) {
                if (pow(a, 2) == (pow(b, 2) + pow(c, 2))) {
                    printf("%d %d %d\n", c, b, a);
                }
            }
        }
    }
}