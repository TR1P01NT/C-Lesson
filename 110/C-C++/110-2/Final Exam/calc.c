#include <stdio.h>
#include <math.h>
#include <string.h>

int addition(int x, int y);
int subtraction(int x, int y);
int multiplication(int x, int y);
int division(int x, int y);
int num_power(int x, int y);
void bracket();

//numbers and operators

int main(void) {
    char line[100];
    int ans = 0;

    scanf("%s", line);

    while (line[0] != '\0') {
        int length = strlen(line);
        int temp_num;

        for (int i = 0; i < length; i++) {
            if (isdigit(line[i])) {
                temp_num = line[i];
                continue;
            }

            if (line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] == '/' || line[i] == '^') {
                switch (line[i]) {
                    case '+':
                        ans += addition(temp_num, line[i + 1]);
                        i++;
                        break;
                }
            }
        }
    }
}