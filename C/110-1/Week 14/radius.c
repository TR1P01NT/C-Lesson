#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846264338327950288

void function1(double a);
void function2(double b);
void function3(double c);

int main(void)
{             
    int num = 0;                
    void (*f[3])(double) = {function1, function2, function3};   

    scanf("%d", &num); 

    int choice = 0;
    scanf("%u", &choice);

    while (choice >= 0 && choice < 3) {                            
        (*f[choice])(num);                                

        scanf("%u", &choice);
    } 

    puts("Program execution completed.");
} 

void function1(double a)
{
    printf("%d\n", ((int)(2 * M_PI * a)));
}

void function2(double b)
{
    printf("%d\n", ((int)(b * b * M_PI)));
}

void function3(double c)
{
    printf("%d\n", ((int)(4 * M_PI * c * c * c / 3)));
}
