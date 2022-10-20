#include <stdio.h>
#include <string.h>

void check(char line[], int testcase);

int main(void) {
    int testcase = 0;
    char line[81] = {0};

    scanf("%d", &testcase);

    for (int i = 0; i < testcase; i++) {
        getchar();

        scanf("%s", line);

        check(line, testcase);
    }
}

void check(char line[], int testcase) {
    int length = strlen(line);
    int flag = 0;

    for (int i = 1; i <= length; i++) { 
        // loop for each “phrase” incrementally
        // use i to count how long is the "phrase"
        if (length % i != 0) {
            continue;
        }

        for (int j = 0; j < i; j++) { // compare “phrase” to sentence to check for differences
            flag = 0;

            for (int x = 1; x < length / i; x++) { 
                // use length / i as the whole sentence is divided into i's period
                // if the criteria is met hence the output will be i, which is the shortest period
                if (((x * i) + j < length) && (line[j] != line[(x * i) + j])) {
                    flag = 1;
                    break;
                }
            }

            if (flag) {
                break;
            }
        }

        if ((!flag) && (testcase != 0)) {
            printf("%d\n\n", i);
            break;
        }
        else if ((!flag) && (testcase == 0)) {
            printf("%d\n", i);
            break;
        }
    }  

    if ((flag) && (testcase != 0)) {
        printf("%d\n\n", length);
    }
    else if ((flag) && (testcase == 0)) {
        printf("%d\n", length);
    }
}

//period = the length of the word that repeats
//extract a part of the line(start from just a letter)
//compare incrementally(the length of the number)