#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    int nums = 0;

    while(scanf("%d", &nums) != EOF) {
        int number[3001] = {0};
        int difference[3001] = {0};

        for (int i = 0; i < nums; i++) {
            scanf("%d", &number[i]);
        }

        for (int i = 0; i < nums - 1; i++) {
            difference[i] = abs(number[i] - number[i + 1]);
        }

        for (int i = 0; i < nums - 1; i++) {
            for (int j = i + 1; j < nums - 1; j++) {
                if (difference[i] > difference[j]) {
                    int temp = difference[i];
                    difference[i] = difference[j];
                    difference[j] = temp;
                }
            }
        }

        bool flag = false;

        for (int i = 0; i < nums - 1; i++) {
            if (difference[i] != i + 1) {
                flag = true;
                break;
            }
        }

        if (flag) {
            printf("Not jolly\n");
        }
        else {
            printf("Jolly\n");
        }
    }
}