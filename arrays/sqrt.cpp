#include <iostream>
using namespace std;

long long int sqrtinteger(int n)
{
    int s = 0;
    int e = n;
    long long int m = s + (e - s) / 2;
    long long int ans = -1;
    while (s <= e)
    {
        long long int sq = m * m;

        if (sq == n)
        {
            return m;
        }
        if (sq < n)
        {
            ans = m;
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
        m = s + (e - s) / 2;
    }
    return ans;
}

double morePrecision(int n, int precision, int tempsol)
{

    double factor = 1;
    double ans = tempsol;
    for (int i = 0; i < precision; i++)
    {
        factor = factor / 10;
        for (double j = ans; j * j < n; j += factor)
        {
            ans = j;
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter number: ";
    cin >> n;
    int tempsol = sqrtinteger(n);
    cout << "answer is:  " << morePrecision(n, 3, tempsol) << endl;

    return 0;
}
