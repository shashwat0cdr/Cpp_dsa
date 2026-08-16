#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSums(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;
    while(low<high){
        int currentSum = nums[low]+nums[high];
        if (currentSum == target){
            return {low, high};
        }
        else if(currentSum < target ){
            low++;
        }
        else{
            high--;
        }
    }
    return {-1, -1};
}


int main()
{
    vector<int> nums = {1, 2, 3, 4, 6, 8, 10};
    int target = 10;

    vector<int> ans = twoSums(nums, target);

    if (ans[0] != -1)
    {
        cout << "Indices: " << ans[0] << " " << ans[1] << endl;
        cout << "Elements: " << nums[ans[0]] << " + "
             << nums[ans[1]] << " = " << target << endl;
    }
    else
    {
        cout << "No pair found";
    }

    return 0;
}