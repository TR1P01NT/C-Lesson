#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int m, n, run, solution_space = 0, input_space = 0, len, flag = 0, charcount = 0, line_error = 0;
int solution_newline[100], input_newline[100];
char solution[100][120], input[100][120];
char check1[12000], check2[12000];
char *words;

void whitespace(); //find whitespace and count the number of characters in solution and input; put words into check1 and check2

int main(void) {
    run = 1;
    while (1) {
        scanf("%d", &n);
        getchar();

        if (n == 0) {
            break;
        }

        memset(solution, 0, sizeof(solution));
        memset(input, 0, sizeof(input));
        memset(check1, 0, sizeof(check1));
        memset(check2, 0, sizeof(check2));
        memset(solution_newline, 0, sizeof(solution_newline));
        memset(input_newline, 0, sizeof(input_newline));

        flag = 0;
        line_error = 0;
        
        for (int i = 0; i < n; i++) {
            fgets(solution[i], 120, stdin);
            solution_newline[i] = strcspn(solution[i], "\n"); // find the location of newline character in the string
            solution[i][strcspn(solution[i], "\n")] = 0; //set the location of the newline character to zero
        }

        scanf("%d", &m);
        getchar();
        
        for (int j = 0; j < m; j++) {
            fgets(input[j], 120, stdin);
            input_newline[j] = strcspn(input[j], "\n"); // find the location of newline character in the string
            input[j][strcspn(input[j], "\n")] = 0; //set the location of the newline character to zero
        }
        
        whitespace();

        if (strcmp(check1, check2) != 0) {
            flag = 1;
        }

        for (int i = 0; i < 100; i++) {
            if (solution_newline[i] != input_newline[i]) {
                line_error++; //check if there is different in the location of newline character between solution and input
            }
        }
        
        if (flag == 0) {
            if (solution_space == input_space && line_error == 0) {
                printf("Run #%d: Accepted %d\n", run, charcount);
            }
            else {
                printf("Run #%d: Presentation Error %d\n", run, charcount);
            }
        }
        else {
            printf("Run #%d: Wrong Answer %d\n", run, charcount);
        }

        run++;
    }
}

void whitespace() {
    solution_space = input_space = 0;
    charcount = 0;

    for (int i = 0; i < n; i++) {
        len = strlen(solution[i]);
        for (int j = 0; j < len; j++) {
            if (solution[i][j] == ' ') {
                solution_space++;
            }
        charcount++;
        }

        words = strtok(solution[i], " "); // separate string into words by the condition(character) set in the function strtok
        while (words != NULL) {
            strcat(check1, words);
            words = strtok(NULL, " "); // until NULL
        }

        solution_space++;
    }

    for (int i = 0; i < m; i++) {
        len = strlen(input[i]);
        for (int j = 0; j < len; j++) {
            if (input[i][j] == ' ') {
                input_space++;
            }
        }

        words = strtok(input[i], " "); // separate string into words by the condition(character) set in the function strtok
        while (words != NULL) {
            strcat(check2, words);
            words = strtok(NULL, " "); // until NULL
        }

        input_space++;
    }

}

