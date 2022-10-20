#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int run = 0;
    int status = 0;
    int last_parenthesis = 0;
    int parenthesis_count = 0;
    // 0 ()
    // 1 []
    // 2 {}

    scanf("%d", &run);

    for (int i = 0; i < run; i++) {
        int place = 0;
        status = 0;

        char line[50] = {0};
        char stack[20] = {0};

        scanf("%s", line);

        int line_len = strlen(line);

        for (int j = 0; j < line_len; j++) {
            if (line[j] == '(' || line[j] == '[' || line[j] == '{') {
                if (place > 0) {
                    switch (last_parenthesis) {
                        case 0:
                            if (line[j] == '[' || line[j] == '{') {
                                status = 1;
                            }
                            break;
                        case 1:
                            if (line[j] == '{') {
                                status = 1;
                            }
                            break;
                    }
                }

                if (line[j] == '(') {
                    last_parenthesis = 0;
                }
                else if (line[j] == '[') {
                    last_parenthesis = 1;
                } 
                else if (line[j] == '{') {
                    last_parenthesis = 2;
                }

                stack[place] = line[j];
                place++;
                parenthesis_count++;
            }
            else if (line[j] == ')' || line[j] == ']' || line[j] == '}') {
                if (place == 0) {
                    status = 1;
                    break;
                }
                else if (line[j] == ')' && stack[place - 1] == '(') {
                    place--;
                    stack[place] = 0;
                    parenthesis_count--;
                    if (place >= 2) {
                        switch (stack[place - 2]) {
                            case '(':
                                last_parenthesis = 0;
                                break;
                            case '[':
                                last_parenthesis = 1;
                                break;
                            case '{':
                                last_parenthesis = 2;
                                break;
                        }
                    }
                }
                else if (line[j] == ']' && stack[place - 1] == '[') {
                    place--;
                    stack[place] = 0;
                    parenthesis_count--;
                    if (place >= 2) {
                        switch (stack[place - 2]) {
                            case '[':
                                last_parenthesis = 1;
                                break;
                            case '{':
                                last_parenthesis = 2;
                                break;
                        }
                    }
                }
                else if (line[j] == '}' && stack[place - 1] == '{') {
                    place--;
                    stack[place] = 0;
                    parenthesis_count--;
                    if (place >= 2) {
                        switch (stack[place - 2]) {
                            case '{':
                                last_parenthesis = 2;
                                break;
                        }
                    }
                }
                else {
                    status = 1;
                    break;
                }
            }
        }

        
        for (int i = 0; i < 20; i++) {
            if (stack[i] != 0) {
                status = 1;
                break;
            }
        }

        if (status) {
            printf("wrong\n");
        }
        else {
            printf("correct\n");
        }
    }
}