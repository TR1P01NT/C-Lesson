#include <stdio.h>
#include <string.h>

int main(void) {
    char a[1001] = {0};
    char b[1001] = {0};

    while (gets(a) && gets(b)) {
        int tableA[26] = {0};
        int tableB[26] = {0};

        for (int i = 0; i < strlen(a); i++) {
            if (a[i] >= 'a' && a[i] <= 'z') {
                if (tableA[a[i] - 'a']) {
                    continue;
                }
                else {
                    tableA[a[i] - 'a'] = 1;
                }
            }
        }

        for (int i = 0; i < strlen(b); i++) {
            if (b[i] >= 'a' && b[i] <= 'z') {
                if (tableB[b[i] - 'a']) {
                    continue;
                }
                else {
                    tableB[b[i] - 'a'] = 1;
                }
            }
        }

        for (int i = 0; i < 26; i++) {
            if(tableA[i] && tableB[i]) {
                printf("%c", i + 'a');
            }
        }

        printf("\n");
    }
}