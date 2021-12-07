#include<stdio.h>

int main(void) {
    int a[100], b[100], i, c[100], j, k = 0, n1 = 10, n2 = 10;

    for (i = 0; i < n1; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < n2; i++)
        scanf("%d", &b[i]);

    for (i = 0; i < n1; i++) {
        for (j = 0;j < k; j++) {
            if (c[j] == a[i]) {
                break;
            }
        }

        if (j == k) {
            c[k] = a[i];
            k++;
        }
    }

    for(i = 0; i < n2; i++) {
        for(j = 0; j < k; j++) {
            if(c[j] == b[i]) {
                break;
            }
        }

        if (j == k) {
            c[k] = b[i];
            k++;
        }
    }

    for(i = 0; i < k; i++) {
        printf("%d ", c[i]);
    }
}
