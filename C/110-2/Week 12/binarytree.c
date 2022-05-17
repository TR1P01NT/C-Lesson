#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

int past[100];

void inorderTraversal(struct node *root);
struct node *insertnode(struct node *node, int val);
struct node *createnode(int val);
// int searchnode(struct node *root, int val);
int checknum(int val);

int main(void)
{
    struct node *root = NULL;
    int choice;
    int num;
    int flag = 0;
    int i = 0;

    for (int x = 0; x < 100; x++) {
        past[x] = -99;
    }

    scanf("%d", &choice);

    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
            scanf("%d", &num);
            root = insertnode(root, num);
            past[i++] = num;
            break;
        case 2:
            scanf("%d", &num);
            root = insertnode(root, num);
            past[i++] = num;
            break;
        case 3:
            scanf("%d", &num);
            flag = checknum(num);
            if (flag) {
                printf("Yes\n");
            }
            else {
                printf("No\n");
            }
            break;
        case 4:
            inorderTraversal(root);
            printf("\n");
            break;
        }

        scanf("%d", &choice);
    }
}

void inorderTraversal(struct node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

struct node *createnode(int val) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp -> data = val;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}

struct node *insertnode(struct node *node, int val) {
    if (node == NULL) {
        return createnode(val);
    }

    int flag = 0;
    flag = checknum(val);

    if (!flag) {
        if (val < node->data) {
        node -> right = insertnode(node->right, val);
        }
        else {
            node -> left = insertnode(node->left, val);
        }
    }

    return node;
}

// int searchnode(struct node *root, int val) {
//     if (root == NULL) {
//         return 0;
//     }

//     if (root->data == val) {
//         return 1;
//     }

//     if (val < root->data) {
//         return searchnode(root->right, val);
//     }
//     else {
//         return searchnode(root->left, val);
//     }
// }

int checknum(int val) {
    int i;
    for (i = 0; i < 100; i++) {
        if (past[i] == val) {
            return 1;
        }
    }
    return 0;
}