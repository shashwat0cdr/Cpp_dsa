#include <iostream>
#include <vector>
using namespace std;

int getPivot(vector<int>& nums, int n)
{
    int s = 0;
    int e = n - 1;

    while (s < e)
    {
        int mid = s + (e - s) / 2;

        if (nums[mid] > nums[e])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
    }

    return s;
}

int binarySearch(vector<int>& nums, int s, int e, int target)
{
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (nums[mid] == target)
            return mid;

        if (nums[mid] < target)
            s = mid + 1;
        else
            e = mid - 1;
    }

    return -1;
}

int search(vector<int>& nums, int target)
{
    int n = nums.size();
    int pivot = getPivot(nums, n);

    if (target >= nums[pivot] && target <= nums[n - 1])
        return binarySearch(nums, pivot, n - 1, target);

    return binarySearch(nums, 0, pivot - 1, target);
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    cout << "Array: ";
    for (int x : nums)
        cout << x << " ";

    cout << "\nTarget = " << target << endl;
    cout << "Pivot Index = " << getPivot(nums, nums.size()) << endl;
    cout << "Target Found At Index = " << search(nums, target) << endl;

    return 0;
}