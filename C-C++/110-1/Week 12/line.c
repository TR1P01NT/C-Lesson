#include <stdio.h>
#include <string.h>

void add(char *str, int place);

void deletion(char *str, int place);

void find(char *str);

void output(const char *str);

int main(void) {
    int function, place1, place2;
    char str[1][100], word;

    scanf("%d", &function);

    while(function != -1) {
        switch(function) {
            case 1:
                scanf("%d", &place1);
                add(*str, place1);
                break;
            case 2:
                scanf("%d", &place2);
                deletion(*str, place2);
                break;
            case 3:
                find(*str);
                break;
            case 4:
                output(*str);
                break;
        }

        scanf("%d", &function);
    }

    return 0;
}

void add(char str[], int place) {
    char temp[100], half[100];

    if (place == 0) {
        scanf("%[^\n]", str);
    }

    scanf("%[^\n]", temp);

    strncpy(half, &str[place], strlen(str) - place + 1);

    strcpy(&str[place], temp);

    strcat(&str[place], half);

}

void deletion(char str[], int place) {
    char temp[100];

    strncpy(temp, str, place);

    strcpy(str, temp);
}

void find(char *str) {
    char search[100] = {0}, *x;
    int indx, count = 0;

    scanf("%[^\n]", search);

    x = strstr(str, search);

    indx = strlen(str) - strlen(x);

    if(search[1] != 0) {
        printf("index:%d\n", indx);
    }
}

void output(const char *str) {
    printf("%s\n", str);
}