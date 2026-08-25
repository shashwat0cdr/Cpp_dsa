#include <iostream>
using namespace std;


inline int getmax(int& a, int& b)
{
    return (a > b) ? a : b;
}

int main()
{
    int a = 5, b = 6;
    int ans = 0;
    ans = getmax(a,b);
    cout << ans << endl;




    // if(a>b){
    //     ans = a;
    // }
    //     ------------> this whole opreation can be written in the one line //
    //          --------> ans = (a>b) ? a:b;
    // else{
    //     ans = b;
    // }



    a = a + 3;
    b = b + 2;
    ans = getmax(a,b);
    cout << ans << endl;






    return 0;
}