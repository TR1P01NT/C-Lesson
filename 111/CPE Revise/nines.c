#include <stdio.h>
#include <string.h>

int degrees(char *str) {
    int sum = 0;
    int degree = 0;

    if (strlen(str) == 1 && str[0] == '9') {
        return 1;
    }
    
    while (strlen(str) >= 2) {
        sum = 0;
        
        for (int i = 0; i < strlen(str); i++) {
            sum += str[i] - '0';
        }

        if (sum % 9 == 0) {
            degree++;
        }

        sprintf(str, "%d", sum);
    }

    return degree;
}

int main(void) {
    char num[1001] = {0};

    scanf("%s", num);

    while (1) {
        if (num[0] == '0' && strlen(num) == 1) {
            break;
        }
        else {
            printf("%s ", num);

            int degree = degrees(num);

            if (degree) {
                printf("is a multiple of 9 and has 9-degree %d.\n", degree);
            }
            else {
                printf("is not a multiple of 9.\n");
            }
        }
        memset(num, 0, sizeof(num));

        scanf("%s", num);
    }  
}