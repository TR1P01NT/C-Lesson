#include <stdio.h>

int main(void) {
    int people = 0, day = 0, endday = 0, i = 0;

    scanf("%d %d", &people, &endday);

    while((people != 0) && (endday != 0)) {
        for(i = day; i <= endday; people++) {
            i += people;

            if(i >= endday) {
                break;
            }
        }
        printf("%d\n", people);

        scanf("%d %d", &people, &endday);
    }
}