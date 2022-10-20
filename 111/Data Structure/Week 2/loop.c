#include <stdio.h>

int multiplication(int answer, int base_num, int binary_exponent[], int count);

int main(void) {
    int base, exp;
    int total = 1;
    int binary_exp[100];
    int answer = 0;
    int count = 0;

    scanf("%d %d", &base, &exp);

    for (int i = 0; exp != 0; ++i, count++) {
        binary_exp[i] = exp % 2;
        exp /= 2;
    }

    answer = multiplication(total, base, binary_exp, count);
}

//function loop binary exponent

int multiplication(int answer, int base_num, int binary_exponent[], int count) {
    if (binary_exponent[count] == 0) {
        answer *= answer;
    }
    else if (binary_exponent[count] == 1) {
        answer *= (answer * base_num);
    }
    
    if (count == 0) {
        printf("%d\n", answer);
        return 0;
    }
    else {
        count--;
        return multiplication(answer, base_num, binary_exponent, count);
    }
}