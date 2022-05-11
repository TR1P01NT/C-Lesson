#include <stdio.h>

int main(void) {
    int h1, m1, h2, m2;
    int time;

    while ((scanf("%d %d %d %d", &h1, &m1, &h2, &m2)) && (h1 + h2 + m1 + m2 != 0)) {
        time = (h2 - h1) * 60 + (m2 - m1);
        if (time < 0) {
            time = 24 * 60 + time;
        }

        printf("%d\n", time);
    }
}