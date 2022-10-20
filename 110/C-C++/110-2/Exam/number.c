#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct node {
        int key;
        struct node *next;
    };

    int main(void) {
        struct node *head = NULL;
        struct node *node = NULL;
        int sum = 0;
        int average = 0;
        int keys[25] = {0};

        srand(time(NULL));

        for (int i = 0; i < 25; i++) {
            keys[i] = rand() % 100;
            printf("%d ", keys[i]);
        }
        printf("\n");

        for (int i = 0; i < 25; i++) {
            node = (struct node *)malloc(sizeof(struct node));
            if (node == NULL) {
                printf("Error\n");
                return 1;
            }
            node->key = keys[i];
            node->next = head;
            head = node;
        }

        node = head;
        while (node != NULL) {
            sum += node->key;
            node = node->next;
        }

        average = sum / 25;

        printf("Sum: %d\n", sum);
        printf("Average: %d\n", average);
    }