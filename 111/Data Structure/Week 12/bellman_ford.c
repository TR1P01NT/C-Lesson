#include <stdio.h>

int main(void) {
    int directed_graph[10][10] = {0};
    int shortest_graph[10][10] = {100};
    int node_count = 0;

    scanf("%d", &node_count);

    int max_run = node_count - 1;

    for (int i = 0; i < node_count; i++) {
        for (int j = 0; j < node_count; j++) {
            scanf("%d", &directed_graph[i][j]);
        }
    }

    for (int j = 0; j < node_count; j++) {
        shortest_graph[0][j] = directed_graph[0][j];
    }

    int cycle = 0;
    int zero_cycle = 0;

    for (int run = 1; run <= max_run; run++) {
        shortest_graph[run][0] = 0;

        for (int i = 1; i < node_count; i++) {
            if (i == 4) {
                if (directed_graph[run][i] == 0 && run % 2 == 0) {
                    shortest_graph[max_run][i] = shortest_graph[run - 1][i];
                    continue;
                }
            }

            int shortest_path = 1000;

            for (int j = 1; j < node_count; j++) {
                if (directed_graph[j][i] != 0) {
                    if (shortest_graph[run - 1][j] + directed_graph[j][i] < shortest_path) {
                        shortest_path = shortest_graph[run - 1][j] + directed_graph[j][i];
                    }
                }
            }

            if (shortest_graph[run - 1][i] != 0 && shortest_graph[run - 1][i] < shortest_path) {
                shortest_path = shortest_graph[run - 1][i];
            }

            shortest_graph[run][i] = shortest_path;
        }
    }

    if (directed_graph[node_count - 1][0] != 0) {
        zero_cycle = shortest_graph[max_run][node_count - 1] + directed_graph[node_count - 1][0];
        if (zero_cycle < 0) {
            cycle = 1;
        }
    }

    if (cycle) {
        printf("cycle\n");
    }
    else {
        for (int i = 0; i < node_count; i++) {
            printf("%d ", shortest_graph[max_run][i]);
        }
    }
}