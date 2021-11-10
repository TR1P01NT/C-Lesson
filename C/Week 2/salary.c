#include<stdio.h>
#include<stdlib.h>

int main() {
    int hours = 0, exhours;
    float salary = 0.0, exsalary = 0, total;

    scanf("%d", &hours);

    while (hours != -1) {
        scanf("%f", &salary);

        if (hours > 40) {
            exhours = hours - 40;
            exsalary = salary * 1.5;
            exsalary = exsalary * exhours;
            hours = hours - exhours;
        }

        total = (salary * hours) + exsalary;

        printf("Salary is $%.2f\n", total);

        scanf("%d", &hours);
    }

    return 0;
    
}