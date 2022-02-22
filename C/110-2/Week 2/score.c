#include <stdio.h>

int main(void) {
    int test = 0;

    scanf("%d", &test);

    for(int i = 0; i < test; i++) {
        int sum = 0, diff = 0;
        int s1 = 0, s2 = 0;
        int temp = 0;

        scanf("%d %d", &sum, &diff);

        for(int i = 0; i < 100; i++, s1 += 1, s2 += 1) {
            int t1 = s1, t2 = s2;
            t1 += diff;
            temp = t1 + t2;

            if (temp == sum) {
                printf("%d %d\n", t1, t2);
                break;
            }
            if (i == 99) {
                printf("Impossible\n");
                break;
            }
        }
    }
}