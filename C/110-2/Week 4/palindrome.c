#include <stdio.h>

int reverse(int num);
int palindrome(int num);

int main(void) {
    int n = 0, number = 0, count = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &number);

        while(!palindrome(number)) {
            number += reverse(number);
            ++count;
        }

        printf("%d %d\n", count, number);
        count = 0;
    }

    
}

int reverse(int num) {
    int remainder = 0, total = 0;
    while (num != 0) {
        remainder = num % 10;
        total = total * 10 + remainder;
        num /= 10;
    }
    return total;
}

int palindrome(int num) {
    int reverse_num = reverse(num);
    if (num == reverse_num) {
        return 1;
    }
    else {
        return 0;
    }
}