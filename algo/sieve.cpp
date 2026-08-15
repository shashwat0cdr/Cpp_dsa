// sieve of eratosthenes

#include <iostream>
#include <vector>
using namespace std;

int count_primes(int n)
{
    int cnt = 0;
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = 0;

    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
            cnt++;
            for (int j = 2 * i; j < n; j += i)
            {
                prime[j] = 0;
            }
        }
    }
    return cnt;
}

int main()
{
    // Test Case 1
    int n1 = 10;

    cout << "Number of primes less than "
         << n1 << " = "
         << count_primes(n1) << endl;

    // Test Case 2
    int n2 = 20;

    cout << "Number of primes less than "
         << n2 << " = "
         << count_primes(n2) << endl;

    return 0;
}