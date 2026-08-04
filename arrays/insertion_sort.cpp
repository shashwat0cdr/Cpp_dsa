#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* this version of sorting is not very good practice
void insertionSort(vector<int> &arr)
{

    for (int i = 1; i < arr.size(); i++)
    {
        int temp = arr[i];
        int j = i - 1;
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                // shift
                arr[j + 1] = arr[j];
            }
            else
            {
                // stop
                break;
            }
        }
        arr[j + 1] = temp;
    }
}
*/

// more readable version of insertion sort
void insertionSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // Shift elements greater than key
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        // Place key at its correct position
        arr[j + 1] = key;
    }
}
int main()
{
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    insertionSort(arr);
    cout << "Sorted array: \n";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
