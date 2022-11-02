#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    struct node *left;
    char alphabet;
    struct node *right;
};

int check(char *line, int length) {
    struct node *head;
    struct node *current;
    struct node *end;
    struct node *newnode;
    
    head = (struct node *)malloc(sizeof(struct node));
    current = head;

    for (int i = 0; i < length; i++) {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->alphabet = line[i];

        current->right = newnode;
        newnode->left = current;
        current = current->right;
    }

    end = current;
    end->right = head;
    head->left = current;
    current = head->right;

    int result = 0;
    // 0 -> no, 1 -> yes

    for (int i = 0; i < length; i++) {
        if (current->alphabet != end->alphabet) {
            result = 0;
            break;
        }

        current = current->right;
        end = end->left;
        result = 1;
    }

    return result;
}

int main(void) {
    int testcase = 0;
    int result = 0;

    scanf("%d", &testcase);

    for (int i = 0; i < testcase; i++) {
        char line[100] = {0};

        scanf("%s", line);

        int len = strlen(line);

        result = check(line, len);

        if (result == 1) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }
}