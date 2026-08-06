#include <iostream>
#include <vector>
using namespace std;

void binary_sch(vector<int> &nums, int k)
{
    int s = 0;
    int n = nums.size();
    int e = n - 1;
    for (int i = 0; i < n; i++)
    {
        int mid = s + (e - s) / 2;
        if (nums[mid] < k)
        {
            s = mid + 1;
        }
        else if (nums[mid] > k)
        {
            e = mid - 1;
        }
        else
        {
            cout << "Element found at index: " << mid << endl;
            return;
        }
        mid = s + (e - s) / 2;
    }
    cout << "Element not found" << endl;
}

int main()
{
    vector<int> nums1 = {5, 12, 23, 34, 41, 45, 56, 67, 78, 88, 90};
    vector<int> nums2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> nums3 = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    binary_sch(nums1, 67);
    binary_sch(nums2, 8);
    binary_sch(nums3, 77);
    return 0;
}