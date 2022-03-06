#include <stdio.h>
#include <string.h>

int main(void) {
    int line = 0, count = 0, flags = 0;
    char country[2000][76] = {0}, other[1000] = {0}, temp[76] = {0};

    scanf("%d", &line);

    for (int i = 0; i < line; i++) {
        scanf("%s", country[i]);
        gets(other);
        if (other[70] != '\0') {
            memset(country[i], 0, sizeof(country[i]));
            i--;
            memset(other, 0, sizeof(other));
        }
    }

    for (int i = 0; i < line - 1; i++) {
        for (int j = 0; j < line - 1 - i; j++) {
            if (strcmp(country[j], country[j + 1]) > 0) {
                strcpy(temp, country[j]);
                strcpy(country[j], country[j + 1]);
                strcpy(country[j + 1], temp);
            }
        }
    }

    int x = 0;

    while(x < line) {
        if (!flags) {
            printf("%s ", country[x]);
            count++;
            flags = 1;
        } 
        else if (flags) {
            if (strcmp(country[x], country[x + 1]) == 0) {
                count++;
            }
        else {
            printf("%d\n", count);
            flags = 0;
            count = 0;
        }
        x++;
        }
    }
}