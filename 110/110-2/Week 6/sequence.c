#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    int test = 0;
    int sequence = 0, divider = 0;
    int num[10010][110] = {0};
    int number[10010] = {0};

    scanf("%d", &test);

    while(test--) {
        scanf("%d %d", &sequence, &divider);

        memset(num, 0 , sizeof(num)); // reset the content of the array

        for (int i = 1; i <= sequence; i++) {
            scanf("%d", &number[i]);
            number[i] = abs(number[i]); // make the number positive
        }

        num[1][number[1] % divider] = 1;

        for (int i = 1; i <= sequence; i++) {
            for (int j = 0; j < divider; j++) {
                if (num[i - 1][j]) {
                    num[i][(j + number[i]) % divider] = 1;
                    num[i][((j - number[i] + divider) % divider + divider) % divider] = 1;
                }
            }
        }

        if (num[sequence][0] == 1) {
            printf("Divisible\n");
        } 
        else {
            printf("Not divisible\n");
        }
        }
    }

/*
2 testcases

first

sequence = 4 
divider = 7

number[1] = 17
number[2] = 5
number[3] = 21
number[4] = 15

num[1][3] = 1

first iteration
i = 1 ; i <= 4
    j = 0 ; j < 7
nothing

second iteration
i = 2; i <= 4
    j = 3; j < 7
        num[1][3] = 1
            num[2][1] = 1
            num[2][5] = 1

third iteration
i = 3; i <= 4
    j = 1 ; j < 7
        num[2][1] = 1
            num[3][1] = 1
            num[3][1] = 1
    j = 5 ; j < 7
        num[2][5] = 1
            num[3][5] = 1
            num[3][5] = 1

fourth iteration
i = 4; i <= 4
    j = 1 ; j < 7
        num[3][1] = 1
            num[4][2] = 1
            num[4][0] = 1
    j = 5 ; j < 7
        num[3][5] = 1
            num[4][6] = 1
            num[4][4] = 1

as num[4][0] = 1, the sequence is divisible

second

sequence = 4 
divider = 5

number[1] = 17
number[2] = 5
number[3] = 21
number[4] = 15

num[1][2] = 1

first iteration
i = 1; i <= 4
j = 0 ; j < 7

second iteration
i = 2; i <= 4
    j = 2; j < 5
        num[1][2] = 1
            num[2][2] = 1
            num[2][2] = 1

third iteration
i = 3; i <= 4
    j = 2 ; j < 7
        num[2][2] = 1
            num[3][3] = 1
            num[3][1] = 1

fourth iteration
i = 4; i <= 4
    j = 1 ; j < 7
        num[3][1] = 1
            num[4][1] = 1
            num[4][1] = 1
    j = 3; j < 7
        num[3][3] = 1
            num[4][3] = 1
            num[4][3] = 1

as num[4][0] = 0, the sequence is not divisible
*/ 