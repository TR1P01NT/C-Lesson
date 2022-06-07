#include <stdio.h>

unsigned long long int gcd(unsigned long long int x, unsigned long long int y);

int main(void) {
    unsigned long long int v1, d1, v2, d2;
    int testcase = 0;

    scanf("%lld %lld %lld %lld", &v1, &d1, &v2, &d2);

    while ((v1 + d1 + v2 + d2) != 0) {
        unsigned long long int distance = (d1 * v2) + (d2 * v1);
        unsigned long long int average = v1 * v2 * 2;
        unsigned long long int divider = gcd(distance, average);

        distance /= divider;
        average /= divider;

        if (d1 * v2 < d2 * v1) {
            printf("Case #%d: You owe me a beer!\n", ++testcase);
        }
        else {
            printf("Case #%d: No beer for the captain.\n", ++testcase);
        }

        if (average == 1) {
            printf("Avg. arrival time: %lld\n", distance);
        }
        else {
            printf("Avg. arrival time: %lld/%lld\n", distance, average);
        }

        scanf("%lld %lld %lld %lld", &v1, &d1, &v2, &d2);
    }
}

unsigned long long int gcd(unsigned long long int x, unsigned long long int y) {
    if (y != 0) {
        return gcd(y, x % y);
    }
    else {
        return x;
    }
}

/*
    while ((v1 + d1 + v2 + d2) != 0) {
        double t1, t2;

        t1 = (double)d1 / v1;
        t2 = (double)d2 / v2;

        int temp;
        float average;
        int flag = 0;

        average = (t1 + t2) / 2;
        temp = (int)average;

        if (temp == average) {
            flag = 1;
        }

        if (t1 < t2) {
            printf("Case #%d: You owe me a beer!\n", ++testcase);

            if (flag) {
                printf("Avg. arrival time: %d\n", temp);
            }
            else {
                printf("Avg. arrival time: %.0f/%d\n", t1 + t2, 2);
            }
        }
        else {
            printf("Case #%d: No beer for the captain.\n", ++testcase);

            if (flag) {
                printf("Avg. arrival time: %d\n", temp);
            }
            else {
                printf("Avg. arrival time: %.0f/%d\n", t1 + t2, 2);
            }
        }

        scanf("%ld %ld %ld %ld", &v1, &d1, &v2, &d2);
    }
*/