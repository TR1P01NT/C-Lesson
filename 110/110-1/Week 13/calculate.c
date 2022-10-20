#include <stdio.h>

int calculate(const int *num, int *sum, float *average);

int main(void) {
    const int num[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int sum = 0;
    float average = 0;

    calculate(&num[0], &sum, &average);

    printf("%d %.1f\n", sum, average);

}

int calculate(const int *num, int *sum, float *average) {
    int i;

    for (i = 0; i < 20; i++) {
        *sum += num[i];
    }

    *average = (float)*sum / 20;

    return 0;
}