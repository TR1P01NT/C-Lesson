#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
        char name[10];
        int score;
    };

int main(void) {
    struct student a[100];
    int count = 0;

    while ((scanf("%s %d", a[count].name, &a[count].score)) != EOF) {
        count++;
    }

    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (a[i].score > a[j].score) {
                struct student temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    for (int i = 0; i < count; i++) {
        printf("%s %d\n", a[i].name, a[i].score);
    }
}