#include <stdio.h>
#include <string.h>

int main(void) {
    int testcase;
    int i, j, k;
    char str[1000];

    scanf("%d", &testcase);

    for (i = 0; i < testcase; i++) {
        scanf("%s", str);

        int length = strlen(str);

        while (length == 0) {
            scanf("%s", str);
        }

        for (j = 1; j < length; j++) {
            for (k = 0; k + j < length; k++) {
                if (str[k] != str[j + k]) {
                    break;
                }
            }
            if ((j + k) == length) {
                break;
            }
        }

        if ((length % j) != 0) {
            printf("%d\n", length);
        }
        else {
            printf("%d\n", j);
        }
    }
}