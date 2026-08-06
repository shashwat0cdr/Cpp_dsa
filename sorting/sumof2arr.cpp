#include <iostream>
#include <vector>
using namespace std;

vector<int> reverse(vector<int> v)
{
    int s = 0;
    int e = v.size() - 1;

    while (s < e)
    {
        swap(v[s], v[e]);
        s++;
        e--;
    }

    return v;
}

vector<int> findArraySum(vector<int> &a, int n, vector<int> &b, int m)
{
    int i = n - 1;
    int j = m - 1;

    int carry = 0;

    vector<int> ans;

    while (i >= 0 && j >= 0)
    {
        int sum = a[i] + b[j] + carry;

        carry = sum / 10;
        sum = sum % 10;

        ans.push_back(sum);

        i--;
        j--;
    }

    while (i >= 0)
    {
        int sum = a[i] + carry;

        carry = sum / 10;
        sum = sum % 10;

        ans.push_back(sum);

        i--;
    }

    while (j >= 0)
    {
        int sum = b[j] + carry;

        carry = sum / 10;
        sum = sum % 10;

        ans.push_back(sum);

        j--;
    }

    while (carry != 0)
    {
        ans.push_back(carry % 10);
        carry /= 10;
    }

    return reverse(ans);
}

int main()
{
    vector<int> a = {1, 4, 3};
    vector<int> b = {5, 6, 7};

    vector<int> ans = findArraySum(a, a.size(), b, b.size());

    cout << "Sum = ";

    for (int x : ans)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}