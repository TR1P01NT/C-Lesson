#include <stdio.h>
#include <string.h>

int main(void) {
    char line[100] = {0};
    int count = 1;

    while(gets(line)) {
        for(int i = 0; i < strlen(line); i++) {
            if(line[i] == '\"') {
                if(count % 2 == 0) {
                    printf("''");
                }
                else {
                    printf("``");
                }
                count++;
            }
            else {
                printf("%c", line[i]);
            }
        }
    }
}

/*
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int main(){

    char chr;
    bool flag = true;

    while((chr = getchar()) != EOF){
        if(flag && chr == '"'){
            printf("``");
            flag = false;
        }
        else if(!flag && chr == '"'){
            printf("''");
            flag = true;
        }
        else{
            printf("%c", chr);
        }
    }

    return 0;
}
*/