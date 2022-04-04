#include <stdio.h>
#include <string.h>

int main(void) {
    char text[31] = {0};
    int count = 0, hyphens = 0;

    while((scanf("%s", text)) != EOF) {
        for (int i = 0; i < strlen(text); i++) {
            switch(text[i]) {
                case '-':
                    hyphens++;
                    break;
                case 'A':
                case 'B':
                case 'C':
                    count++;
                    text[i] = '2';
                    break;
                case 'D':
                case 'E':
                case 'F':
                    count++;
                    text[i] = '3';
                    break;
                case 'G':
                case 'H':
                case 'I':
                    count++;
                    text[i] = '4';
                    break;
                case 'J':
                case 'K':
                case 'L':
                    count++;
                    text[i] = '5';
                    break;
                case 'M':
                case 'N':
                case 'O':
                    count++;
                    text[i] = '6';
                    break;
                case 'P':
                case 'Q':
                case 'R':
                case 'S':
                    count++;
                    text[i] = '7';
                    break;
                case 'T':
                case 'U':
                case 'V':
                    count++;
                    text[i] = '8';
                    break;
                case 'W':
                case 'X':
                case 'Y':
                case 'Z':
                    count++;
                    text[i] = '9';
                    break;
            }
        }
        printf("%s %d %d\n", text, count, hyphens);
        count = 0;
        hyphens = 0;
    }
    
}