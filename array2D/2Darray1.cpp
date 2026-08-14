#include <iostream>
#include <climits>
using namespace std;

bool ispresent(int arr[][4], int target, int row, int col)
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            if (arr[row][col] == target)
            {
                return 1;
            }
        }
    }
    return 0;
}

// to print row wise sum
void printSum_row(int arr[][4], int row, int col)
{
    cout << "printing sum row wise:- " << endl;
    for (int row = 0; row < 3; row++)
    {
        int sum = 0;
        for (int col = 0; col < 4; col++)
        {
            sum += arr[row][col];
        }
        cout << sum << " ";
    }
    cout << endl;
}

// to print col wise
void printSum_col(int arr[][4], int row, int col)
{
    cout << "printing sum col wise:- " << endl;
    for (int col = 0; col < 4; col++)
    {
        int sum = 0;
        for (int row = 0; row < 3; row++)
        {
            sum += arr[row][col];
        }
        cout << sum << " ";
    }
    cout << endl;
}

// to getting the largest row sum
int largestRowSum(int arr[][4], int row, int col)
{
    int maxi = INT_MIN;
    int rowIndex = -1;
    for (int row = 0; row < 3; row++)
    {
        int sum = 0;
        for (int col = 0; col < 4; col++)
        {
            sum += arr[row][col];
        }
        if (sum > maxi)
        {
            maxi = sum;
            rowIndex = row;
        }
    }

    cout << "the maximum sum is " << maxi << endl;
    return rowIndex;
}

int main()
{

    // create 2d array
    int arr[3][4];
    // taking input row wise
    /*
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> arr[i][j];
        }
    }
    */
    // taking input column wise

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[j][i];
        }
    }

    // printing the array
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    /*
        cout << "enter the element to search the array: ";
        int target;
        cin >> target;

        if (ispresent(arr, target, 3, 4))
        {
            cout << "element found" << endl;
        }
        else
        {
            cout << "element not found" << endl;
        }

        // row wise sum
        printSum_row(arr, 3, 4);
        printSum_col(arr, 3, 4);
    */
    int ansIndex = largestRowSum(arr, 3, 4);
    cout << "The max row is at index " << ansIndex  << endl;

    return 0;
}