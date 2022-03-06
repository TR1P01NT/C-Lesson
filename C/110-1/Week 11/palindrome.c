#include <stdio.h>
#include <string.h>
#include <ctype.h>

int testPalindrome(char str[], int left, int right);
void clear(char str[]);

int main(void) {
    char str[100], c;
    int palindrome;
    
    while ((gets(str)) != NULL) {
        clear(str);
        palindrome = testPalindrome(str, 0, strlen(str) - 1);
        if (palindrome == 1) {
            printf("True\n");
        } 
        else {
            printf("False\n");
        }
    }
}

void clear(char line[]) {
    for (int i = 0, j; line[i] != '\0'; ++i) {

    while (!(line[i] >= 'a' && line[i] <= 'z') && !(line[i] >= 'A' && line[i] <= 'Z') && !(line[i] == '\0')) {
        for (j = i; line[j] != '\0'; ++j) {
            line[j] = line[j + 1];
        }
        line[j] = '\0';
        }
    }
}

int testPalindrome(char str[], int left, int right) {
    if(left >= right) {
        return 1;
    }

    if(str[left] == str[right]) {
        return testPalindrome(str, left + 1, right - 1);
    }

    return 0;
}

// int testPalindrome(char str[]) {
//     int i, j, len;
//     len = strlen(str);
//     for (i = 0, j = len - 1; i < j; i++, j--) {
//         if (!isalnum (str[j])) {
//             j--;
//             continue;
//         }
//         if (!isalnum (str[i])) {
//             i++;
//             continue;
//         }
//         if (str[i] != str[j]) {
//             return 0;
//         }
//     }
//     return 1;
// }