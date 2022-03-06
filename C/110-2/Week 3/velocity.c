#include <stdio.h>

int main(void) {
    int velocity = 0, time = 0;

    scanf("%d %d", &velocity, &time);

    while((time >= 0)) {
        printf("%d\n", velocity * time * 2);
        scanf("%d %d", &velocity, &time);
    }
}