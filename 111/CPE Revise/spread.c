#include <stdio.h>

int main(void) {
    int testcase = 0;
    int total = 0;
    int difference = 0;

    scanf("%d", &testcase);

    while (testcase--) {
        scanf("%d %d", &total, &difference);

        if (total < difference) {
            printf("impossible\n");
            continue;
        }

        for (int i = 0; i < difference; i++) {
            if (i + i + difference == total) {
                printf("%d %d\n", i + difference, i);
                continue;
            }
        }
    }
}

/*
#include<stdio.h>

int main(){

    int n;
    int i;
    int s, d;
    int a, b;

    scanf("%d", &n);

    for(i = 0; i < n; i++){

        scanf("%d %d", &s, &d);

        a = s + d;
        b = s - d;

        if(a < 0 || b < 0 || a % 2 != 0 || b % 2 != 0){
            printf("impossible\n");
        }
        else{
            printf("%d %d\n", a / 2, b / 2);
        }
    }

    return 0;
}
*/