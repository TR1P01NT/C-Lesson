#include <stdio.h>

int main(void) {
    int n1 = 0, n2 = 0;

    scanf("%d %d", &n1, &n2);

    while ((n1 != 0) && (n2 != 0)) {
        int max = 0;

        for(int i = n1; i <= n2; i++) {
            int count = 0;

            if (i == 1) {
                count++;
            }

            int temp = i;

            while(temp != 1) {
                if (temp % 2 == 0) {
                    temp /= 2;
                    count++;
                }
                else {
                    temp = temp * 3 + 1;
                    count++;
                }
            }
            count++;
            
            if (count > max) {
                max = count;
            }
        }
        printf("%d %d %d\n", n1, n2, max);

        scanf("%d %d", &n1, &n2);
    }
}