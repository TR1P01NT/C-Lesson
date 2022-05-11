#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    int line;
    int count[26] = {0};
    char str[1000];

    scanf("%d", &line);

    fgets(str, 1000, stdin);

    for (int i = 0; i < line; i++) {
        fgets(str, 1000, stdin);

        int len = strlen(str) - 1;

        for (int j = 0; j < len; j++) {
            if (!isalpha(str[j])) {
                continue;
            }
            str[j] = toupper(str[j]);
            count[str[j] - 'A' + 1]++;
        }
    }

    int max;
    count[0] = 0;

    while (1) {
        max = 0;

        for (int i = 1; i <= 26; i++) {
            if (count[max] >= count[i]) {
                continue;
            }
            max = i;
        }

        if (0 == max) {
            break;
        }

        printf("%c %d\n", max + 'A' - 1, count[max]);
        count[max] = 0;
    }
}