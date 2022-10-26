#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    char name[100];
    int score;
    struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

struct node *add_data(char *name, int score) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));

    strcpy(new_node->name, name);
    new_node->score = score;

    if (head == NULL) {
        head = new_node;
        head->next = NULL;
    } 
    else {
        current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
        new_node->next = NULL;
    }

    return new_node;
}

int list_length() {
    int length = 0;
    struct node *current;

    for (current = head; current != NULL; current = current->next) {
        length++;
    }

    return length;
}

void sort_data() {
    struct node *current = head;
    struct node *next = NULL;
    
    int length = list_length();

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (current->score < current->next->score) {
                int temp_score = current->score;
                char temp_name[100];
                strcpy(temp_name, current->name);

                current->score = current->next->score;
                strcpy(current->name, current->next->name);

                current->next->score = temp_score;
                strcpy(current->next->name, temp_name);
            }
            current = current->next;
        }
        current = head;
    }
}

int main(void) {
    int line = 0;
    char name[100] = "";
    int score = 0;

    scanf("%d", &line);

    for (int i = 0; i < line; i++) {
        scanf("%s", name);

        if (strcmp(name, "delete") == 0) {
            head = head->next;
        }
        else {
            scanf("%d", &score);

            add_data(name, score);
            sort_data();
        }
    }
    
    struct node *ptr = head;

    while (ptr != NULL) {
        printf("%s\n", ptr->name);
        ptr = ptr->next;
    }
}