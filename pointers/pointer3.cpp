#include <iostream>
using namespace std;
int main()
{
     /*
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
   */

     /*
     int temp[10];
     cout << sizeof(temp) << endl;
     cout << "1st" <<sizeof(*temp) << endl;
     cout << "2nd" <<sizeof(&temp) << endl;

     int *ptr = &temp[0];
     cout << sizeof(ptr) << endl;
     cout << sizeof(*ptr) << endl;
     cout << sizeof(&ptr) << endl;
     */

     /*  int a[20] = {1, 2, 3, 4, 5};
     cout << &a[0] << endl;
      cout << &a << endl;
      cout << a << endl;

      int *p = &a[0];
      cout << p << endl;
      cout << *p << endl;
      cout << "->" <<  &p << endl;
     */

     char ch[6] ="abcde";
     int arr[5] = {1,2,3,4,5};

     cout << ch << endl;
     cout << arr << endl;

     char *c = &ch[0];
     // print an entire string
     cout << c << endl;

     char temp = 'z';
     char *p = &temp;
     cout << p << endl; 

     return 0;
}