#include<stdio.h>
#include<stdlib.h>

int main() {
    int hours, exhours;
    float salary, exsalary, total;

    while (hours != EOF) {
        scanf("%d", &hours);

        if (hours == -1) {
            exit(0);
        }

        scanf("%f", &salary);

        if (hours > 40) {
            exhours = hours - 40;
            exsalary = salary * 1.5;
            exsalary = exsalary * exhours;
            hours = 40;
            salary = salary * hours;
            total = salary + exsalary;

            printf("Salary is $%.2f\n", total);
        }

        else {
            total = salary * hours;

            printf("Salary is $%.2f\n", total);
        }
    }

    return 0;
    
}