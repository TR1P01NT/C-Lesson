#include <iostream>
#include <stdio.h>
#include <cctype>

int main(void) {
    char line[31];
    char al[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int t;
    int testcase = 1;

    std::cin >> t;

    while (t != EOF) {
        int count = 0;

        for (int i = 0; i < t; i++) {
            int check[26] = {0};
            int flag = 0;
            int tick = 0;

            getchar();

            char c;

            while ((c = getchar())) {
                if (c != '\n') {
                    if (isalpha(c)) {
                        for (int j = 0; j < 26; j++) {
                            if (c == al[j]) {
                                tick++;
                                check[j]++;
                            }
                        }
                    }
                }
                else {
                    break;
                }
            }

            for (int a = 0; a < 26; a++) {
                for (int b = a + 1; b < 26; b++) {
                    if ((check[a] == check[b]) && (check[a] + check[b] > 0)) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 1) {
                    break;
                }
            }

            if (flag == 0) {
                count++;
            }
            if (tick == 0) {
                count--;
            }
        }

        std::cout << "Case " << testcase << ": " << count << std::endl;

        testcase++;
        std::cin >> t;
    }

}