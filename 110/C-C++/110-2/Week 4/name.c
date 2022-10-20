#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    int n = 0, flag = 0, count = 0;
    char t1[21][21] = {0}, t2[21][21] = {0};

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", t1[i]);
        scanf("%s", t2[i]);

        int l1 = strlen(t1[i]);
        int l2 = strlen(t2[i]);

        count = 0;

        if (l1 == l2) {
            for (int j = 0; j < l1; j++, count++) {
                char c1 = t1[i][j];
                char c2 = t2[i][j];

                if (c1 != c2) {
                    char compare1 = toupper(c1);
                    char compare2 = toupper(c2);
                    if (((compare1 == 'A') || (compare1 == 'E') || (compare1 == 'I') || (compare1 == 'O') || (compare1 == 'U')) && ((compare2 == 'A') || (compare2 == 'E') || (compare2 == 'I') || (compare2 == 'O') || (compare2 == 'U'))) {
                        flag = 0;
                    }
                    else {
                        flag = 1;
                    }
                }

                if (flag == 1) {
                    printf("No\n");
                    break;
                }
            }            
        }
        else {
            printf("No\n");
        }

        if (flag == 0 && count == l1) {
            printf("Yes\n");
        }
    }
}