#include <stdio.h>
#include <math.h>

int tree[70] = {0};
int tree_insert[70] = {0};
int tree_delete[70] = {0};
int max_node_count = 0;

void insertnode(int insert_location, int insert_value) {
    if (tree[insert_location] == 0) {
        tree[insert_location] = insert_value;
        max_node_count = insert_location;
    }
    else {
        if (insert_value < tree[insert_location]) {
            insertnode(2 * insert_location, insert_value);
        }
        else {
            insertnode(2 * insert_location + 1, insert_value);
        }
    }
}

int findnode(int target) {
    int i = 1;
    while (i <= max_node_count) {
        if (tree[i] == target) {
            return i;
        }
        else {
            if (target < tree[i]) {
                i = 2 * i;
            }
            else {
                i = (2 * i) + 1;
            }
        }
    }
    return 0;
}

int findmaxnode(int location) {
    int i = location;
    while (i <= max_node_count) {
        if (tree[(2 * i) + 1] == 0) {
            return i;
        }
        else {
            i = (2 * i) + 1;
        }
    }
    return 0;
}

int findminnode(int location) {
    int i = location;
    while (i <= max_node_count) {
        if (tree[2 * i] == 0) {
            return i;
        }
        else {
            i = 2 * i;
        }
    }
    return 0;
}

void deletenode(int to_delete) {
    int index = findnode(to_delete);
    int replacement = 0;

    if (tree[2 * index] != 0) {
        int sub_index = findmaxnode(2 * index);
        replacement = tree[sub_index];
        deletenode(tree[sub_index]);
    }
    else if (tree[2 * index + 1] != 0) {
        int sub_index = findminnode(2 * index + 1);
        replacement = tree[sub_index];
        deletenode(tree[sub_index]);
    }
    else {
        tree[index] = 0;
    }

    if (replacement != 0) {
        tree[index] = replacement;
    }
}

int main(void) {
    int insert_count = 0;
    int delete_count = 0;

    int node;

    while (1) {
        scanf("%d", &node);
        if (node == -1) {
            break;
        }
        tree_insert[insert_count] = node;
        insert_count++;
    }

    while (1) {
        scanf("%d", &node);
        if (node == -1) {
            break;
        }
        tree_delete[delete_count] = node;
        delete_count++;
    }

    tree[1] = tree_insert[0];

    for (int i = 1; i < insert_count; i++) {
        insertnode(1, tree_insert[i]);
    }

    // for (int i = 1; i <= max_node_count; i++) {
    //     printf("%d ", tree[i]);
    // }

    // printf("\n");

    for (int i = 0; i < delete_count; i++) {
        deletenode(tree_delete[i]);
    }

    int node_count = insert_count - delete_count;
    // int height = log2(node_count + 1);
    // printf("%d %d\n", node_count, height);

    for (int i = 1; i <= pow(2, node_count) - 1; i++) {
        if (tree[i] != 0) {
            max_node_count = i;
        }
    }

    for (int i = 1; i <= max_node_count; i++) {
        printf("%d ", tree[i]);
    }
}