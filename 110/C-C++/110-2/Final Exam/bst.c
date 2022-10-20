#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int val) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node *insertnode(struct node *node, int val) {
    if (node == NULL) {
        return createnode(val);
    }
    if (val < node->data) {
        node->left = insertnode(node->left, val);
    }
    else {
        node->right = insertnode(node->right, val);
    }
    return node;
}

int checknode(struct node *node) {
    if (node == NULL) {
        return 1;
    }
    if (node->left != NULL && node->left->data > node->data) {
        return 0;
    }
    if (node->right != NULL && node->right->data < node->data) {
        return 0;
    }
    if (!checknode(node->left) || !checknode(node->right)) {
        return 0;
    }
    return 1;
}

int main(void) {
    struct node *root = NULL;
    int val;
    int check = 0;
    char line[100];
    int x = 0;

    while ((scanf("%d", &val)) != EOF) {
        root = insertnode(root, val);

        if (getchar() == '\n') {
            check = checknode(root);
            if (check) {
                printf("YES\n");
            }
            else {
                printf("NO\n");
            }
            // free(root);
            root = NULL;
            check = 0;
        }
    }
}