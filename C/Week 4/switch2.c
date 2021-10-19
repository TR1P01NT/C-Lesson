#include <stdio.h>

int main(void) {
    int grade;
    unsigned int a = 0, b = 0, c = 0, d = 0, f = 0;

    puts("Enter the letter grades.");
    puts("Enter the EOF character to end input.");

    while ((grade = getchar()) != EOF) {
        if (grade == 'A' || grade == 'a') {
            ++a;
        }
        else if (grade == 'B' || grade == 'b') {
            ++b;
        }
        else if (grade == 'C' || grade == 'c') {
            ++c;
        }
        else if (grade == 'D' || grade == 'd') {
            ++d;
        }
        else if (grade == 'F' || grade == 'f') {
            ++f;
        }
        else if (grade == '\n' || grade == ' ' || grade == '\t') {
            continue;
        }
        else {
            printf("%s", "Incorrect letter grade entered.");
            puts(" Enter a new grade.");
        }
    }

    puts("\nTotals for each letter grade are:");
    printf("A: %u\n", a);
    printf("B: %u\n", b);
    printf("C: %u\n", c);
    printf("D: %u\n", d);
    printf("F: %u\n", f);
}