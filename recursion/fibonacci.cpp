#include <iostream>
using namespace std;

int fibbonaci(int n)
{
    // base case
    if (n == 0)
    {
        return 0;
    }
    if (n == 1 || n == 2)
    {
        return 1;
    }
    return fibbonaci(n - 2) + fibbonaci(n - 1);
}
int main()
{
    int n;

    cout << "Enter n: ";
    cin >> n;

    cout << "Fibonacci term is: " << fibbonaci(n) << endl;

    return 0;
}