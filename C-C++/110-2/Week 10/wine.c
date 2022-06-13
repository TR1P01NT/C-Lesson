#include <stdio.h>
#include <stdlib.h>

//economy and wine

int main(void) {
    int house;
    long long int transaction[1000001];
    long long int work = 0;

    scanf("%d", &house);

    while(house != 0) {
        for (int i = 0; i < house; i++) {
            scanf("%lld", &transaction[i]);
        }

        for (int j = 1; j < house; j++) {
          work += llabs(transaction[j - 1]);
          transaction[j] += transaction[j - 1];
          transaction[j - 1] = 0;
        }

        printf("%lld\n", work);
        work = 0;

        scanf("%d", &house);
    }
}