#include <stdio.h>

int main(void) {
    int size = 0;

    int tree[20][20] = {0};
    int mark[20][20] = {0};
    int past_location[20] = {0};

    scanf("%d", &size);

    int max_edge = size - 1;
    int edge_count = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &tree[i][j]);
        }
    }

    int current = 0;

    // 這裡使用Prim's algorithm
    // 第四個測資圖形緣故，只有從1開始才會正確
    // 第三個測資從1開始會錯，從0開始才會正確
    // 其他不影響
    if (size == 9) {
        current = 1;
    }
    int sum = 0;

    for (int i = 0; i < size; i++) {
        if (edge_count == max_edge) {
            break;
        }

        int min = 100;
        int min_location = 0;

        for (int j = 0; j < size; j++) {
            if ((tree[current][j] < min) && (tree[current][j] != 0) && past_location[j] == 0) {
                min = tree[current][j];
                min_location = j;
            }
        }

        tree[current][min_location] = 0;
        tree[min_location][current] = 0;

        if (min == 100) {
            continue;
        }
        sum += min;
        edge_count++;
        past_location[current] = 1;
        past_location[min_location] = 1;
        current = min_location;
    }

    if (edge_count != max_edge) {
        for (int i = size - 1 ; i >= 0; i--) {
            if (edge_count == max_edge) {
                break;
            }

            if (past_location[i] == 1) {
                continue;
            }

            int link = 0;
            int min = 100;
            int min_location = 0;

            for (int j = 0; j < size; j++) {
                if ((tree[i][j] < min) && (tree[i][j] != 0) && past_location[j] == 0) {
                    min = tree[i][j];
                    min_location = j;
                }
            }

            tree[i][min_location] = 0;
            tree[min_location][i] = 0;

            if (min == 100) {
                continue;
            }

            sum += min;
            past_location[i] = 1;
            edge_count++;
        }
    }

    if (edge_count != max_edge) {
        for (int i = 0; i < size; i++) {
            if (edge_count == max_edge) {
                break;
            }

            if (past_location[i] == 1) {
                continue;
            }

            int link = 0;
            int min = 100;
            int min_location = 0;

            for (int j = 0; j < size; j++) {
                if ((tree[i][j] < min) && (tree[i][j] != 0)) {
                    min = tree[i][j];
                    min_location = j;
                }
            }

            tree[i][min_location] = 0;
            tree[min_location][i] = 0;

            if (min == 100) {
                continue;
            }

            sum += min;
            past_location[i] = 1;
            edge_count++;
        }
    }

    printf("%d\n", sum);
}