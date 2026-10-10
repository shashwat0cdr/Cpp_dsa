
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Approach 1: Stack
class Solution1 {
private:
    bool know(const vector<vector<int>>& mat, int a, int b) {
        return mat[a][b] == 1;
    }

public:
    int celebrity(const vector<vector<int>>& mat) {
        int n = mat.size();

        if (n == 0) return -1;

        stack<int> s;

        // Step 1: Push all people
        for (int i = 0; i < n; i++) {
            s.push(i);
        }

        // Step 2: Eliminate non-celebrities
        while (s.size() > 1) {
            int a = s.top();
            s.pop();

            int b = s.top();
            s.pop();

            if (know(mat, a, b)) {
                s.push(b);
            } else {
                s.push(a);
            }
        }

        // Step 3: Verify candidate
        int candidate = s.top();

        for (int i = 0; i < n; i++) {
            if (i != candidate &&
                (mat[candidate][i] == 1 ||
                 mat[i][candidate] == 0)) {
                return -1;
            }
        }

        return candidate;
    }
};

// Approach 2: Two Pointers
class Solution2 {
public:
    int celebrity(const vector<vector<int>>& mat) {
        int n = mat.size();

        if (n == 0) return -1;

        int i = 0;
        int j = n - 1;

        // Step 1: Find potential celebrity
        while (i < j) {
            if (mat[i][j] == 1) {
                // i knows j, so i cannot be celebrity
                i++;
            } else {
                // i does not know j, so j cannot be celebrity
                j--;
            }
        }

        int candidate = i;

        // Step 2: Verify candidate
        for (int k = 0; k < n; k++) {
            if (k != candidate &&
                (mat[candidate][k] == 1 ||
                 mat[k][candidate] == 0)) {
                return -1;
            }
        }

        return candidate;
    }
};

int main() {
    Solution1 stackSol;
    Solution2 twoPointerSol;

    // Test cases: {matrix, expected answer}
    vector<pair<vector<vector<int>>, int>> tests = {
        // Test 1: Celebrity is person 1
        {{{0, 1, 0},
          {0, 0, 0},
          {0, 1, 0}}, 1},

        // Test 2: No celebrity
        {{{0, 1, 0},
          {0, 0, 1},
          {1, 0, 0}}, -1},

        // Test 3: Celebrity is person 0
        {{{0, 0, 0},
          {1, 0, 1},
          {1, 0, 0}}, 0},

        // Test 4: Only one person
        {{{0}}, 0},

        // Test 5: Nobody knows anybody
        {{{0, 0, 0},
          {0, 0, 0},
          {0, 0, 0}}, -1},

        // Test 6: Celebrity is person 2
        {{{0, 0, 1},
          {1, 0, 1},
          {0, 0, 0}}, 2},

        // Test 7: Empty matrix
        {{}, -1}
    };

    cout << "Celebrity Problem: Approach Comparison\n";
    cout << "---------------------------------------\n";

    bool allPassed = true;

    for (int t = 0; t < (int)tests.size(); t++) {
        const auto& mat = tests[t].first;
        int expected = tests[t].second;

        int stackAns = stackSol.celebrity(mat);
        int pointerAns = twoPointerSol.celebrity(mat);

        bool passed =
            (stackAns == expected &&
             pointerAns == expected);

        if (!passed) allPassed = false;

        cout << "Test Case " << t + 1 << ":\n";
        cout << "Expected    : " << expected << '\n';
        cout << "Stack       : " << stackAns << '\n';
        cout << "Two Pointers: " << pointerAns << '\n';
        cout << "Status      : "
             << (passed ? "PASS" : "FAIL") << "\n\n";
    }

    cout << (allPassed
                 ? "All test cases passed!"
                 : "Some test cases failed!")
         << endl;

    return 0;
}
