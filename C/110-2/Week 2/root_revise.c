#include <stdio.h>

int main(void) {
    int start, end, total = 0;

    while ((scanf("%d %d", &start, &end)) && start != 0 && end != 0) {
        if (start > end) {
            continue;
        }

        int x = 1;
        total = 0;

        while ((x * x) < start) {
            x++;
        }

        for (; x * x <= end; x++) {
            total++;
        }

        printf("%d\n", total);
    }
}