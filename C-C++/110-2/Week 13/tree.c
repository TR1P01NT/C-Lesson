#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

int past[100] = {0};
int check[10];
int kit = 0;

struct node *createnode(int val);
struct node *insertnode(struct node *node, int val);
int checknum(int val);
struct node *removeNode(struct node *root, int val);
int getRightMin(struct node *root);
void inorderTraversal(struct node *root);
void printout();

int main(void)
{
    struct node *root = NULL;
    int choice;
    int num;
    int flag = 0;
    int i = 0;
    int count = 0;

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
            root = removeNode(root, num);
            count--;
            break;
        case 4:
            scanf("%d", &num);
            flag = checknum(num);
            if (flag) {
                printf("Yes\n");
            }
            else {
                printf("No\n");
            }
            break;
        case 5:
            kit = 0;
            inorderTraversal(root);
            printout();
            break;
        }

        scanf("%d", &choice);
    }
}

void inorderTraversal(struct node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        check[kit++] = root->data;
        inorderTraversal(root->right);
    }
}

void printout() {
    for (int x = 0; x < kit - 1; x++) {
        printf("%d ", check[x]);
    }

    printf("%d\n", check[kit - 1]);

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
        node -> left = insertnode(node->left, val);
        }
        else {
            node -> right = insertnode(node->right, val);
        }
    }

    return node;
}

int checknum(int val) {
    int i;
    for (i = 0; i < 100; i++) {
        if (past[i] == val) {
            return 1;
        }
    }
    return 0;
}

int getRightMin(struct node *root)
{
    struct node *temp = root;

    while(temp->left != NULL) { 
        temp = temp->left;
    }

    return temp->data;
}

struct node *removeNode(struct node *root, int val)
{
    if (root == NULL) {
        return NULL;
    }

    if (root->data < val) {
        root->right = removeNode(root->right,val);
    }
    
    else if (root->data > val) {
        root->left = removeNode(root->left,val);
    }
    
    else {
        
        if(root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        
        else if(root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        
        else if(root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        
        else {
            int rightMin = getRightMin(root->right);
            root->data = rightMin;
            root->right = removeNode(root->right,rightMin);
        }

    }

    return root;
}