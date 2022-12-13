#include <stdio.h>

int main(void) {
    int testcase = 0;
    int test = 1;

    scanf("%d", &testcase);

    while (testcase--) {
        int a, b;

        scanf("%d", &a);
        scanf("%d", &b);

        int sum = 0;

        printf("Case %d: ", test);

        for (int i = a; i <= b; i++) {
            if(i % 2 != 0) {
                sum += i;
            }
        }

        printf("%d\n", sum);
        test++;
    }
}