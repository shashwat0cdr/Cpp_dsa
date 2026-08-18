#include <iostream>
using namespace std;

void print(int *p)
{
    cout << p << endl;
    cout << *p << endl;
}

void update(int *p)
{
    p = p + 1;
    cout << "update: " << p << endl;
}

int get_sum(int *arr, int n)
{

    cout << endl
         << "Size of: " << sizeof(arr) << endl;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{

    // int value = 5;
    // int *p = &value;
    // print(p);

    // cout << "before " << *p << endl;
    // update(p);
    // cout << "after " << *p << endl;

    int arr[5] = {1, 2, 3, 4, 5};
    cout << "sum is " << get_sum(arr, 5) << endl;
    cout << "sum is " << get_sum(arr + 3, 2) << endl;

    return 0;
}