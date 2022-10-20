#include <stdio.h>

//first day of 2011 is Saturday

int main(void) {
    int testcase;

    scanf("%d", &testcase);

    for (int x = 0; x < testcase; x++) {
        int day, month, total_day = 0;
        int* j;

        scanf("%d %d", &month, &day);

        for (int i = 0; i < month - 1; i++) {
            switch (i) {
                case 0:
                    total_day += 31;
                    break;
                case 1:
                    total_day += 28;
                    break;
                case 2:
                    total_day += 31;
                    break;
                case 3:
                    total_day += 30;
                    break;
                case 4:
                    total_day += 31;
                    break;
                case 5:
                    total_day += 30;
                    break;
                case 6:
                    total_day += 31;
                    break;
                case 7:
                    total_day += 31;
                    break;
                case 8:
                    total_day += 30;
                    break;
                case 9:
                    total_day += 31;
                    break;
                case 10:
                    total_day += 30;
                    break;
                case 11:
                    total_day += 31;
                    break;
            }
        }

        total_day += day;

        total_day %= 7;

        switch (total_day) {
            case 0:
                printf("Friday\n");
                break;
            case 1:
                printf("Saturday\n");
                break;
            case 2:
                printf("Sunday\n");
                break;
            case 3:
                printf("Monday\n");
                break;
            case 4:
                printf("Tuesday\n");
                break;
            case 5:
                printf("Wednesday\n");
                break;
            case 6:
                printf("Thursday\n");
                break;
        }
    }
}