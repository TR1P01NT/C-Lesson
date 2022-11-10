#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

typedef struct stack {
    int top;
    char data[MAX];
} stack;

typedef struct num {
    int top;
    int data[MAX];
} num;

stack expression;

void push_num(num *s, int c) {
    if (s->top == MAX - 1) {
        printf("Stack is full");
    } else {
        s->top++;
        s->data[s->top] = c;
    }
}

int pop_num(num *s) {
    int c;
    if (s->top == -1) {
        printf("Stack is empty");
    } else {
        c = s->data[s->top];
        s->top--;
    }
    return c;
}

void push(stack *s, char c) {
    if (s->top == MAX - 1) {
        printf("Stack is full.\n");
    }
    else {
        s->top++;
        s->data[s->top] = c;
    }
}

char pop(stack *s) {
    if (s->top == -1) {
        printf("Stack is empty.\n");
        return -1;
    }
    else {
        char c = s->data[s->top];
        s->top--;
        return c;
    }
}

int isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
        return 1;
    }
    else {
        return 0;
    }
}

int precedence(char c) {
    if (c == '^') {
        return 3;
    } 
    else if (c == '*' || c == '/') {
        return 2;
    } 
    else if (c == '+' || c == '-') {
        return 1;
    } 
    else {
        return 0;
    }
}

int isBalanced(char *exp) {
    stack s;
    s.top = -1;

    int i;
    int parenthesis = 0;

    for (i = 0; i < strlen(exp); i++) {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            push(&s, exp[i]);
            parenthesis++;
        } 
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            parenthesis++;

            if (s.top == -1) {
                return 0;
            } 
            else {
                char c = pop(&s);
                if (c == '(' && exp[i] != ')') {
                    return 0;
                } 
                else if (c == '[' && exp[i] != ']') {
                    return 0;
                } 
                else if (c == '{' && exp[i] != '}') {
                    return 0;
                }
            }
        }
        else if (isdigit(exp[i])) {
            continue;
        }
        else if (isOperator(exp[i])) {
            continue;
        }
        else {
            return 3;
        }
    }

    if (s.top == -1 && parenthesis == 0) {
        return 2;
    } 
    else if (s.top == -1) {
        return 1;
    } 
    else {
        return 0;
    }
}

int isCorrect(char *exp) {
    stack s;
    s.top = -1;

    int i;

    for (i = 0; i < strlen(exp); i++) {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            push(&s, exp[i]);
            // check if the previous parenthesis is smaller than the current
            if (s.top > 0) {
                if (s.data[s.top] == '(' && s.data[s.top - 1] != '{' && s.data[s.top - 1] != '[') {
                    if (s.data[s.top - 1] == '(') {
                        continue;
                    }
                    return 0;
                } 
                else if (s.data[s.top] == '[' && s.data[s.top - 1] != '{') {
                    if (s.data[s.top - 1] == '[') {
                        continue;
                    }
                    return 0;
                } 
                else if (s.data[s.top] == '{') {
                    if (s.data[s.top - 1] == '{') {
                        continue;
                    }
                    return 0;
                }
            }
        } 
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            if (s.top == -1) {
                return 0;
            } 
            else {
                char c = pop(&s);
                if (c == '(' && exp[i] != ')') {
                    return 0;
                } 
                else if (c == '[' && exp[i] != ']') {
                    return 0;
                } 
                else if (c == '{' && exp[i] != '}') {
                    return 0;
                }
            }
        }
    }

    if (s.top == -1) {
        return 1;
    } 
    else {
        return 0;
    }
}

