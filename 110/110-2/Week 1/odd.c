#include <stdio.h>

int main(void) {
    int num = 0, n1 = 0, n2 = 0;

    scanf("%d", &num);

    int test[num];

    for (int i = 0; i < num; i++) {
        test[i] = 0;
    }

    for (int i = 0; i < num; i++) {
        scanf("%d %d", &n1, &n2);

        for(int j = n1; j <= n2; j++) {
            if (j % 2 != 0) {
                test[i] += j;
            }
        }

        printf("Case %d: %d\n", i + 1, test[i]);
    }
}