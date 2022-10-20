#include <stdio.h>
#include <string.h>

typedef struct {
    char star;
    int minutes;
    char name[20];
} queue;

typedef struct {
    char name[20];
} idol;

idol a[50];
idol k[50];
idol b[50];
int time = 0;
int people = 0;
queue lineup[100];

int main(void) {
    int a_counter = 0;
    int k_counter = 0;
    int b_counter = 0;
    int a_time = 0;
    int k_time = 0;
    int b_time = 0;
    int a_set = 1;
    int k_set = 1;
    int b_set = 1;
    int present = 0;

    scanf("%d %d", &time, &people);

    for (int i = 0; i < people; i++) {
        scanf("%s %d %s", &lineup[i].star, &lineup[i].minutes, lineup[i].name);
    }

    for (int i = 0; i < people; i++) {
        if (lineup[i].star == 'A') {
            if (a_set) {
                if ((lineup[i].minutes + i) > time) {
                    for (int x = 0; x < a_counter; x++) {
                        if (strcmp(a[x].name, lineup[i].name) == 0) {
                            present = 1;
                            break;
                        }
                    }
                    
                    if (present == 0) {
                        strcpy(a[a_counter].name, lineup[i].name);
                        a_counter++;
                    }
                    else {
                        present = 0;
                    }
                }
                else {
                    a_time += (lineup[i].minutes + i);
                }
                a_set = 0;
            }
            else {
                int extra = i - a_time;
                if (extra > 0) {
                    a_time += extra;
                }

                if ((lineup[i].minutes + a_time) > time) {
                    for (int x = 0; x < a_counter; x++) {
                        if (strcmp(a[x].name, lineup[i].name) == 0) {
                            present = 1;
                            break;
                        }
                    }
                    
                    if (present == 0) {
                        strcpy(a[a_counter].name, lineup[i].name);
                        a_counter++;
                    }
                    else {
                        present = 0;
                    }
                }
                else {
                    a_time += lineup[i].minutes;
                }
            }
        }
        else if (lineup[i].star == 'K') {
            if (k_set) {
                if ((lineup[i].minutes + i) > time) {
                    for (int x = 0; x < k_counter; x++) {
                        if (strcmp(k[x].name, lineup[i].name) == 0) {
                            present = 1;
                            break;
                        }
                    }
                    
                    if (present == 0) {
                        strcpy(k[k_counter].name, lineup[i].name);
                        k_counter++;
                    }
                    else {
                        present = 0;
                    }
                }
                else {
                    k_time += (lineup[i].minutes + i);
                }
                k_set = 0;
            }
            else {
                int extra = i - k_time;
                if (extra > 0) {
                    k_time += extra;
                }

                if ((lineup[i].minutes + k_time) > time) {
                    for (int x = 0; x < k_counter; x++) {
                        if (strcmp(k[x].name, lineup[i].name) == 0) {
                            present = 1;
                            break;
                        }
                    }
                    
                    if (present == 0) {
                        strcpy(k[k_counter].name, lineup[i].name);
                        k_counter++;
                    }
                    else {
                        present = 0;
                    }
                }
                else {
                    k_time += lineup[i].minutes;
                }
            }
        }
        else if (lineup[i].star == 'B') {
            if (b_set) {
                if ((lineup[i].minutes + i) > time) {
                    for (int x = 0; x < b_counter; x++) {
                        if (strcmp(b[x].name, lineup[i].name) == 0) {
                            present = 1;
                            break;
                        }
                    }
                    
                    if (present == 0) {
                        strcpy(b[b_counter].name, lineup[i].name);
                        b_counter++;
                    }
                    else {
                        present = 0;
                    }
                }
                else {
                    b_time += (lineup[i].minutes + i);
                }
                b_set = 0;
            }
            else {
                int extra = i - b_time;
                if (extra > 0) {
                    b_time += extra;
                }

                if ((lineup[i].minutes + b_time) > time) {
                    for (int x = 0; x < b_counter; x++) {
                        if (strcmp(b[x].name, lineup[i].name) == 0) {
                            present = 1;
                            break;
                        }
                    }
                    
                    if (present == 0) {
                        strcpy(b[b_counter].name, lineup[i].name);
                        b_counter++;
                    }
                    else {
                        present = 0;
                    }
                }
                else {
                    b_time += lineup[i].minutes;
                }
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
}