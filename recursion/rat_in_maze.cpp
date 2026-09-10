#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:

    // Check whether the cell is safe to visit
    bool isSafe(int row, int col, int n,
                vector<vector<int>>& maze,
                vector<vector<int>>& visited) {

        if ((row >= 0 && row < n) &&
            (col >= 0 && col < n) &&
            maze[row][col] == 1 &&
            visited[row][col] == 0) {

            return true;
        }

        return false;
    }

    void solve(int row, int col,
               vector<vector<int>>& maze,
               int n,
               vector<string>& ans,
               string path,
               vector<vector<int>>& visited) {

        // Base case
        if (row == n - 1 && col == n - 1) {
            ans.push_back(path);
            return;
        }

        visited[row][col] = 1;

        // Down
        if (isSafe(row + 1, col, n, maze, visited)) {
            solve(row + 1, col, maze, n, ans, path + 'D', visited);
        }

        // Left
        if (isSafe(row, col - 1, n, maze, visited)) {
            solve(row, col - 1, maze, n, ans, path + 'L', visited);
        }

        // Right
        if (isSafe(row, col + 1, n, maze, visited)) {
            solve(row, col + 1, maze, n, ans, path + 'R', visited);
        }

        // Up
        if (isSafe(row - 1, col, n, maze, visited)) {
            solve(row - 1, col, maze, n, ans, path + 'U', visited);
        }

        // Backtracking
        visited[row][col] = 0;
    }

public:

    vector<string> ratInMaze(vector<vector<int>>& maze, int n) {

        vector<string> ans;

        if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
            return ans;

        vector<vector<int>> visited(n, vector<int>(n, 0));

        solve(0, 0, maze, n, ans, "", visited);

        return ans;
    }
};

int main() {

    Solution obj;

    int n;
    cout << "Enter size of maze: ";
    cin >> n;

    vector<vector<int>> maze(n, vector<int>(n));

    cout << "Enter maze:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }

    vector<string> ans = obj.ratInMaze(maze, n);

    cout << "\nPossible paths:\n";

    if (ans.empty()) {
        cout << "No path exists";
    }
    else {
        for (string path : ans) {
            cout << path << endl;
        }
    }

    return 0;
}