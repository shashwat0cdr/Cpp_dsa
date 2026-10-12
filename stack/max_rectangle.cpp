
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<int> nextSmallerElement(vector<int>& arr, int n) {
        stack<int> s;
        s.push(-1);

        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            while (s.top() != -1 && arr[s.top()] >= arr[i]) {
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }

        return ans;
    }

    vector<int> prevSmallerElement(vector<int>& arr, int n) {
        stack<int> s;
        s.push(-1);

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            while (s.top() != -1 && arr[s.top()] >= arr[i]) {
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }

        return ans;
    }

    int largestRectangleArea(vector<int>& heights, int n) {
        vector<int> next = nextSmallerElement(heights, n);
        vector<int> prev = prevSmallerElement(heights, n);

        int area = 0;

        for (int i = 0; i < n; i++) {
            if (next[i] == -1) {
                next[i] = n;
            }

            int width = next[i] - prev[i] - 1;
            int newArea = heights[i] * width;

            area = max(area, newArea);
        }

        return area;
    }

public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size();

        if (n == 0) return 0;

        int m = mat[0].size();

        if (m == 0) return 0;

        vector<int> heights(m, 0);
        int area = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }

            area = max(area, largestRectangleArea(heights, m));
        }

        return area;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> mat = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0}
    };

    cout << "Maximum Rectangle Area: "
         << obj.maxArea(mat) << endl;

    return 0;
}
