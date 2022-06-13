#include <iostream>

//number generator

int main(void) {
    int t;

    std::cin >> t;

    for (int i = 0; i < t; i++) {
        int n, f, temp;

        std::cin >> n;

        for (int j = n - 50; j < n; j++) {
            temp = j;

            f = j;

            for (int k = temp; k > 0;) {
                f += k % 10;
                k /= 10;
            }

            if (f == n) {
                break;
            }
        }

        if (f == n) {
            std::cout << temp << std::endl;
        }
        else {
            std::cout << 0 << std::endl;
        }
    }
}