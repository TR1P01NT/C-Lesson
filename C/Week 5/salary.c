#include <stdio.h>

int main() {
    int code, count;
    double hours, salary, sales;

    scanf("%d", &code);

    while (code != -1) {
        switch (code) {
            case 1:
                scanf("%lf", &salary);
                printf("%.2lf\n", salary);
                break;
            case 2:
                scanf("%lf", &salary);
                scanf("%lf", &hours);
                printf("%.2lf\n", (hours > 40 ? (salary * 40) + (salary * (hours - 40) * 1.5) : (salary * hours)));
                break;
            case 3:
                scanf("%lf", &sales);
                printf("%.2lf\n", 250 + (sales * 0.057));
                break;
            case 4:
                scanf("%d", &count);
                scanf("%lf", &salary);
                printf("%.2lf\n", count * salary);
                break;
            default:
                puts("Wrong pay code");
        }

        scanf("%d", &code);
    }

    return 0;
}