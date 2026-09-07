#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:

    void solve(vector<int> nums, vector<int> output, int index,
               vector<vector<int>>& ans) {

        // Base case
        if (index >= nums.size()) {
            ans.push_back(output);
            return;
        }

        // Exclude
        solve(nums, output, index + 1, ans);

        // Include
        int element = nums[index];
        output.push_back(element);

        solve(nums, output, index + 1, ans);
    }

public:

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;

        solve(nums, output, index, ans);

        return ans;
    }
};

int main() {

    // Input array
    vector<int> nums = {1, 2, 3};

    // Create object
    Solution obj;

    // Get all subsets
    vector<vector<int>> ans = obj.subsets(nums);

    // Print subsets
    cout << "All subsets are:" << endl;

    for (int i = 0; i < ans.size(); i++) {

        cout << "[ ";

        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }

        cout << "]" << endl;
    }

    return 0;
}