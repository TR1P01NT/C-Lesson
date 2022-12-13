#include <stdio.h>

int find_max(int x, int y) {
    return (x > y) ? x : y;
}

int find_min(int x, int y) {
    return (x < y) ? x : y;
}

int main(void) {
    int start, end;

    scanf("%d %d", &start, &end);

    while (start != -1 && end != -1) {
        int max_cycle = 0;
        int cycle = 0;

        for (int i = find_min(start, end); i <= find_max(start, end); i++) {
            int num = i;
            cycle = 1;

            while (num != 1) {
                if (num % 2 == 0) {
                    num /= 2;
                }
                else {
                    num = (3 * num) + 1;
                }
                cycle++;
            }
            max_cycle = find_max(max_cycle, cycle);
        }

        printf("%d %d %d\n", start, end, max_cycle);

        scanf("%d %d", &start, &end);
    }
}