#include <stdio.h>

//stack

int stack[5];
int max = 4;
int top = -1;

int isEmpty();
int isFull();
void push();
void pop();
void printStack();

int main(void) {
    int choice = 0;

    scanf("%d", &choice);

    while (choice != 0) {
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                printStack();
                break;
        }

        scanf("%d", &choice);
    }
}

void push() {
    int data;
    int flag = 0;

    scanf("%d", &data);

    if (!isFull()) {
        for (int i = top; i > -1; i--) {
            if (stack[i] == data) {
                flag = 1;
                break;
            }
        }
        
        if (!flag) {
            top++;
            stack[top] = data;
        }
    }
}

void pop() {
    if (!isEmpty()) {
        printf("%d\n", stack[top]);
        top--;
    }
}

int isEmpty() {
    if (top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

int isFull() {
    if (top == max) {
        return 1;
    }
    else {
        return 0;
    }
}

void printStack() {
    for (int i = top; i > -1; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}