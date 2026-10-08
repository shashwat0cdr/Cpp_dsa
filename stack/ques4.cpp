#include <iostream>
#include <stack>
using namespace std;

// Insert element at correct position in sorted stack
void sortedInsert(stack<int>& s, int num)
{
    // Base case
    // Stack empty OR top element is smaller than num
    if (s.empty() || s.top() < num)
    {
        s.push(num);
        return;
    }

    // Store top element
    int n = s.top();
    s.pop();

    // Recursive call
    sortedInsert(s, num);

    // Put stored element back
    s.push(n);
}

// Sort the stack
void sortStack(stack<int>& s)
{
    // Base case
    if (s.empty())
    {
        return;
    }

    // Remove top element
    int num = s.top();
    s.pop();

    // Recursively sort remaining stack
    sortStack(s);

    // Insert removed element at correct position
    sortedInsert(s, num);
}

// Print stack
void printStack(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> s;
    cout << "========== Test case 1 ==========" << endl;
    // Test Case 1
    s.push(30);
    s.push(10);
    s.push(50);
    s.push(20);
    s.push(40);

    cout << "Before sorting: ";
    printStack(s);

    sortStack(s);

    cout << "After sorting:  ";
    printStack(s);

    // test case 2

    cout << "========== Test case 2 ==========" << endl;
    stack<int> s2;
    s2.push(80);
    s2.push(10);
    s2.push(-2);
    s2.push(20);
    s2.push(45);

    cout << "Before sorting: ";
    printStack(s2);

    sortStack(s2);

    cout << "After sorting:  ";
    printStack(s2);


    return 0;
}