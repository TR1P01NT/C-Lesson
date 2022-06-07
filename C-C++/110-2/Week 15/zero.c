#include <stdio.h>

int main(void) {
    long long int low, high;

    scanf("%lld %lld", &low, &high);

    while ((low + high) != 0) {
        printf("%lld\n", (high / 5 - low / 5) + 1);
        
        scanf("%lld %lld", &low, &high);
    }
}

/*
    5^0            0! = 1 (include 0!)
    5^0            1! = 1
    5^0            2! = 2
    5^0            3! = 6
    5^0            4! = 24
    5^1            5! = 120
    5^1            6! = 720
    5^1            7! = 5040
    5^1            8! = 40320
    5^1            9! = 362880
    5^2            10! = 3628800

    1 10
    0 0 0 0 0 1 1 1 1 1 2 = 3 types
    (10 / 5) - (1 / 5) + 1 = 3

    1 3
    0 0 0 = 1 type
    (3 / 5) - (1 / 5) + 1 = 0
*/