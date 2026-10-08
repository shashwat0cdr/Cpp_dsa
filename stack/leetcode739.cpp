#include <iostream>
#include <vector>
#include <stack>
using namespace std;


// ============================================================
// 1. LEETCODE 739 - DAILY TEMPERATURES
// ============================================================

vector<int> dailyTemperatures(vector<int>& temperatures) {

    int n = temperatures.size();

    // Stack stores INDEXES
    stack<int> s;

    vector<int> ans(n, 0);

    // Traverse from right to left
    for (int i = n - 1; i >= 0; i--) {

        // Remove temperatures which are smaller
        // or equal to current temperature
        while (!s.empty() &&
               temperatures[s.top()] <= temperatures[i]) {
            s.pop();
        }

        // If stack is not empty,
        // top contains the next warmer day
        if (!s.empty()) {
            ans[i] = s.top() - i;
        }

        // Push current index
        s.push(i);
    }

    return ans;
}


// ============================================================
// 2. NEXT SMALLER ELEMENT
// ============================================================

vector<int> nextSmallerElement(vector<int>& arr) {

    int n = arr.size();

    stack<int> s;

    vector<int> ans(n, -1);

    // Traverse from right to left
    for (int i = n - 1; i >= 0; i--) {

        // Remove elements which are >= current
        while (!s.empty() && s.top() >= arr[i]) {
            s.pop();
        }

        // If stack is not empty,
        // top is the next smaller element
        if (!s.empty()) {
            ans[i] = s.top();
        }

        // Push current element
        s.push(arr[i]);
    }

    return ans;
}


// ============================================================
// PRINT VECTOR
// ============================================================

void printVector(vector<int>& ans) {

    cout << "[ ";

    for (int x : ans) {
        cout << x << " ";
    }

    cout << "]" << endl;
}


// ============================================================
// MAIN
// ============================================================

int main() {

    // ========================================================
    // TEST CASES FOR DAILY TEMPERATURES
    // ========================================================

    cout << "======================================" << endl;
    cout << "     DAILY TEMPERATURES - LEETCODE 739" << endl;
    cout << "======================================" << endl;

    // Test Case 1
    vector<int> temp1 = {73, 74, 75, 71, 69, 72, 76, 73};

    cout << "Test Case 1: ";
    printVector(temp1);

    vector<int> result1 = dailyTemperatures(temp1);

    cout << "Output:      ";
    printVector(result1);

    cout << endl;


    // Test Case 2
    vector<int> temp2 = {30, 40, 50, 60};

    cout << "Test Case 2: ";
    printVector(temp2);

    vector<int> result2 = dailyTemperatures(temp2);

    cout << "Output:      ";
    printVector(result2);

    cout << endl;


    // Test Case 3
    vector<int> temp3 = {30, 60, 90};

    cout << "Test Case 3: ";
    printVector(temp3);

    vector<int> result3 = dailyTemperatures(temp3);

    cout << "Output:      ";
    printVector(result3);


    // ========================================================
    // TEST CASES FOR NEXT SMALLER ELEMENT
    // ========================================================

    cout << endl;
    cout << "======================================" << endl;
    cout << "          NEXT SMALLER ELEMENT" << endl;
    cout << "======================================" << endl;

    // Test Case 1
    vector<int> arr1 = {4, 8, 5, 2, 25};

    cout << "Test Case 1: ";
    printVector(arr1);

    vector<int> small1 = nextSmallerElement(arr1);

    cout << "Output:      ";
    printVector(small1);

    cout << endl;


    // Test Case 2
    vector<int> arr2 = {13, 7, 6, 12};

    cout << "Test Case 2: ";
    printVector(arr2);

    vector<int> small2 = nextSmallerElement(arr2);

    cout << "Output:      ";
    printVector(small2);

    cout << endl;


    // Test Case 3
    vector<int> arr3 = {5, 4, 3, 2, 1};

    cout << "Test Case 3: ";
    printVector(arr3);

    vector<int> small3 = nextSmallerElement(arr3);

    cout << "Output:      ";
    printVector(small3);


    return 0;
}