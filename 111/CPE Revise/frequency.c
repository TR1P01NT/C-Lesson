#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void) {
    char str[1024] = {0};
    bool flag = false;

    while (gets(str)) {
        int count[128] = {0};

        if (flag) {
            printf("\n");
        }

        flag = true;

        for (int i = 0; i < strlen(str); i++) {
            count[str[i]]++;
        }

        for (int i = 1; i <= strlen(str); i++) {
            for (int j = 127; j >= 32; j--) {
                if (count[j] == i) {
                    printf("%d %d\n", j, count[j]);
                }
            }
        }
    }
}