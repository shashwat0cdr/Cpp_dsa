#include <iostream>
#include <vector>
using namespace std;

void moveZeros(vector<int> &nums)
{
    int nonZero = 0;
    int n = nums.size();
    for (int j = 0; j < n; j++)
    {
        if (nums[j] != 0)
        {
            swap(nums[nonZero], nums[j]);
            nonZero++;
        }
    }
}

void print_array(vector<int> &nums)
{
    for (size_t i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeros(nums);
    print_array(nums);
    return 0;
}