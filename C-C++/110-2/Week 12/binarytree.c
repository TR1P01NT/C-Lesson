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
void inorder(int count);

int main(void)
{
    struct node *root = NULL;
    int choice;
    int num;
    int flag = 0;
    int i = 0;
    int count = 0;

    for (int x = 0; x < 100; x++) {
        past[x] = -1;
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
            count++;
            break;
        case 2:
            scanf("%d", &num);
            root = insertnode(root, num);
            past[i++] = num;
            count++;
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
            // inorderTraversal(root);
            inorder(count);
            // printf("\n");
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

void inorder(int count) {
    int out[100];

    for (int i = 0; i < count; i++) {
        out[i] = past[i];
    }

    for (int i = 0; i < count; i ++)  
    {  
        for (int j = i + 1; j < count; j++)  
        {  
            if (out[i] == out[j])  
            {  
                for (int k = j; k < count - 1; k++)  
                {  
                    out[k] = out[k + 1];  
                }  
                count--;  
                  
                j--;      
            }  
        }  
    }  

    int tmp;

    for (int i = 0; i < count; ++i) 
        {
            for (int j = i + 1; j < count; ++j) 
            {
                if (out[i] < out[j]) 
                {
                    tmp = out[i];
                    out[i] = out[j];
                    out[j] = tmp;
                }
            }
        }

    for (int i = 0; i < count - 1; i++) {
        printf("%d ", out[i]);
    }

    printf("%d\n", out[count - 1]);
}