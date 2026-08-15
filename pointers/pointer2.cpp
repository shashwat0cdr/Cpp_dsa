#include <iostream>
using namespace std;

int main()
{
    // pointer to int is cretated and pointing to any garbage value
    //  int *p;
    // cout << *p << endl;
    // this above practice is bad pratice neber do it

    // instead of do in this way
    // int *ptr = 0;

    int num = 5;
    int a = num;
    a++;

    cout << num << endl;
    int *p = &num;
    cout << "before: " << num << endl;
    (*p)++;
    cout << "after: " << num << endl;

    // copying a pointer
    int *q = p;
    cout << p << "-" << q << endl;
    cout << *p << "-" << *q << endl;

    // important concept
    int i = 3;
    int *t = &i;
    cout << (*t)++ << endl;

    return 0;
}