#include <iostream>
using namespace std;


void merge(int *arr, int s, int e){

    int mid = s + (e - s) / 2;
    int len1 = mid -s +1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int k = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[k++];
    }

    int k2 = mid + 1; // k2 = second array index
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[k2++];
    }

    int index1 = 0;
    int index2 = 0;
    k = s; // k = main array index
    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[k++] = first[index1++];
        }
        else
        {
            arr[k++] = second[index2++];
        }
    }
    // Copy any remaining elements from either subarray
    while (index1 < len1)
    {
        arr[k++] = first[index1++];
    }
    while (index2 < len2)
    {
        arr[k++] = second[index2++];
    }
    // Deallocate memory
    delete[] first;
    delete[] second;
}
void mergeSort(int arr[], int s, int e)
{
    // base case '
    if (s > e)
    {
        return;
    }
    int mid = s + (e - s) / 2;
    // left part
    mergeSort(arr , s, mid);

    // right part 
    mergeSort(arr, mid + 1, e);

    // merge 
    merge(arr, s, e);

}

int main()
{

    int arr[5] = {5, 4, 3, 2, 1};
    int n = 5;

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}