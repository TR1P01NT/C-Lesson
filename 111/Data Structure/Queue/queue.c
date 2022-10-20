#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check();

typedef struct {
    char star;
    int minutes;
    char name[20];
} queue;

struct idol {
    char name[20];
};

struct idol a[50];
struct idol k[50];
struct idol b[50];
int time = 0;
int people = 0;
int final_a = 0;
int final_k = 0;
int final_b = 0;
queue lineup[50];

int main(void) {
    int a_counter = 0;
    int k_counter = 0;
    int b_counter = 0;
    int timer = 0;

    scanf("%d %d", &time, &people);

    for (int i = 0; i < people; i++) {
        scanf("%s %d %s", &lineup[i].star, &lineup[i].minutes, lineup[i].name);
    }

    for (int i = 0; i < people; i++) {
        if (lineup[i].minutes + timer > time) {
            if (lineup[i].star == 'A') {
                strcpy(a[a_counter].name, lineup[i].name);
                // a[a_counter].duration = lineup[i].minutes;
                // a[a_counter].enter_queue = i;
                a_counter++;
            }
            else if (lineup[i].star == 'K') {
                strcpy(k[k_counter].name, lineup[i].name);
                // k[k_counter].duration = lineup[i].minutes;
                // k[k_counter].enter_queue = i;
                k_counter++;
            }
            else if (lineup[i].star == 'B') {
                strcpy(b[b_counter].name, lineup[i].name);
                // b[b_counter].duration = lineup[i].minutes;
                // b[b_counter].enter_queue = i;
                b_counter++;
            }
        }

        timer++;
    }

    for (int i = 0; i < a_counter; i++) {
        for (int j = i + 1; j < a_counter; j++) {
            if (strcmp(a[i].name, a[j].name) == 0) {
                a[j].name[0] = '\0';
                for (int k = j + 1; k < a_counter; k++) {
                    strcpy(a[k - 1].name, a[k].name);
                }
                --a_counter;
            }
        }
    }

    for (int i = 0; i < k_counter; i++) {
        for (int j = i + 1; j < k_counter; j++) {
            if (strcmp(k[i].name, k[j].name) == 0) {
                k[j].name[0] = '\0';
                for (int x = j + 1; x < k_counter; x++) {
                    strcpy(k[x - 1].name, k[x].name);
                }
                --k_counter;
            }
        }
    }

    for (int i = 0; i < b_counter; i++) {
        for (int j = i + 1; j < b_counter; j++) {
            if (strcmp(b[i].name, b[j].name) == 0) {
                b[j].name[0] = '\0';
                for (int x = j + 1; x < b_counter; x++) {
                    strcpy(b[x - 1].name, b[x].name);
                }
                --b_counter;
            }
        }
    }

    if (a_counter == 0) {
        printf("A: .\n");
    }
    else {
        printf("A:");
        for (int i = 0; i < a_counter; i++) {
            printf(" %s", a[i].name);
        }
        printf(".\n");
    }

    if (k_counter == 0) {
        printf("K: .\n");
    }
    else {
        printf("K:");
        for (int i = 0; i < k_counter; i++) {
            printf(" %s", k[i].name);
        }
        printf(".\n");
    }

    if (b_counter == 0) {
        printf("B: .\n");
    }
    else {
        printf("B:");
        for (int i = 0; i < b_counter; i++) {
            printf(" %s", b[i].name);
        }
        printf(".\n");
    }

    // check();

    // if (final_a == 0) {
    //     printf("A: .\n");
    // }
    // else {
    //     printf("A: ");
    //     for (int i = final_a; i <= a_counter; i++) {
    //         printf("%s", a[i].name);
    //     }
    //     printf(".\n");
    // }

    // if (final_k == 0) {
    //     printf("K: .\n");
    // }
    // else {
    //     printf("K: ");
    //     for (int i = final_k; i <= k_counter; i++) {
    //         printf("%s", k[i].name);
    //     }
    //     printf(".\n");
    // }

    // if (final_b == 0) {
    //     printf("B: .\n");
    // }
    // else {
    //     printf("B: ");
    //     for (int i = final_b; i <= b_counter; i++) {
    //         printf("%s", b[i].name);
    //     }
    //     printf(".\n");
    // }
    
}

// void check() {
//     int a_current = 0;
//     int k_current = 0;
//     int b_current = 0;
//     int a_time = 0;
//     int k_time = 0;
//     int b_time = 0;
//     int a_current_time = 0;
//     int k_current_time = 0;
//     int b_current_time = 0;
//     int timer = 0;

//     for (int i = 0; timer < time; i++, timer++) {
//         if (a[a_current].enter_queue == i) {
//             a_current_time = a[a_current].duration;
//             a_current++;
//         }
//         if (a_current_time != 0) {
//             a_time++;
//         }
//         if (a_time > time) {
//             final_a = a_current;
//         }

//         if (k[k_current].enter_queue == i) {
//             k_time += k[k_current].duration;
//             if (k_time > time) {
//                 final_k = k_current;
//             }
//             k_current++;
//         }
        
//         if (b[b_current].enter_queue == i) {
//             b_time += b[b_current].duration;
//             if (b_time > time) {
//                 final_b = b_current;
//                 printf("%d\n", b_time);
//             }
//             b_current++;
//         }
//     }
// }