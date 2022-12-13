#include <stdio.h>

int main(void) {
    int bottles = 0;

    while(scanf("%d", &bottles) != EOF) {
        printf("%d\n", 3 * bottles / 2);
    }
}