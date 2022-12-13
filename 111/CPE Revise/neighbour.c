#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y) {
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

void find_sum(int *houses, int count, int median) {
    int sum = 0;

    for (int i = 0; i < count; i++) {
        sum += abs(median - houses[i]);
    }

    printf("%d\n", sum);
}

void bubble_sort(int *houses, int count) {
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count - i -1; j++) {
            if (houses[j] > houses[j + 1]) {
                swap(&houses[j], &houses[j + 1]);
            }
        }
    }

    find_sum(houses, count, houses[count/2]);
}

int main(void) {
    int testcase = 0;
    int count = 0;

    scanf("%d", &testcase);

    for (int i = 0; i < testcase; i++) {
        int house[500] = {0};       
        scanf("%d", &count);

        for (int j = 0; j < count; j++) {
            scanf("%d", &house[j]);
        }
        
        bubble_sort(house, count);
    }
}