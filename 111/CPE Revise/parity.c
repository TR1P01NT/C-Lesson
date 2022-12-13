#include <stdio.h>
#include <string.h>

int main(void) {
    int num = 0;

    scanf("%d", &num);

    while (num != 0) {
        char binary_num[100] = {0};
        int ten_num = num;
        int count = 0;
        int one_count = 0;

        while (ten_num > 0) {
            if (ten_num % 2 == 0) {
                binary_num[count] = '0';
            }
            else {
                binary_num[count] = '1';
                one_count++;
            }
            count++;
            ten_num /= 2;
        }

        printf("The parity of ");
        for (int i = strlen(binary_num); i >= 0; i--) {
            printf("%c", binary_num[i]);
        }
        printf(" is %d (mod 2).\n", one_count);

        scanf("%d", &num);
    }
}