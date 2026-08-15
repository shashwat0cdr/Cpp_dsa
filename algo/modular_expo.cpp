// modular exponentiation
/*
Input:
a = 2
b = 10
m = 1000

Output:
24
*/
#include <iostream>
using namespace std;

int modularExponentiation(int x, int n, int m)
{
    int res = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            // odd
            res = (1LL * (res) * (x) % m) % m;
        }
        x = (1LL* (x)%m * (x)%m)%m;
        n = n>>1;
    }
    return res;
}

int main()
{
    // Test Case 1
    int x1 = 2;
    int n1 = 10;
    int m1 = 1000;

    cout << "Test Case 1: "
         << modularExponentiation(x1, n1, m1)
         << endl;


    // Test Case 2
    int x2 = 3;
    int n2 = 13;
    int m2 = 7;

    cout << "Test Case 2: "
         << modularExponentiation(x2, n2, m2)
         << endl;

    return 0;
}
