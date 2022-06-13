#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

//cool and uncool number

int main(void) {
    int t;
    int testcase = 1;

    while (scanf("%d", &t) != EOF) {
        int count = 0;
        char c;

        getchar();

        while (t--) {
            bool number[31] = {};
            int check[26] = {};
            int tick = 0;
            int flag = 1;

            while ((c = getchar()) != '\n') {
                tick++;
                check[c - 'a']++;
            }


            for (int i = 0; i < 26; i++) {
                if (check[i]) {
                    if (tick == check[i] || number[check[i]]) {
                        flag = 0;
                        break;
                    }
                    else {
                        number[check[i]] = true;
                    }
                }
            }

            if (flag) {
                count++;
            }
        }

        printf("Case %d: %d\n", testcase++, count);
    }

}