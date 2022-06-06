#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[11];
    int score;
    char gender[6];
} Student;

int main()
{
    Student a[4];
    
    const char delimiter[2] = "\t";
    char input[100];
    
    int femaleHigh = 0;
    int femaleHighIndex = 0;
    
    int maleHigh = 0;
    int maleHighIndex = 0;

    for (int i = 0; i < 4; i++) {
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = 0;

        memset(a[i].name, 0, sizeof(a[i].name));
        memset(a[i].gender, 0, sizeof(a[i].gender));
        
        strncpy(students[i].name, strtok(input, delimiter), 10);
        students[i].score = atoi(strtok(NULL, delimiter));
        strncpy(students[i].gender, strtok(NULL, delimiter), 6);
        
        if(femaleHigh < students[i].score && !strcmp(students[i].gender, "Female")) {
            femaleHigh = students[i].score;
            femaleHighIndex = i;
        }
        
        if(maleHigh < students[i].score && !strcmp(students[i].gender, "Male")) {
            maleHigh = students[i].score;
            maleHighIndex = i;
        }
    }
    
    printf("%s %d %s\n", students[femaleHighIndex].name, students[femaleHighIndex].score, students[femaleHighIndex].gender);
    printf("%s %d %s", students[maleHighIndex].name, students[maleHighIndex].score, students[maleHighIndex].gender);
   
    return 0;
}