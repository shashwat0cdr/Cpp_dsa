#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums, int n, int m, int mid) {

        int arrcount = 1;
        int sum_arr = 0;

        for (int i = 0; i < n; i++) {

            if (sum_arr + nums[i] <= mid) {
                sum_arr += nums[i];
            }
            else {

                arrcount++;

                if (arrcount > m || nums[i] > mid)
                    return false;

                sum_arr = nums[i];
            }
        }

        return true;
    }

    int splitArray(vector<int>& nums, int k) {

        int n = nums.size();

        int s = *max_element(nums.begin(), nums.end());

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        int e = sum;
        int ans = -1;

        while (s <= e) {

            int mid = s + (e - s) / 2;

            if (isPossible(nums, n, k, mid)) {
                ans = mid;
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    // Test Case 1
    vector<int> nums1 = {7, 2, 5, 10, 8};
    int k1 = 2;

    cout << "Test Case 1" << endl;
    cout << "Answer = " << obj.splitArray(nums1, k1) << endl;
    cout << "Expected = 18" << endl << endl;

    // Test Case 2
    vector<int> nums2 = {1, 2, 3, 4, 5};
    int k2 = 2;

    cout << "Test Case 2" << endl;
    cout << "Answer = " << obj.splitArray(nums2, k2) << endl;
    cout << "Expected = 9" << endl;

    return 0;
}