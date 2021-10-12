#include <stdio.h>

int main(void) {
    int count, scannum, totalnum, total;
    int array[1000];
    int i = 0, j = 0;
    int average;

    scanf("%d", &count);

    for(scannum = 0; scannum < count; ++scannum) {
        scanf("%d", &array[i]);
        ++i;
    }

    for(totalnum = 0; totalnum < count; ++totalnum) {
        total += array[j];
        ++j;
    }

    average = total / count;

    printf("Average: %d\n", average);
}