#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int row = 0;
    int col = matrix[0].size() - 1;

    // Start from top-right corner
    while (row < matrix.size() && col >= 0)
    {
        int element = matrix[row][col];

        if (element == target)
        {
            return true;
        }

        // Current element is greater -> move left
        if (element > target)
        {
            col--;
        }
        // Current element is smaller -> move down
        else
        {
            row++;
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
        {1,  4,  7,  11, 15},
        {2,  5,  8,  12, 19},
        {3,  6,  9,  16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    int target1 = 16;

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
        {1,  4,  7,  11, 15},
        {2,  5,  8,  12, 19},
        {3,  6,  9,  16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    int target2 = 20;

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