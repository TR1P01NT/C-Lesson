#include <stdio.h>

double triangle (double x, double y, double z);
double total (double x, double y, double z);

int main(void) {
    double a, b, c;
    int chr;

    scanf("%lf %lf %lf", &a, &b, &c);

    while ((chr = getchar()) != EOF) {
        if (triangle(a, b, c)) {
            printf("%.2lf\n", total(a, b, c));
        }
        else {
            printf("False\n");
        }

        scanf("%lf %lf %lf", &a, &b, &c);
    }
}

double triangle (double x, double y, double z) {
    if ((x + y) > z && (x + z) > y && (y + z) > x) {
        return 1;
    }
    else {
        return 0;
    }
}

double total (double x, double y, double z) {
    double sum = x + y + z;
    return sum;
}