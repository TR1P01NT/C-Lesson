#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct tree {
    char data;
    struct tree *left_child;
    struct tree *right_child;
};

void postfix_order(struct tree *root) {
    if (root == NULL) {
        return;
    }
    postfix_order(root->left_child);
    postfix_order(root->right_child);
    printf("%c", root->data);
}

struct tree *createnode(char *prefix, char *infix) {
    if (prefix[0] == '\0') {
        return NULL;
    }

    struct tree *root = (struct tree *)malloc(sizeof(struct tree));

    root->data = prefix[0];

    int prefix_len = strlen(prefix);
    int infix_len = strlen(infix);

    int i;

    char infix_left[100] = {0};
    char infix_right[100] = {0};
    char prefix_left[100] = {0};
    char prefix_right[100] = {0};

    int left_count = 0;

    for (i = 0; i < infix_len; i++) {
        if (infix[i] == prefix[0]) {
            break;
        }
        infix_left[i] = infix[i];
        left_count++;
    }

    int j = 0;

    for (i = i + 1; i < infix_len; i++) {
        infix_right[j] = infix[i];
        j++;
    }

    for (i = 1; i <= left_count; i++) {
        prefix_left[i - 1] = prefix[i];
    }

    j = 0;

    for (i = left_count + 1; i < prefix_len; i++) {
        prefix_right[j] = prefix[i];
        j++;
    }

    root->left_child = createnode(prefix_left, infix_left);
    root->right_child = createnode(prefix_right, infix_right);

    return root;
}

int main(void) {
    char infix[100] = {0};
    char prefix[100] = {0};

    scanf("%s", prefix);
    scanf("%s", infix);

    struct tree postfix;

    postfix = *createnode(prefix, infix);

    postfix_order(&postfix);
}