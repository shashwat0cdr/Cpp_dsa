#include <iostream>
using namespace std;

bool binarySearch(int *arr, int s, int e, int key)
{

    // base case
    if (s > e)
    {
        return false;
    }
    int mid = s + (e - s) / 2;
    if (arr[mid] == key)
    {
        return true;
    }
    if (arr[mid] < key)
    {
        return binarySearch(arr, mid + 1, e, key);
    }
    else
    {
        return binarySearch(arr, s, mid - 1, key);
    }
}

int main()
{
    int arr[5] = {2, 4, 6, 10, 14};
    int size = 5;
    int key = 14;
    int s = 0;
    int e = size - 1;
    bool ans = binarySearch(arr, s, e, key);
    if (ans)
    {
        cout << "Key is present" << endl;
    }
    else
    {
        cout << "Key is not present" << endl;
    }
    return 0;
}