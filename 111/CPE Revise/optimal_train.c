#include <stdio.h>

int main(void) {
    int testcase = 0;
    int train_length = 0;

    scanf("%d", &testcase);

    for (int i = 0; i < testcase; i++) {
        int train[50] = {0};
        int swap = 0;

        scanf("%d", &train_length);

        for (int j = 0; j < train_length; j++) {
            scanf("%d", &train[j]);
        }

        for (int j = 0; j < train_length; j++) {
            for (int k = j + 1; k < train_length; k++) {
                if (train[j] > train[k]) {
                    int temp = train[j];
                    train[j] = train[k];
                    train[k] = temp;
                    swap++;
                }
            }
        }

        printf("Optimal train swapping takes %d swaps.\n", swap);
    }
}