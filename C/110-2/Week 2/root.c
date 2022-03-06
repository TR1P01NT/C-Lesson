#include <stdio.h>

int main(void) {
    int start = 0, end = 0, count = 0;

    scanf("%d %d", &start, &end);

    while ((start != 0) && (end != 0)) {
        for (int i = start; i <= end; i++) {
            for (int j = 1; j <= i; j++) {
                if (((i / j) == j) && (i % j == 0)) {
                    count++;
                    break;
                }
            }
        }

        printf("%d\n", count);
        count = 0;

        scanf("%d %d", &start, &end);  
    }
}