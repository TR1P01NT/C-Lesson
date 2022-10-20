#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//algebra

int main(void) {
    int num[100];
    char calc[100], line[100], answer[100];

    int i, j, k, mark;

    while(gets(line) != NULL) {
        j = 0;
        memset(calc, '\0', sizeof(calc));
        memset(num, 0, sizeof(num));

        for (i = 0; i < strlen(line); i++) {
            num[j] = atoi(&line[i]);

            while (line[i] == ' ' || line[i] == '-' || line[i] == '+') {
                i++;
            }
            while (isdigit(line[i]) || line[i] == ' ') {
                i++;
            }

            calc[j] = line[i];
            j++;

            if (line[i] == '=') {
                while (line[i + 1] == ' ') {
                    i++;
                }
                strcpy(answer, &line[i + 1]);
                break;
            }
        }

        for (k = 0; k < strlen(calc); k++) {
            printf("%d %c ", num[k], calc[k]);
        }
        puts(answer);

        while (1) {
            mark = 1;

            if (calc[0] == '=') {
                break;
            }

            for (i = 0; i < strlen(calc); i++) {
                if (calc[i] == '*' || calc[i] == '/') {
                    if (calc[i] == '*') {
                        num[i] = num[i] * num[i + 1];
                    } 
                    else {
                        num[i] = num[i] / num[i + 1];
                    }

                    for (k = i + 2; k < strlen(calc); k++) {
                        num[k - 1] = num[k];
                    }

                    strcpy(&calc[i], &calc[i + 1]);
                    
                    for (k = 0; k < strlen(calc); k++) {
                        printf("%d %c ", num[k], calc[k]);
                    }

                    puts(answer);
                    mark = 0;
                    break;
                }
            }

            if (!mark) {
                continue;
            }
            
            for (i = 0; i < strlen(calc); i++) {
                if (calc[i] == '+' || calc[i] == '-') {
                    if (calc[i] == '+') {
                        num[i] = num[i] + num[i + 1];
                    }
                    else {
                        num[i] = num[i] - num[i + 1];
                    }

                    for (k = i + 2; k < strlen(calc); k++) {
                        num[k - 1] = num[k];
                    }

                    strcpy(&calc[i], &calc[i + 1]);

                    for (k = 0; k < strlen(calc); k++) {
                        printf("%d %c ", num[k], calc[k]);
                    }

                    puts(answer);
                    break;
                }
            }
        }
        printf("\n");
    }
}
