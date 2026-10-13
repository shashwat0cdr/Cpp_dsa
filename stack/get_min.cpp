
#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<long long> s;
    long long mini;

public:
    MinStack() {
        mini = 0;
    }

    void push(int val) {
        if (s.empty()) {
            s.push(val);
            mini = val;
        }
        else if (val < mini) {
            s.push(2LL * val - mini);
            mini = val;
        }
        else {
            s.push(val);
        }
    }

    void pop() {
        if (s.empty()) {
            cout << "Stack is empty!\n";
            return;
        }

        long long curr = s.top();
        s.pop();

        if (curr < mini) {
            mini = 2LL * mini - curr;
        }
    }

    int top() {
        if (s.empty()) {
            return -1;
        }

        long long curr = s.top();

        if (curr < mini) {
            return (int)mini;
        }

        return (int)curr;
    }

    int getMin() {
        if (s.empty()) {
            return -1;
        }

        return (int)mini;
    }
};

int main() {

    // TEST CASE 1
    cout << "Test Case 1:\n";
    {
        MinStack st;

        st.push(-2);
        st.push(0);
        st.push(-3);

        cout << "Minimum: " << st.getMin() << endl; // -3

        st.pop();

        cout << "Top: " << st.top() << endl;       // 0
        cout << "Minimum: " << st.getMin() << endl; // -2
    }

    // TEST CASE 2
    cout << "\nTest Case 2:\n";
    {
        MinStack st;

        st.push(5);
        st.push(3);
        st.push(7);
        st.push(2);

        cout << "Minimum: " << st.getMin() << endl; // 2

        st.pop();

        cout << "Top: " << st.top() << endl;       // 7
        cout << "Minimum: " << st.getMin() << endl; // 3
    }

    // TEST CASE 3
    cout << "\nTest Case 3:\n";
    {
        MinStack st;

        st.push(10);
        st.push(20);
        st.push(5);
        st.push(1);

        cout << "Minimum: " << st.getMin() << endl; // 1

        st.pop();

        cout << "Minimum: " << st.getMin() << endl; // 5

        st.pop();

        cout << "Top: " << st.top() << endl;       // 20
        cout << "Minimum: " << st.getMin() << endl; // 10
    }

    return 0;
}
