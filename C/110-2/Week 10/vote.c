#include <stdio.h>

int main(void) {
    int testcase, people;
    int number;
    char candidate[21][81];
    int choice[1001][21] = {0};
    int result[21][1001];
    char num[1001];
    int vote[21];

    scanf("%d", &testcase);

    getchar();

    while (testcase--) {
        scanf("%d", &people);

        getchar();

        for (int i = 0; i < people; i++) {
            gets(candidate[i]);
            vote[i] = 0;
        }

        number = 0;
        while (gets(num) && num[0]) {
            // if (!num[0]) {
            //     break;
            // }

            int value = 0, count = 0;

            //get the choices of people

            for (int i = 0; num[i]; i++) {
                if ((num[i] >= '0') && (num[i] <= '9')) {
                    value *= 10;
                    value += num[i] - '0';
                }
                else {
                    choice[number][count++] = value - 1;
                    value = 0;
                }
            }
            choice[number++][count++] = value - 1;
        }

        for (int i = 0; i < number; i++) {
            int cand = choice[i][0];
            result[cand][vote[cand]++] = i;
        }

        //find the maximum and minimum voting result

        while (1) {
            int max = 0, min = 1001, max_space, min_space;

            for (int i = 0; i < people; i++) {
                if (vote[i]) {
                    if (max < vote[i]) {
                        max = vote[i];
                        max_space = i;
                    }
                    if (min > vote[i]) {
                        min = vote[i];
                        min_space = i;
                    }
                }
            }

            //check if the voting result is equal or greater than 50%
            if (max * 2 >= number) {
                break;
            }

            if (max == min) {
                break;
            }

            //begin to remove the candidate with the least number of votes and rearrange the votes

            for (int k = 0; k < people; k++) {
                if (vote[k] != min) {
                    continue;
                }

                for (int i = 0; i < vote[k]; i++) {
                    int peer = result[k][i];
                    
                    for (int j = 0; j < people; j++) {
                        int person = choice[peer][j];

                        if ((vote[person] != min) && vote[person]) {
                            result[person][vote[person]++] = peer;
                            break;
                        }
                    }
                }
                vote[k] = 0;
            }
        }

        int maxi = 0;

        for (int i = 0; i < people; i++) {
            if (vote[maxi] < vote[i]) {
                maxi = i;
            }
        }

        for (int i = 0; i < people; i++) {
            if (vote[maxi] == vote[i]) {
                printf("%s\n", candidate[i]);
            }
        }

        if (testcase) {
            puts("");
        }
    }
}

/*
    1 2 3
    2 1 3
    2 3 1
    3 1 2
    1 2 3

    as 3 is the one with the least number of votes, hence remove 3 and rearrange the votes

    and it will become

    1 2
    2 1
    2 1
    1 2
    1 2

    so now the first person will be the one with the most number of votes, hence the first candidate won the election
*/