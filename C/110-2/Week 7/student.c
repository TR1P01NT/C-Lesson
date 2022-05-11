#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student{
    char name[20];
    int score;
    char gender[6];
};

int main(void) {
    struct student a[100];
    int count = 0, m = 0, f = 0;
    char m_max;
    int m_max_score = 0;
    char f_max;
    int f_max_score = 0;
    char *sex = "Male";

    while ((scanf("%[^\t]", a[count].name)) != EOF) {
        scanf("%d %s\n", &a[count].score, a[count].gender);
        count++;
    }

    for (int i = 0; i < count; i++) {
        if ((a[i].score >= m_max_score) || (a[i].score >= f_max_score)) {
            if (!strcmp(a[i].gender, sex)) {
                m_max_score = a[i].score;
                m_max = i;
            }
            else {
                f_max_score = a[i].score;
                f_max = i;
            }
        }
    }

    if (m_max_score > f_max_score) {
        printf("%s %d %s\n", a[m_max].name, m_max_score, a[m_max].gender);
        printf("%s %d %s\n", a[f_max].name, f_max_score, a[f_max].gender);
    }
    else {
        printf("%s %d %s\n", a[f_max].name, f_max_score, a[f_max].gender);
        printf("%s %d %s\n", a[m_max].name, m_max_score, a[m_max].gender);
    }


}