#include <stdio.h>

int encrypt(int);

int main(void) {
    int num;

    scanf("%d", &num);

    while (num >= 1000 && num < 10000) {
        printf("%04d", encrypt(num));
        printf("\n");

        scanf("%d", &num);
    }

    if (num == -1) {
        return 0;
    }
}

int encrypt(num) {
    int array[4];
    int i;

    array[0] = (num / 1000); // first digit

    array[1] = ((num / 100) % 10); //second digit

    array[2] = ((num / 10) % 10); // third digit

    array[3] = (num % 10); // fourth digit

    for(i = 0; i < 4; i++) {
        array[i] = (array[i] + 7) % 10;
    }

    return (array[2] * 1000) + (array[3] * 100) + (array[0] * 10) + (array[1]);
}