#include <stdio.h>

int main(void) {
    int test;

    scanf("%d", &test);

    for (int i = 0; i < test; i++) {
        int sum, diff;

        scanf("%d %d", &sum, &diff);

        if ((sum <= diff) || ((sum + diff) % 2) != 0 || (diff == 0)) {
            printf("Impossible\n");
            continue;
        }

        printf("%d %d\n", (sum + diff) / 2, (sum - diff) / 2);
    }
}