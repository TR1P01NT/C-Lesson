#include <stdio.h>
#include <string.h>

int main(void) {
    int num = 0, count[26] = {0}, n = 0, i = 0, x = 0, arranged[100] = {0}, letter[100] = {0}, j = 0;

    scanf("%d", &num);

    char str[1000]; 

    for (int i = 0; i <= num; i++) {
        gets(str);

        while (str[n] != '\0') {
            if (str[n] >= 'a' && str[n] <= 'z') {
                x = str[n] - 'a';
                count[x]++;
            }
            else if (str[n] >= 'A' && str[n] <= 'Z') {
                x = str[n] - 'A';
                count[x]++;
            }
            n++;
        }

        n = 0;
    }

    for (int i = 0; i < 26; i++) {
        int temp = 0;
        for (int j = 0; j < 26; j++) {
            if (count[j] > arranged[i]) {
                arranged[i] = count[j];

                letter[i] = j;
            }
        }
        int spec = letter[i];
        count[spec] = 0;
    }

    for(int i = 0; i < 26; i++) {
        if (arranged[i] != 0) {
            printf("%c %d\n", letter[i] + 65, arranged[i]);
        }
    }
}