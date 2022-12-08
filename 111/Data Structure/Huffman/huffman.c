#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    char data[26];
    int count;
};

int queue_head = 0;
int queue_rear = 0;
struct node huffmanQueue[50];

void priorityQueueArrange(struct node *queue) {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    for (int i = 0; i < queue_rear; i++) {
        for (int j = i + 1; j < queue_rear; j++) {
            if (queue[i].count > queue[j].count) {
                temp->count = queue[j].count;
                queue[j].count = queue[i].count;
                queue[i].count = temp->count;

                strcpy(temp->data, queue[j].data);
                strcpy(queue[j].data, queue[i].data);
                strcpy(queue[i].data, temp->data);
            }
        }
    }
}

void huffman_dequeue(struct node *queue) {
    char data1[50] = {0};
    char data2[50] = {0};
    int count1 = queue[queue_head].count;
    int count2 = queue[queue_head + 1].count;

    strcpy(data1, queue[queue_head].data);
    strcpy(data2, queue[queue_head + 1].data);

    char data[50] = {0};
    strcat(data1, data2);
    strcat(data, data1);

    int length = strlen(data);

    for (int i = 0; i < length; i++) {
        printf("%c", data[i]);
    }

    queue_head++;

    strcpy(queue[queue_head].data, data);
    queue[queue_head].count = count1 + count2;
}

int main(void) {
    char alphabet;
    int frequency = 0;

    scanf("%s", &alphabet);

    while (alphabet != '.') {
        scanf("%d", &frequency);

        strcpy(huffmanQueue[queue_rear].data, &alphabet);
        
        huffmanQueue[queue_rear].count = frequency;
        queue_rear++;

        priorityQueueArrange(huffmanQueue);
        scanf("%s", &alphabet);
    }

    int data_count = 1;

    while (data_count < queue_rear) {
        printf("%d", data_count);
        huffman_dequeue(huffmanQueue);
        data_count++;
        priorityQueueArrange(huffmanQueue);
    }
}