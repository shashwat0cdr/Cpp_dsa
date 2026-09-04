#include <iostream>
using namespace std;

bool isSorted(int arr[], int n)
{
    // base case
    if (n == 0 || n == 1)
    {
        return true;
    }

    if (arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        bool remainingPart = isSorted(arr + 1, n - 1);
        return remainingPart;
    }
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};\
    cout << "array is sorted or not: " << isSorted(arr, 5);

    return 0;
}