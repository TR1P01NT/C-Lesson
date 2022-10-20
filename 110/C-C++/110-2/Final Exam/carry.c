#include <stdio.h>

unsigned int numone[10], numtwo[10];

int main(void) {
    unsigned int num1, num2;
    int num1_count, num2_count;
    int operation = 0;
    int num[10] = {0};

    scanf("%d %d", &num1, &num2);

    while (num1 + num2 != 0) {
        int i;
        for (i = 0; i < 9; i++) {
            numone[i] = num1 % 10;
            num1 /= 10;
        }

        int j;
        for (j = 0; j < 9; j++) {
            numtwo[j] = num2 % 10;
            num2 /= 10;
        }

        num1_count = i;
        num2_count = j;

        if ((num1_count == 1) || (num2_count == 1)) {
            if (num1_count > num2_count) {
                num[0] = numone[0] + numtwo[0];
                if (num[0] >= 10) {
                    operation++;
                    num[1]++;
                }

                for (int a = 1; a < num1_count; a++) {
                    num[a] += numone[a];
                    if (num[a] >= 10) {
                        operation++;
                        num[a + 1]++;
                    }
                }
            }

            else {
                num[0] = numone[0] + numtwo[0];
                if (num[0] >= 10) {
                    operation++;
                    num[1]++;
                }

                for (int a = 1; a < num2_count; a++) {
                    num[a] += numtwo[a];
                    if (num[a] >= 10) {
                        operation++;
                        num[a + 1]++;
                    }
                }
            }
        }
        else if (num1_count <= num2_count) {
            int a;
            for (a = 0; a < num1_count; a++) {
                num[a] = numone[a] + numtwo[a];
                if (num[a] >= 10) {
                    operation++;
                    numtwo[a + 1]++;
                }
            }
            for (int x = a; a < 9; a++) {
                num[a] = numtwo[a];
                if (num[a] >= 10) {
                    operation++;
                    numtwo[a + 1]++;
                }
            }
        }
        else if (num1_count >= num2_count) {
            int a;
            for (a = 0; a < num2_count; a++) {
                num[a] = numone[a] + numtwo[a];
                if (num[a] >= 10) {
                    operation++;
                    numone[a + 1]++;
                }
            }
            for (int x = a; a < 9; a++) {
                num[a] = numone[a];
                if (num[a] >= 10) {
                    operation++;
                    numone[a + 1]++;
                }
            }
        }

        if (operation == 0) {
            printf("No carry operation.\n");
        }
        else if (operation == 1) {
            printf("1 carry operation.\n");
        }
        else {
            printf("%d carry operations.\n", operation);
        }

        operation = 0;

        scanf("%d %d", &num1, &num2);
    }
}