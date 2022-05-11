#include <stdio.h>

int main(void) {
    int h1, h2, m1, m2, total = 0;

    scanf("%d %d %d %d", &h1, &m1, &h2, &m2);

    while (1) {
        if ((h1 == 0) && (h2 == 0) && (m1 == 0) && (m2 == 0)) {
            break;
        }
        else if ((h1 != h2) && (m1 == m2)) {
            if (h1 > h2) {
                total = ((h2 + 24) * 60) - (h1 * 60);
            }
            else {
                total = (h2 - h1) * 60;
            }
        }
        else if ((h1 == 0) && (h2 == 0)) {
            total = m2 - m1;
        }
        else if (h2 == 0) {
            total = ((24 * 60) + m2) - ((h1 * 60) + m1);

        }
        else if (h1 == h2) {
            if (m1 > m2) {
                total = ((h2 + 24) * 60) + m2 - (h1 * 60) - m1; 
            }
            else {
                total = m2 - m1;
            }
            
        }
        else {
            total = ((h2 * 60) + m2) - ((h1 * 60) + m1);
        }

        printf("%d\n", total);
        scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
    }
}