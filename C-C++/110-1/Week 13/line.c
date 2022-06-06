#include <stdio.h>

int calculate(int *arr);

int main(void) {
    int arr[3][3] = {0};
    int count = 3;
    int new = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ++count;
            scanf("%d", &arr[i][j]);
            if (count == 4) {
                calculate(&arr[i][j]);
                count = 0;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%-3d", arr[i][j]);
            ++new;
            if (new == 3) {
                printf("\n");
                new = 0;
            }
        }
    }
}

int calculate(int *arr) {
    *arr += 2;
    return 0;
}