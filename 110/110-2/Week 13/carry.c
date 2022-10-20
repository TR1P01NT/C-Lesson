#include <stdio.h>

//carry operation

unsigned int left[15], right[15];

int main(void) {
    int left_count = 0, right_count = 0;
    int num[11] = {0};
    int n;
    int carry = 0;
    long long int left_num, right_num;

    scanf("%llu", &left_num);
    scanf("%llu", &right_num);

    while ((left_num + right_num) != 0) {
        int i, j;
        for (i = 0; left_num != 0; i++) {
            left[i] = left_num % 10;
            left_num /= 10;
        }

        for (j = 0; right_num != 0; j++) {
            right[j] = right_num % 10;
            right_num /= 10;
        }

        left_count = i;
        right_count = j;

        int a, b;

        if ((left_count < 11) && (right_count < 11)) {
            if (left_count == 1 || right_count == 1) {
                if (left_count > right_count) {
                    num[0] = left[0] + right[0];
                    if (num[0] >= 10) {
                        num[1]++;
                        carry++;
                    }
                    for (int i = 1; i < left_count; i++) {
                        num[i] += left[i];
                        if (num[i] >= 10) {
                            num[i + 1]++;
                            carry++;
                        }
                    }
                }
                else {
                    num[0] = left[0] + right[0];
                    if (num[0] >= 10) {
                        num[1]++;
                    }
                    for (int i = 1; i < right_count; i++) {
                        num[i] += right[i];
                        if (num[i] >= 10) {
                            num[i + 1]++;
                            carry++;
                        }
                    }
                }
            }
            else if (left_count <= right_count) {
                for (a = 0; a < left_count; a++) {
                    num[a] = left[a] + right[a];
                    if (num[a] >= 10) {
                        carry++;
                        right[a + 1]++;
                    }
                }
                for (int x = a; a < 10; a++) {
                    num[a] = right[a];
                    if (num[a] >= 10) {
                        carry++;
                        right[a + 1]++;
                    }
                }
            }
            else if (left_count >= right_count) {
                for (b = 0; b < right_count; b++) {
                    num[b] = left[b] + right[b];
                    if (num[b] >= 10) {
                        carry++;
                        left[b + 1]++;
                    }
                }
                for (int x = b; b < 10; b++) {
                    num[b] = left[b];
                    if (num[b] >= 10) {
                        carry++;
                        left[b + 1]++;
                    }
                }
            }    
        }

        if (carry > 0) {
            if (carry == 1) {
                printf("1 carry operation.\n");
            } else {
                printf("%d carry operations.\n", carry);
            }
        }
        else if (left_count > 10 || right_count > 10) {
            printf("Out of scope.\n");
        }
        else if (carry == 0) {
            printf("No carry operation.\n");
        }

        scanf("%llu", &left_num);
        scanf("%llu", &right_num);
        carry = 0;
    }
}