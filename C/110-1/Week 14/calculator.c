#include <stdio.h>

void add(double a, double b);
void subtract(double a, double b);
void multiply(double a, double b);
void divide(double a, double b);

int main(void) {             
    double num1 = 0, num2 = 0;                
    void (*f[4])(double, double) = {add, subtract, multiply, divide};   

    scanf("%lf %lf", &num1, &num2); 

    int choice = 0;
    scanf("%u", &choice);

    while (choice >= 0 && choice < 4) {                            
        (*f[choice])(num1, num2);                                

        scanf("%u", &choice);
    } 

    puts("Program execution completed.");
} 

void add(double a, double b) {
    printf("%.1f\n", a + b);
}

void subtract(double a, double b) {
    printf("%.1f\n", a - b);
}

void multiply(double a, double b) {
    printf("%.1f\n", a * b);
}

void divide(double a, double b) {
    printf("%.1f\n", a / b);
}