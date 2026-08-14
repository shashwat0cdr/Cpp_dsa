#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
    vector<int> ans;

    int row = matrix.size();
    int col = matrix[0].size();

    int count = 0;
    int total = row * col;

    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row - 1;
    int endingCol = col - 1;

    while (count < total)
    {
        // 1. Starting Row -> Left to Right
        for (int index = startingCol;
             index <= endingCol && count < total;
             index++)
        {
            ans.push_back(matrix[startingRow][index]);
            count++;
        }
        startingRow++;

        // 2. Ending Column -> Top to Bottom
        for (int index = startingRow;
             index <= endingRow && count < total;
             index++)
        {
            ans.push_back(matrix[index][endingCol]);
            count++;
        }
        endingCol--;

        // 3. Ending Row -> Right to Left
        for (int index = endingCol;
             index >= startingCol && count < total;
             index--)
        {
            ans.push_back(matrix[endingRow][index]);
            count++;
        }
        endingRow--;

        // 4. Starting Column -> Bottom to Top
        for (int index = endingRow;
             index >= startingRow && count < total;
             index--)
        {
            ans.push_back(matrix[index][startingCol]);
            count++;
        }
        startingCol++;
    }

    return ans;
}

int main()
{
    // =========================
    // Test Case 1
    // =========================

    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> result1 = spiralOrder(matrix1);

    cout << "Test Case 1: ";

    for (int i = 0; i < result1.size(); i++)
    {
        cout << result1[i] << " ";
    }

    cout << endl;


    // =========================
    // Test Case 2
    // =========================

    vector<vector<int>> matrix2 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    vector<int> result2 = spiralOrder(matrix2);

    cout << "Test Case 2: ";

    for (int i = 0; i < result2.size(); i++)
    {
        cout << result2[i] << " ";
    }

    cout << endl;

    return 0;
}