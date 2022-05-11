#include <stdio.h>
#include <math.h>

struct student {
        char name[20];
        int score;
        float fscore;
    };

int main(void) {
    struct student a[10];
    int count = 0;

    while ((scanf("%s %d", a[count].name, &a[count].score)) != EOF) {
        a[count].fscore = ((sqrt((float)a[count].score)) * 10);
        count++;
    }

    for (int i = 0; i < count; i++) {
        printf("%s %d %.2f\n", a[i].name, a[i].score, a[i].fscore);
    }
}