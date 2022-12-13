#include <stdio.h>
#include <string.h>

int main(void) {
    int testcase = 0;
    char str[1000] = {0};
    int count[128] = {0};

    scanf("%d", &testcase);
    getchar();

    while (testcase--) {
        gets(str);
        for (int i = 0; i < strlen(str); i++) {
            if (str[i] >= 'a' && str[i] <= 'z') {
                count[str[i] - 'a' + 'A']++;
            }
            else {
                count[str[i]]++;
            } 
        }
    }

    for (int i = sizeof(str); i >= 1; i--) {
        for (int j = 'A'; j <= 'Z'; j++) {
            if(count[j] == i) {
                printf("%c %d\n", j, count[j]);
            }
        }
    }
}