// ps :- for a given 2d- array of size (n X m) print the arr in a sine 
// wave order i.e., print the first col top to bottom and next col bottom to top and so on.

#include <iostream>
using namespace std;

void wavePrint(int arr[][4], int n, int m)
{
    for (int col = 0; col < m; col++)
    {
        if (col % 2 == 0)
        {
            // Even column: Top to Bottom
            for (int row = 0; row < n; row++)
            {
                cout << arr[row][col] << " ";
            }
        }
        else
        {
            // Odd column: Bottom to Top
            for (int row = n - 1; row >= 0; row--)
            {
                cout << arr[row][col] << " ";
            }
        }
    }

    cout << endl;
}

int main()
{
    // Test Case 1
    int arr1[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    cout << "Test Case 1: ";
    wavePrint(arr1, 3, 4);


    // Test Case 2
    int arr2[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    cout << "Test Case 2: ";
    wavePrint(arr2, 4, 4);

    return 0;
}

