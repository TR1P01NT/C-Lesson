#include <stdio.h>
#include <ctype.h>

/*
    cannot detect expression error yet
    (1+) -> 1+
*/

//cannot count the sum yet

char stack[100];
int top = -1;

void push(char x) { 
    stack[++top] = x;
}

char pop() {
    if (top == -1) {
        return -1;
    }
    else {
        return stack[top--];
    }
}

int arrange_operator(char x) {
    if (x == '+' || x == '-') {
        return 1;
    }
    else if (x == '*' || x == '/') {
        return 2;
    }
    else if (x == '^') {
        return 3;
    }
    else {
        return 0;
    }
}

int main(void) {
    char line[100];
    char x;
    

    while (scanf("%s", line) != EOF) {
        char *chr = line;

        while (*chr != '\0') {
            if (isalnum(*chr)) {
                printf("%c", *chr);
            }
            else if (*chr == '(') {
                push(*chr);
            }
            else if (*chr == ')') {
                while ((x = pop()) != '(') {
                    printf("%c", x);
                }
            }
            else {
                while (arrange_operator(stack[top]) >= arrange_operator(*chr)) {
                    printf("%c", pop());
                }
                push(*chr);
            }
            chr++;
        }

        while (top != -1) {
            printf("%c", pop());
        }
        printf("\n");
    }
}