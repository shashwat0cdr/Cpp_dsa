#include <iostream>
using namespace std;
void sum(int arr[], int size)
{
    int s = 0;
    for (int i = 0; i < size; i++)
    {
        s = s + arr[i];
    }
    cout << "Sum: " << s << endl;
}

int main()
{
    int size;
    cout << "enter the size of an array: ";
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    sum(arr, size);
    return 0;
}
