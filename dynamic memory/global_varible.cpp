#include <iostream>
using namespace std;

// global variable 
int score = 15;

void a(int& i)
{
    
    cout << score << endl;
    cout << i << endl;
    //b(i);
}

void b(int& i)
{
    cout << i << endl;
}

int main()
{
    // local variable
    int i = 5;
   // a(i);
    {
        int i = 2;
        cout << i << endl;

    }


    return 0;
}