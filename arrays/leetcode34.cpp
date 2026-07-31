#include <iostream>
using namespace std;

int left_most(int arr[], int size, int key)
{
    int s = 0, e = size - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (arr[mid] < key)
        {
            // key greater than mid then right part me move krna hai
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int right_most(int arr[], int size, int key)
{
    int s = 0, e = size - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (arr[mid] < key)
        {
            // key greater than mid then right part me move krna hai
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    int arr[5] = {1, 2, 3, 3, 5};
    int first_occurence = left_most(arr, 5, 3);
    cout << " the first occurence of the elements is at index  " << first_occurence << endl;
    int last_occurence = right_most(arr, 5, 3);
    cout << " the last occurence of the elements is at index " << last_occurence << endl;
    return 0;
}