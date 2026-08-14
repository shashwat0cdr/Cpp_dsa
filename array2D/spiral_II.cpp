#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    int startingRow = 0;
    int startingCol = 0;
    int endingRow = n - 1;
    int endingCol = n - 1;

    int count = 1;
    int total = n * n;

    while (count <= total)
    {
        // 1. Starting Row -> Left to Right
        for (int index = startingCol;
             index <= endingCol && count <= total;
             index++)
        {
            matrix[startingRow][index] = count;
            count++;
        }
        startingRow++;

        // 2. Ending Column -> Top to Bottom
        for (int index = startingRow;
             index <= endingRow && count <= total;
             index++)
        {
            matrix[index][endingCol] = count;
            count++;
        }
        endingCol--;

        // 3. Ending Row -> Right to Left
        for (int index = endingCol;
             index >= startingCol && count <= total;
             index--)
        {
            matrix[endingRow][index] = count;
            count++;
        }
        endingRow--;

        // 4. Starting Column -> Bottom to Top
        for (int index = endingRow;
             index >= startingRow && count <= total;
             index--)
        {
            matrix[index][startingCol] = count;
            count++;
        }
        startingCol++;
    }

    return matrix;
}

void printMatrix(vector<vector<int>>& matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    // Test Case 1
    int n1 = 3;

    vector<vector<int>> result1 = generateMatrix(n1);

    cout << "Test Case 1:" << endl;
    printMatrix(result1);


    // Test Case 2
    int n2 = 4;

    vector<vector<int>> result2 = generateMatrix(n2);

    cout << "\nTest Case 2:" << endl;
    printMatrix(result2);

    return 0;
}