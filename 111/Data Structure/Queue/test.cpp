#include <iostream>
using namespace std;

int main(void)
{
    int m, n, ticket, index = 0;
    cin >> m >> n;
    string idol, name;
    string a = "A:", k = "K:", b = "B:";
    for (int i = 0; i < n; i++)
    {
        cin >> idol >> ticket >> name;
        if (ticket + index > m)
        {
            if (idol == "A")
                a += " " + name;
            else if (idol == "K")
                k += " " + name;
            else if (idol == "B")
                b += " " + name;
        }
        index++;
    }
    if (a == "A:")
        cout << a << " ." << endl;
    else
        cout << a << "." << endl;
    if (k == "K:")
        cout << k << " ." << endl;
    else
        cout << k << "." << endl;
    if (b == "B:")
        cout << b << " ." << endl;
    else
        cout << b << "." << endl;
}