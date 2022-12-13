#include <stdio.h>

int main(void) {
    int velocity = 0;
    int time = 0;

    while(scanf("%d %d", &velocity, &time) != EOF) {
        printf("%d\n", velocity * time * 2);
    }
}