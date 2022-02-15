#include <stdio.h>

int main(void) {
    char *topics[5] = {"police", "weather", "global", "social", "media"};
    int responses[5][10] = {0}, total[5] = {0};
    int people = 0, temp = 0, max = 0, min = 100, maxname = 0, minname = 0;

    scanf("%d", &people);

    int input[people][5];

    for (int i = 0; i < people; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &input[i][j]);
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < people; j++) {
            temp = input[j][i];
            total[i] += temp;
            responses[i][temp - 1]++;
        }
    }

    printf("%10s ", " ");

    for (int i = 1; i <= 10; i++) {
        printf("%3d", i);
    }

    printf("\n");

    for (int i = 0; i < 5; i++) {
        printf("%10s ", topics[i]);
        for (int j = 0; j < 10; j++) {
            printf("%3d", responses[i][j]);
        }
        printf("%3d\n", total[i] / people);
    }

    for (int i = 0; i < 5; i++) {
        if (total[i] > max) {
            max = total[i];
            maxname = i;
        }

        if (total[i] <= min) {
            min = total[i];
            minname = i;
        }
    }

    printf("%s %d\n", topics[maxname], max);

    printf("%s %d\n", topics[minname], min);
}