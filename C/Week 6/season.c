#include <stdio.h>

int main(void) {
    int n;

    scanf("%d", &n);

    while (n != -1) {
        switch (n) {
            case 3 ... 5:
                printf("Spring\n");
                break;
            case 6 ... 8:
                printf("Summer\n");
                break;
            case 9 ... 11:
                printf("Autumn\n");
                break;
            case 12: case 1: case 2:
                printf("Winter\n");
                break;
        }

        scanf("%d", &n);
    }
}