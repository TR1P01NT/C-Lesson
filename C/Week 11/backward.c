#include <stdio.h>
#include <string.h>

void stringReverse(char str[], int len);

int main(void) {
    char str[100];
    
    while ((gets(str)) != NULL) {
        int len = strlen(str);
        stringReverse(str, len);
        printf("%s\n", str);
    }
}

void stringReverse(char str[], int len) {
    if (len <= 1 ) {
        return ;
    }
    else {
        int temp;
        int i = 0;

        temp = str[i];
        str[i]= str[len-1];
        str[len - 1] = temp;
        stringReverse(&str[1], len - 2);
    }
}