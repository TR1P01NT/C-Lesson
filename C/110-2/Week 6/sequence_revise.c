#include <stdio.h>
#include <stdlib.h>

int check(int num[], int i, int sum, const int *sequence, const int *divider) {
    if (i == *sequence) {
        return (abs(sum)% *divider);
    }

    if (check(num, i + 1, sum + num[i], sequence, divider) == 0) {
        return 0;
    }
    if (check(num, i + 1, sum - num[i], sequence, divider) == 0) {
        return 0;
    }

    return 1;
}

int main(void) {
    int num[100];
    int testcase;

    scanf("%d", &testcase);

    while (testcase--) {
        int sequence, divider;
        scanf("%d %d", &sequence, &divider);

        for (int i = 0; i < sequence; i++) {
            scanf("%d", &num[i]);
        }

        if (check(num, 0, 0, &sequence, &divider) == 0) {
            printf("Divisible\n");
        }
        else {
            printf("Not divisible\n");
        }
    }
}