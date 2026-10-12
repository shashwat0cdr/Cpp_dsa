
#include <iostream>
using namespace std;

class kStacks {
    int *arr;
    int *top;
    int *next;
    int n, k;
    int freespot;

public:
    kStacks(int N, int K) {
        n = N;
        k = K;

        arr = new int[n];
        top = new int[k];
        next = new int[n];

        // Initialize all stacks as empty
        for (int i = 0; i < k; i++) {
            top[i] = -1;
        }

        // Initialize free list
        for (int i = 0; i < n - 1; i++) {
            next[i] = i + 1;
        }

        next[n - 1] = -1;
        freespot = 0;
    }

    void push(int x, int m) {
        // Stack array is full
        if (freespot == -1) {
            cout << "Stack array is full!\n";
            return;
        }

        int index = freespot;
        freespot = next[index];

        arr[index] = x;
        next[index] = top[m];
        top[m] = index;
    }

    int pop(int m) {
        // Stack is empty
        if (top[m] == -1) {
            return -1;
        }

        int index = top[m];
        top[m] = next[index];

        // Return index to free list
        next[index] = freespot;
        freespot = index;

        return arr[index];
    }

    ~kStacks() {
        delete[] arr;
        delete[] top;
        delete[] next;
    }
};

int main() {
    // TEST CASE 1
    cout << "Test Case 1:\n";
    {
        kStacks st(4, 2);

        st.push(5, 0);
        st.push(3, 0);
        st.push(1, 1);

        cout << st.pop(0) << endl;  // 3
        cout << st.pop(1) << endl;  // 1
        cout << st.pop(0) << endl;  // 5
        cout << st.pop(0) << endl;  // -1
    }

    // TEST CASE 2
    cout << "\nTest Case 2:\n";
    {
        kStacks st(9, 3);

        st.push(2, 0);
        st.push(5, 0);
        st.push(4, 1);
        st.push(3, 2);

        cout << st.pop(1) << endl;  // 4
        cout << st.pop(0) << endl;  // 5
        cout << st.pop(0) << endl;  // 2
        cout << st.pop(2) << endl;  // 3
    }

    // TEST CASE 3: Overflow and reuse freed space
    cout << "\nTest Case 3:\n";
    {
        kStacks st(2, 2);

        st.push(10, 0);
        st.push(20, 1);
        st.push(30, 0);  // Array full

        cout << st.pop(0) << endl;  // 10
        st.push(30, 0);             // Reuses freed space

        cout << st.pop(0) << endl;  // 30
        cout << st.pop(1) << endl;  // 20
        cout << st.pop(1) << endl;  // -1
    }

    return 0;
}
