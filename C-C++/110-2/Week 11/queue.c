#include <stdio.h>

int queue[5];
int max = 4;
int rear = -1;

void inqueue();
void dequeue();
void printQueue();
int isFull();
int isEmpty();

int main(void) {
    int choice = 0;

    scanf("%d", &choice);

    while (choice != 0) {
        switch (choice) {
            case 1:
                inqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printQueue();
                break;
        }
        
        scanf("%d", &choice);
    }
}

void inqueue() {
    int data;
    int flag = 0;

    scanf("%d", &data);

    if (!isFull()) {
        for (int i = 0; i < 5; i++) {
            if (queue[i] == data) {
                flag = 1;
                break;
            }
        }
    }

    if (!flag) {
        rear++;
        queue[rear] = data;
    }
}

void dequeue() {
    if (!isEmpty()) {
        printf("%d\n", queue[0]);

        queue[0] = 0;

        for (int i = 0; i < rear; i++) {
            queue[i] = queue[i + 1];
        }

        rear--;
    }
}

int isFull() {
    if (rear == max) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty() {
    if (rear == -1) {
        return 1;
    } else {
        return 0;
    }
}

void printQueue() {
    for (int i = 0; i < rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}