#include <iostream>
using namespace std;

int main()
{
    int num = 5;

    cout << num << endl;

    cout << "the address of num is " << &num << endl;

    int *ptr = &num;
    cout << "the value is: " << *ptr << endl;
    cout << "the value is: " << ptr << endl;

    cout << "Size of integer is: " << sizeof(num) << endl;
    cout << "Size of pointer is: " << sizeof(*ptr) << endl;
    return 0;
}