#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <iterator>
using namespace std;

const int N = 1e7;

bool check[N];
void prime_number_initiate() {
    for(int i = 2; i <= sqrt(N); ++i){
        for(int j = 2 * i; j < N; j += i)
            check[j] = 1;
    }
}

int main(void) {
    int testcase;
    
    prime_number_initiate();

    cin >> testcase;

    check[1] = check[0] = 1;

    for (int x = 0; x < testcase; ++x) {
        string s;
        cin >> s;

        sort(s.begin(), s.end()); //sort the string

        set<int> res; //store unique elements and also in a sorted manner

        for (int i = 1; i < (1 << s.size()); ++i) { // enumerate subset, bitwise operation

            string tmp = "";
            for (int j = 0; j < (int)s.size(); ++j) {
                if (i >> j & 1) { //bitwise operation
                    tmp += s[j];
                }
            }

            do {
                int num = stoi(tmp);
                if (check[num] || res.count(num)) { //count the number of the specific element
                    continue;
                }
                res.insert(num); //insert element into the vector?
            }while (next_permutation(tmp.begin(), tmp.end())); //排列與組合

        }

        cout << res.size() << "\n";
    }
}