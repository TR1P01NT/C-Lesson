#include <stdio.h>

int main(void) {
    int count = 1;
    double hours, service = 0.50, total = 0, fee = 0;

    do {
        scanf("%lf", &hours);

        fee += (hours * service);

        if (hours >= 24) {
            do {
                hours -= 24;
                fee += 50;
            } while (hours >= 24);

            if (hours > 0 && hours < 24) {
                fee += 50;
            }
        }
        else {
            if (hours <= 8) {
                fee += 25;
            }
            else if (hours <= 23) {
                fee += 50;
            }
        }

        printf("%.2lf\n", fee);

        total += fee;
        ++count;

        fee = 0;

    } while (count <= 3);

    printf("%.2lf\n", total);

    return 0;
}