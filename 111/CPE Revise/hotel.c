#include <stdio.h>

int main(void) {
    long long group = 0;
    long long day = 0;

    while(scanf("%lld %lld", &group, &day) != EOF) {
        long long num = group;

        while(num < day) {
            group++;
            num += group;
        }

        printf("%lld\n", group);
    }
}