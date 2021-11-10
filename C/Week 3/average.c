#include <stdio.h>

int main(void) {
    int count, i, total = 0, average, number;

    scanf("%d", &count);

    for(i = 0; i < count; i++) {
        scanf("%d", &number);
        total = total + number;
    }

    average = total / count;

    printf("Average: %d\n", average);
}