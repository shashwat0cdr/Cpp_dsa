#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &arr, int m, int mid)
    {
        int ballCount = 1;
        int lastPos = arr[0];

        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] - lastPos >= mid)
            {
                ballCount++;
                lastPos = arr[i];

                if (ballCount == m)
                {
                    return true;
                }
            }
        }
        return false;
    }

    int maxDistance(vector<int> &arr, int m)
    {

        sort(arr.begin(), arr.end());

        // Search Space
        int s = 1;
        int e = arr.back() - arr.front();

        int ans = -1;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (isPossible(arr, m, mid))
            {
                ans = mid;
                s = mid + 1; // Try for larger minimum distance
            }
            else
            {
                e = mid - 1;
            }
        }

        return ans;
    }
};

int main()
{

    Solution obj;

    // Test Case 1
    vector<int> arr1 = {1, 2, 3, 4, 7};
    int m1 = 3;

    cout << "Test Case 1 Answer = "
         << obj.maxDistance(arr1, m1) << endl;

    // Test Case 2
    vector<int> arr2 = {5, 4, 3, 2, 1, 1000000000};
    int m2 = 2;

    cout << "Test Case 2 Answer = "
         << obj.maxDistance(arr2, m2) << endl;

    return 0;
}