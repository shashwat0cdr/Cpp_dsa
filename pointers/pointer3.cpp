#include <iostream>
using namespace std;
int main()
{
    int arr[10] = {2, 3, 4};
    cout << "The address of first memory block is: "
         << arr << endl;
    cout << "The address of first memory block is: "
         << &arr[3] << endl;
    cout << arr[0] << endl;
    cout << "4th: " << *arr << endl;
    cout << *arr + 1 << endl;
    cout << *(arr + 1) << endl;

    cout << (*arr) + 1 << endl;
    int i = 3;
    cout << i[arr] << endl;
    
    return 0;
}