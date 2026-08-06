#include<iostream>
#include<vector>
using namespace std;

void rotate_array(vector<int> &nums, int k){
    vector<int> temp(nums.size());
    for (int i=0; i<nums.size(); i++){
        temp[(i+k)%nums.size()] = nums[i];
    }
    // copying the elements from temp to nums
    nums = temp;
}


int main(){
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;
    rotate_array(nums, k);
    cout << "Rotated array: ";
    for (int i=0; i<nums.size(); i++){
        cout << nums[i] << " ";
    }
    return 0;
}