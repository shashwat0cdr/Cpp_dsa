#include <iostream>
using namespace std;

void update(int n)
{
    n++;
}

void update2(int& n)
{
    n++;
}

int main()
{

    // int i = 5;
    // // create a refrence variable
    // int &j = i;

    // cout << i << endl;
    // i++;
    // cout << i << endl;
    // j++;
    // cout << i << endl;
    // cout << j << endl;

    // int n = 5;
    // cout << "before " << n << endl;
    // update2(n);
    // cout << "after " << n << endl;

    // char ch = 'q';
    // cout << sizeof(ch) << endl;

    // char* c = &ch;
    // cout << sizeof(c) << endl;
    

    return 0;
}