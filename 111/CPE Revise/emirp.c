#include <stdio.h>

int check_prime(int x) {
    int flag = 0;
    
    for (int i = 2; i <= x / 2; i++) {
        if (x % i == 0) {
            flag = 1;
            break;
        }
    }

    if (flag) {
        return 1;
    }
    else {
        return 0;
    }
}

int reverse(int num) {
    int reversed = 0;

    while (num > 0) {
        int temp = num % 10;
        reversed = (reversed * 10) + temp;
        num /= 10;
    }

    return reversed;
}

int main(void) {
    int num = 0;

    while(scanf("%d", &num) != EOF) {
        int result = check_prime(num);

        if (result) {
            printf("%d is not prime.\n", num);
            continue;
        }

        int reversed = reverse(num);
        int emirp = check_prime(reversed);

        if (emirp) {
            printf("%d is prime.\n", num);
        }
        else {
            printf("%d is emirp.\n", num);
        }
    }
}