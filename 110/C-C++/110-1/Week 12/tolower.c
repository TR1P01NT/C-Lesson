#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toLower(char *str);

int main(void) {
    char str[100];

    while((gets(str)) != NULL) {
        toLower(&str[0]);
        puts(str);
    }
}

void toLower(char *str) {
    for(int i = 0;i <= strlen(str); i++) {
      if(str[i] >= 65 && str[i] <= 90) {
            str[i] = str[i] + 32;
      }
   }
}