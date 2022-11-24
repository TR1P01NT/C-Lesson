#include <stdio.h>
#include <string.h>

typedef struct {
    char idol;
    int minutes;
    char name[20];
} queue;

queue a[50];
queue k[50];
queue b[50];
queue current_input;

int main(void) {
    int time = 0;
    int people = 0;
    int a_counter = 0;
    int k_counter = 0;
    int b_counter = 0;
    int a_index = 0;
    int k_index = 0;
    int b_index = 0;

    scanf("%d %d", &time, &people);

    for (; people > 0 || time > 0; time--) {
        if (people > 0) {
            scanf("%s %d %s", &current_input.idol, &current_input.minutes, current_input.name);

            if (current_input.idol == 'A') {
                a[a_counter] = current_input;
                a_counter++;
            } else if (current_input.idol == 'K') {
                k[k_counter] = current_input;
                k_counter++;
            } else if (current_input.idol == 'B') {
                b[b_counter] = current_input;
                b_counter++;
            }
            people--;
            
            if (time <= 0) {
                break;
            }
        }

        if (a[a_index].minutes > 0) {
            a[a_index].minutes--;

            if (a[a_index].minutes == 0) {
                a_index++;
            }
        }

        if (k[k_index].minutes > 0) {
            k[k_index].minutes--;

            if (k[k_index].minutes == 0) {
                k_index++;
            }
        }

        if (b[b_index].minutes > 0) {
            b[b_index].minutes--;

            if (b[b_index].minutes == 0) {
                b_index++;
            }
        }
    }

    char a_duplicate[20] = "";
    char k_duplicate[20] = "";
    char b_duplicate[20] = "";

    if (a_index == a_counter) {
        printf("A: .\n");
    }
    else {
        printf("A:");
        for (int i = a_index; i < a_counter; i++) {
            if (strcmp(a_duplicate, a[i].name) == 0) {
                i++;
                continue;
            }

            printf(" %s", a[i].name);
            strcpy(a_duplicate, a[i].name);
        }
        printf(".\n");
    }

    if (k_index == k_counter) {
        printf("K: .\n");
    }
    else {
        printf("K:");
        for (int i = k_index; i < k_counter; i++) {
            if (strcmp(k_duplicate, k[i].name) == 0) {
                i++;
                continue;
            }

            printf(" %s", k[i].name);
            strcpy(k_duplicate, k[i].name);
        }
        printf(".\n");
    }

    if (b_index == b_counter) {
        printf("B: .\n");
    }
    else {
        printf("B:");
        for (int i = b_index; i < b_counter; i++) {
            if (strcmp(b_duplicate, b[i].name) == 0) {
                i++;
                continue;
            }

            printf(" %s", b[i].name);
            strcpy(b_duplicate, b[i].name);
        }
        printf(".\n");
    }
}