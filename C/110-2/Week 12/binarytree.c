#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

int flag = 0;

void inorderTraversal(struct node *root);
struct node *insert(struct node *node, int val);

int main(void)
{
    struct node *root = NULL;
    int choice;
    int num;

    scanf("%d", &choice);

    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
            scanf("%d", &num);
            root = insert(root, num);
            break;
        case 2:
            scanf("%d", &num);
            root = insert(root, num);
            break;
        case 3:
            scanf("%d", &num);
            break;
        case 4:
            inorderTraversal(root);
            printf("\n");
            break;
        }

        scanf("%d", &choice);
    }
}

void inorderTraversal(struct node *root)
{
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

struct node *createnode(int val) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp -> data = val;
    temp -> left = temp -> right = NULL;
    return temp;
}

struct node *insert(struct node *node, int val) {
    if (node == NULL) {
        return createnode(val);
    }

    if (val < node->data) {
        node -> right = insert(node->right, val);
    }
    else {
        node -> left = insert(node->left, val);
    }

    return node;
}