int calculate(int len) {
    num s;
    s.top = -1;

    int i;
    int c = 0;

    for (i = 0; i < len; i++) {
        if (isdigit(expression.data[i])) {
            push_num(&s, expression.data[i] - '0');
        } 
        else if (isOperator(expression.data[i])) {
            int a = pop_num(&s);
            int b = pop_num(&s);
            if (expression.data[i] == '+') {
                c = b + a;
                push_num(&s, c);
            } 
            else if (expression.data[i] == '-') {
                c = b - a;
                push_num(&s, c);
            } 
            else if (expression.data[i] == '*') {
                c = b * a;
                push_num(&s, c);
            }
            else if (expression.data[i] == '/') {
                c = b / a;
                push_num(&s, c);
            } 
            else if (expression.data[i] == '^') {
                c = pow(b, a);
                push_num(&s, c);
            }
        }
        else if (expression.data[i] == '(') {
            int temp = 0;
            int j;
            for (j = i + 1; j < len; j++) {
                if (isdigit(expression.data[j])) {
                    temp = temp * 10 + (expression.data[j] - '0');
                } 
                else if (expression.data[j] == ')') {
                    push_num(&s, temp);
                    i = j;
                    break;
                }
            }
        }
    }
    return pop_num(&s);
}

int main() {
    char exp[MAX];
    printf("Infix expression: ");
    scanf("%s", exp);

    if (isBalanced(exp) == 1) {
        printf("The parenthesis is balanced and are all in pairs.\n");

        if (isCorrect(exp)) {
            printf("The order of parenthesis is correct.\n");
        } 
        else {
            printf("ERROR\n");
            printf("The order of parenthesis is incorrect.\n");
            printf("This means that () might get placed by outside of [] and such.\n");
            return 0;
        }
    } 
    else if (isBalanced(exp) == 2) {
        printf("There is no parenthesis in the expression.\n");
    }
    else if (isBalanced(exp) == 3) {
        printf("ERROR\n");
        printf("The expression is incorrect.\n");
        printf("There might be characters that are not supposed to be in the expression.\n");
        return 0;
    }
    else {
        printf("ERROR\n");
        printf("The parenthesis is not balanced.\n");
        printf("This means that not all parenthesis are in pairs.\n");
        return 0;
    }

    stack s;
    s.top = -1;
    expression.top = -1;

    int i;
    int length = 0;
    int operand_count = 0;
    int operator_count = 0;
    char current;

    printf("Postfix expression: ");

    for (i = 0; i < strlen(exp); i++) {
        if (isdigit(exp[i])) {
            if (isdigit(exp[i + 1])) {
                printf("(");
                push(&expression, '(');
                length++;

                while (isdigit(exp[i])) {
                    printf("%c", exp[i]);
                    push(&expression, exp[i]);
                    i++;
                    length++;
                }
                i--;
                printf(")");
                push(&expression, ')');
                length++;
                operand_count++;
            }
            else {
                printf("%c", exp[i]);
                push(&expression, exp[i]);
                length++;
                operand_count++;
            }
        } 
        else if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            push(&s, exp[i]);
        } 
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            while (s.data[s.top] != '(' && s.data[s.top] != '[' && s.data[s.top] != '{') {
                current = pop(&s);
                printf("%c", current);
                length++;
                push(&expression, current);
                operator_count++;
            }
            pop(&s);
        } 
        else if (isOperator(exp[i])) {
            while (s.top != -1 && s.data[s.top] != '(' && s.data[s.top] != '[' && s.data[s.top] != '{' && precedence(s.data[s.top]) >= precedence(exp[i])) {
                current = pop(&s);
                printf("%c", current);
                length++;
                push(&expression, current);
                operator_count++;
            }
            push(&s, exp[i]);
        }
    }

    while (s.top != -1) {
        current = pop(&s);
        printf("%c", current);
        length++;
        push(&expression, current);
        if (isOperator(current)) {
            operator_count++;
        }
        else {
            operand_count++;
        }
    }
    printf("\n");

    if (operand_count - operator_count == 1) {
        printf("The expression is correct.\n");
        printf("The result of the expression is: %d\n", calculate(length));
    } 
    else {
        printf("ERROR\n");
        printf("The expression is incorrect.\n");
        printf("There might be not enough or too many operands or operators.\n");
        return 0;
    }
}