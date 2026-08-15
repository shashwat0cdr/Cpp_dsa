// gcd

#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    if (b == 0)
    {
        return a;
    }
    while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    return a;
}

int main()
{
    // Test Case 1
    int a1 = 48;
    int b1 = 18;

    cout << "GCD of " << a1 << " and " << b1
         << " = " << gcd(a1, b1) << endl;


    // Test Case 2
    int a2 = 60;
    int b2 = 24;

    cout << "GCD of " << a2 << " and " << b2
         << " = " << gcd(a2, b2) << endl;

    return 0;
}