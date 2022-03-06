#include <stdio.h>

int main(void) {
    int time, i, j, x = 0, day, max1, max2, count = 0;

    scanf("%d", &time);

    float temp[time][4], average[1][4] = {0 ,0 ,0, 0}, daily[1][time], min = 100, max = 0;

    for (i = 0; i < time; i++) {
        daily[0][i] = 0;
    }

    for (i = 0; i < time; i++) {
        for (j = 0; j < 4; j++) {
            scanf("%f", &temp[i][j]);
            if (temp[i][j] > max) {
                max = temp[i][j];
                max1 = i;
                max2 = j;
            }
        }
    }

    for (x = 0; x < 4; x++) {
        for (i = 0; i < time; i++) {
            average[0][x] += temp[i][x];
        }
        average[0][x] /= time;
        if (average[0][x] < min) {
            min = average[0][x];
            day = x;
        }
    }

    for (i = 0; i < time; i++) {
        for (j = 0; j < 4; j++) {
            daily[0][i] += temp[i][j];
        }
        daily[0][i] /= 4;
    }

    for (i = 0; i < time; i++) {
        for (j = 0; j < 4; j++) {
            printf("%.1f ", temp[i][j]);
            ++count;
            if (count == 4) {
                printf("\n");
                count = 0;
            }
        }
    }

    for (x = 0; x < 4; x++) {
        printf("%.1f ", average[0][x]);
    }

    printf("\n");

    for (i = 0; i < time; i++) {
        printf("%.1f ", daily[0][i]);
    }

    printf("\n%d %d\n", max1, max2 - 1);

    printf("%d", day + 1);
}