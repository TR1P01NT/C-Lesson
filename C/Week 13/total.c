#include <stdio.h>
#include <string.h>

int sum(int * const ptr, int num);

int main(void) {
    int num[100] = {0};
    int temp;
    int total = 0, i = 0;

    scanf("%d", &temp);

    while(temp != -9999) {
        num[i] = temp;
        i++;
        scanf("%d", &temp);
    }

    total = sum(&num[0], i);

    printf("%d\n", total);
}

int sum(int * const ptr, int num) {
    int total = 0;

    for (int i = 0; i < num; i++) {
        total += ptr[i];
    }

    return total;
}