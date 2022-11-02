// doubly linked list

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct doubly {
    struct doubly *left;
    char alphabet;
    struct doubly *right;
};

int main(void) {
    int testcase = 0;
    int result = 0;
    // 0 = no, 1 = yes

    scanf("%d", &testcase);

    for (int i = 0; i < testcase; i++) {
        char line[100] = {0};
        
        for (int x = 0; x < 100; x++) {
            line[x] = 0;
        }

        result = 0;

        scanf("%s", line);

        int len = strlen(line);

        if (len == 1) {
            printf("Yes\n");
            continue;
        }

        struct doubly *head = (struct doubly *)malloc(sizeof(struct doubly));
        struct doubly *current = head;

        for (int j = 0; j < len; j++) {
            struct doubly *newnode = (struct doubly *)malloc(sizeof(struct doubly));
            newnode->alphabet = line[j];

            current->right = newnode;
            newnode->left = current;
            current = current->right;
        }

        struct doubly *end = current;
        end->right = head;
        head->left = current;
        current = head->right;

        if (len % 2 == 0) {
            int half_length = (len / 2);

            for (int m = 0; m < half_length; m++) {
                if (current->alphabet != end->alphabet) {
                    result = 0;
                    break;
                }
                result = 1;
                current = current->right;
                end = end->left;
            }

            if (result == 1) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
        else {
            int length = (len / 2);

            for (int m = 0; m < length; m++) {
                if (current->alphabet != end->alphabet) {
                    result = 0;
                    break;
                }
                result = 1;
                current = current->right;
                end = end->left;
            }

            if (result == 1) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
}