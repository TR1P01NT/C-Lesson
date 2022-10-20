#include <stdio.h>
#include <string.h>

int isvowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return 1;
    }
    else {
        return 0;
    }
}

int main(void) {
    int testcase;
    char a[100], b[100];

    scanf("%d", &testcase);

    for (int i = 0; i < testcase; i++) {
        scanf("%s", a);
        scanf("%s", b);

        if ((strlen(a)) != (strlen(b))) {
            printf("No\n");
            continue;     
        }

        int flag = 1;

        for (int j = 0; j < (strlen(a)); j++) {
            if (a[j] == b[j]) {
                continue;
            }
            if (isvowel(a[j]) && isvowel(b[j])) {
                continue;
            }
            flag = 0;
            break;
        }

        if (flag) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }
}