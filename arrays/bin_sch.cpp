#include <iostream>
using namespace std;

int bin_sch(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }

        if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}

int main()
{
    int even[6] = {12, 34, 56, 78, 88, 90};
    int odd[5] = {1, 22, 34, 78, 99};

    int evenindex = bin_sch(even, 6, 90);
    cout << "the index of 90 is: " << evenindex << endl;
    int oddindex = bin_sch(odd, 5, 78);
    cout << "the index pf 78 is: " << oddindex << endl;
}