#include <stdio.h>

int main(void) {
    int count, num;
    double sum1, sum2, sum3, sum4, sum5, total;

    scanf("%d %d", &num, &count);

    while (num != -1 && count != -1) {
        switch (num) {
            case 1:
                sum1 = count * 2.98;
            case 2:
                sum2 = count * 4.50;
            case 3:
                sum3 = count * 9.98;
            case 4:
                sum4 = count * 4.49;
            case 5:
                sum5 = count * 6.87;
        }

        scanf("%d %d", &num, &count);
    }
    
    total = sum1 + sum2 + sum3 + sum4 + sum5;

    printf("%.2lf\n", total);

    return 0;
}