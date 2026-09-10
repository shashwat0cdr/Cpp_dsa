#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    void solve(vector<int> nums, vector<vector<int>> &ans, int index)
    {

        // Base case
        if (index >= nums.size())
        {
            ans.push_back(nums);
            return;
        }

        // Try every element at current position
        for (int j = index; j < nums.size(); j++)
        {

            // Swap
            swap(nums[index], nums[j]);

            // Recursive call
            solve(nums, ans, index + 1);

            // Backtrack
            swap(nums[index], nums[j]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;

        solve(nums, ans, 0);

        return ans;
    }
};

int main()
{

    Solution obj;

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<vector<int>> ans = obj.permute(nums);

    cout << "\nPermutations are:\n";

    for (vector<int> permutation : ans)
    {
        for (int x : permutation)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}