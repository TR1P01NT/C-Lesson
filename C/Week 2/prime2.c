#include <stdio.h>

void checkPrimeNumber();

int main(void){
    checkPrimeNumber(); 
}

void checkPrimeNumber() {
    int n, i, flag = 0;

    scanf("%d", &n);

    for (i = 2; i <= n/2; i++) {
        if (n % i == 0){
            flag = 1;
        }
    }

    if (flag == 1) {
        printf("%d is not a prime number.", n);
    }

    else {
        printf("%d is a prime number.", n);
    }
}