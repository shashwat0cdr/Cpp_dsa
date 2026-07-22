#include <iostream>
#include <climits>   
using namespace std;

// max and min of array

int get_max(int num[], int n)
{

    int maxi = INT_MIN; 
    for (int i = 0; i < n; i++)
    {
        // if (num[i] > max)
        // {
        //     max = num[i];
        // }
        maxi = max(maxi, num[i]); // same method but in more optimize way
    }
    // returning max
    return maxi;
}


int get_min(int num[], int n)
{
    int mini = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        // if (num[i] < min)
        // {
        //     min = num[i];
        // }
        mini = min(mini, num[i]); // same method but in more optimize way
    }
    // returning min 
    return mini;
}


int main()
{
    int size;
    cout << "enter the size of an array: ";
    cin >> size;

    int num[100];
    for (int i = 0; i < size; i++)
    {
        cin >> num[i];
    }

    cout << "Maximum Value is " << get_max(num,size) << endl;
    cout << "mininmum Value is " << get_min(num , size) << endl;

    // maximum
    return 0;
}