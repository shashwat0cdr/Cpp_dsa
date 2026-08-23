#include <iostream>
using namespace std;

int main()
{
    int row;
    cin >> row;
    int col;
    cin >> col;

    int **arr = new int *[row];

    // creation done
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[col];
    }

    // taking an input in 2D array for user
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }

    // printing an 2D array
    cout << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // releasing memory 
    for (int i = 0; i < row; i++)
    {
        delete [] arr[i];
    }
    
    delete []arr;


    return 0;
}


// the things we have learn in this are 
// creating an array dynamically 2D
// input / output 
// deleting form memory 
