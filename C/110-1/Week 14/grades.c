//C++

#include<stdio.h>

#define STUDENTS 3
#define EXAMS 4 

void printArray(const int grades[][EXAMS], size_t pupils, size_t tests);
void minimum(const int grades[][EXAMS], size_t pupils, size_t tests);
void maximum(const int grades[][EXAMS], size_t pupils, size_t tests);
void average(const int grades[][EXAMS], size_t pupils, size_t tests);

int main(void) {
    int choice = 0;
    void (*f[4])(const int grades[][EXAMS], size_t pupils, size_t tests) = {printArray, minimum, maximum, average};

    scanf("%d", &choice);
    
    int studentGrades[STUDENTS][EXAMS] =  
        { { 77, 68, 86, 73 },
          { 96, 87, 89, 78 },
          { 70, 90, 86, 81 } };
    
    while(choice >= 0 && choice < 4) {
        (*f[choice])(studentGrades, STUDENTS, EXAMS);
        scanf("%d", &choice);
    }
}

void minimum(const int grades[][EXAMS], size_t pupils, size_t tests) {
    int min = 100;

    for(int i = 0; i < pupils; ++i) {
        for(int j = 0; j < tests; ++j) {
            if(grades[i][j] <= min) {
                min = grades[i][j];
            }
        }
    }

    printf("%d\n", min);
} 

void maximum(const int grades[][EXAMS], size_t pupils, size_t tests) {
    int max = 0;

    for(int i = 0; i < pupils; ++i) {
        for(int j = 0; j < tests; ++j) {
            if(grades[i][j] >= max) {
                max = grades[i][j];
            }
        }
    }

    printf("%d\n", max);
} 

void average(const int grades[][EXAMS], size_t pupils, size_t tests) {                                                      
    int total[3] = {0};
    float average[3] = {0};

    for(int i = 0; i < pupils; ++i) {
        for(int j = 0; j < tests; ++j) {
            total[i] += grades[i][j];
        }
    }

    for(int i = 0; i < pupils; ++i) {
        average[i] = (double)total[i] / tests;
    }

    for(int i = 0; i < pupils; i++) {
        printf("Student %u average %.2f\n",i, average[i]);
    }
} 

void printArray(const int grades[][EXAMS], size_t pupils, size_t tests) {
    printf("%s", "                 [0]  [1]  [2]  [3]");

    for (size_t i = 0; i < pupils; ++i) {

        printf("\nstudentGrades[%zu] ", i);

        for (int j = 0; j < tests; ++j) {
            printf("%-5d", grades[i][j]);
        } 
    }
    printf("\n");
}