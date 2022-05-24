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
int checknum(int val);
void inorder(int count);
int getRightMin(struct node *root);
struct node *removeNode(struct node *root, int val);
void removePast(int val, int count);

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
            root = removeNode(root, num);
            past[i++] = num;
            removePast(num, count);
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
        inorderTraversal(root->right);
        printf("%d ", root->data);
        inorderTraversal(root->left);
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

void removePast(int val, int count) {
    int i;
    for (i = 0; i < count; i++) {
        if (past[i] == val) {
            past[i] = -1;

            for (int j = i; j < count; j++) {
                past[j] = past[j + 1];
            }
        }
    }
}