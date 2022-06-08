#include <stdio.h>
#include <stdlib.h>

struct node {
        char key;
        struct node *next;
    };

    int main(void) {
        struct node *head = NULL;
        struct node *node = NULL;
        struct node *reverse_head = NULL;
        struct node *reverse_node = NULL;
        char *keys[10] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};

        for (int i = 0; i < 10; i++) {
            node = (struct node *)malloc(sizeof(struct node));
            if (node == NULL) {
                printf("Error\n");
                return 1;
            }
            node->key = *keys[i];
            node->next = head;
            head = node;
        }

        node = head;
        while (node != NULL) {
            reverse_node = (struct node *)malloc(sizeof(struct node));
            if (reverse_node == NULL) {
                printf("Error\n");
                return 1;
            }
            reverse_node->key = node->key;
            reverse_node->next = reverse_head;
            reverse_head = reverse_node;
            node = node->next;
        }

        printf("Before reverse: ");

        node = head;
        while (node != NULL) {
            printf("%c", node->key);
            node = node->next;
        }
        printf("\n");

        printf("After reverse: ");
        
        node = reverse_head;
        while (node != NULL) {
            printf("%c", node->key);
            node = node->next;
        }
        printf("\n");
    }