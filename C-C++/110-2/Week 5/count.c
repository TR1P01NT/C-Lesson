#include <stdio.h>
#include <string.h>

void clear(char line[]);

int main(void) {
    char line[10][100] = {0}, input[100] = {0};
    int count = 0, num[10] = {0};

    for (int i = 0; (gets(input)) != NULL; i++) {
        strcpy(line[i], input);
        clear(line[i]);
        int flag = 1;
        if (line[i][0] != ' ') {
            flag = 0;
        }
        for (int j = 0; j < strlen(input); j++) {
                if (line[i][j] != ' ') {
                    if(!flag) num[i]++;
                    flag = 1;
                }
                else{
                    flag = 0;
                }
            }

        printf("%d\n", num[i]);
    }
}

void clear(char line[]) {
    for (int i = 0, j; line[i] != '\0'; ++i) {

        while (!(line[i] >= 'a' && line[i] <= 'z') && !(line[i] >= 'A' && line[i] <= 'Z') && !(line[i] == '\0') && !(line[i] == ' ')) {
            line[i] = ' ';
            }
    }
}