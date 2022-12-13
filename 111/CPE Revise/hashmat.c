#include <stdio.h>

int main(void) {
    long long int hashmat = 0;
    long long int opponent = 0;

    while(scanf("%lld %lld", &hashmat, &opponent) != EOF) {
        if(hashmat < opponent) {
            long long int temp = hashmat;
            hashmat = opponent;
            opponent = temp;
        }

        long long int difference = hashmat - opponent;
        printf("%lld\n", difference);
    }
}