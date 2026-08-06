#include <iostream>
#include <vector>
using namespace std;

void merge(int arr1[], int n, int arr2[], int m)
{
    int i = n - 1;
    int j = m - 1;
    int k = n + m - 1;
    while (i >= 0 && j >= 0)
    {
        if (arr1[i] > arr2[j])
        {
            arr1[k] = arr1[i];
            i--;
        }
        else
        {
            arr1[k] = arr2[j];
            j--;
        }
        k--;
    }
}

void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr1[8] = {1, 3, 5, 7, 9, 0, 0, 0};
    int arr2[3] = {2, 4, 6};

    merge(arr1, 5, arr2, 3);
    print_array(arr1, 8);
    return 0;
}