#include <iostream>
using namespace std;

class Solution
{
public:
    long long binarysearch(int n)
    {
        int s = 0;
        int e = n;
        long long ans = -1;

        while (s <= e)
        {
            long long mid = s + (e - s) / 2;
            long long sq = mid * mid;

            if (sq == n)
                return mid;

            if (sq < n)
            {
                ans = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }

        return ans;
    }

    int mySqrt(int x)
    {
        return (int)binarysearch(x);
    }
};

int main()
{
    Solution obj;

    int x;
    cout << "Enter number: ";
    cin >> x;

    cout << "Square Root = " << obj.mySqrt(x) << endl;

    return 0;
}
