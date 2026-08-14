#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int row = matrix.size();
    int col = matrix[0].size();

    // Treat 2D matrix as a 1D sorted array
    int start = 0;
    int end = row * col - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        // Convert 1D index to 2D index
        int element = matrix[mid / col][mid % col];

        if (element == target)
        {
            return true;
        }

        if (element < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return false;
}

int main()
{
    // =========================
    // Test Case 1
    // =========================

    vector<vector<int>> matrix1 = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target1 = 3;

    if (searchMatrix(matrix1, target1))
    {
        cout << "Test Case 1: Target Found" << endl;
    }
    else
    {
        cout << "Test Case 1: Target Not Found" << endl;
    }


    // =========================
    // Test Case 2
    // =========================

    vector<vector<int>> matrix2 = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target2 = 13;

    if (searchMatrix(matrix2, target2))
    {
        cout << "Test Case 2: Target Found" << endl;
    }
    else
    {
        cout << "Test Case 2: Target Not Found" << endl;
    }

    return 0;
}