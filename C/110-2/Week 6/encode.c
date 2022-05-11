#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    int test = 0;
    char str[50][200] = {0};
    char decode[50][200] = {0};
    int count = 0;

    scanf("%d", &test);

    for (int i = 0; i < test; i++) {
        scanf("%s", str[i]);

        for (int j = 1; j < strlen(str[i]); j+=2) {
            int num = strtol(&str[i][j], NULL, 10);

            int len = strlen(decode[i]);

            for (int k = 0; k < num; k++) {
                decode[i][len + k] = str[i][j - 1];
            }
        }

        printf("%s\n", decode[i]);
    }
}