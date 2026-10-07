// Insert an element at bottom of a given stack
// Reverse a stack using recursion

#include <iostream>
#include <stack>
using namespace std;


// ======================================================
// INSERT ELEMENT AT BOTTOM
// ======================================================

void solve(stack<int>& s, int x)
{
    // Base case
    if (s.empty())
    {
        s.push(x);
        return;
    }

    // Store top element
    int num = s.top();
    s.pop();

    // Recursive call
    solve(s, x);

    // Put the removed element back
    s.push(num);
}


// Function to insert element at bottom
stack<int> pushAtBottom(stack<int>& myStack, int x)
{
    solve(myStack, x);
    return myStack;
}


// ======================================================
// PRINT STACK
// ======================================================

void printStack(stack<int> s)
{
    cout << "Top -> ";

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    cout << "<- Bottom" << endl;
}


// ======================================================
// REVERSE STACK USING RECURSION
// ======================================================

void reverseStack(stack<int>& s)
{
    // Base case
    if (s.empty())
    {
        return;
    }

    // Store top element
    int num = s.top();
    s.pop();

    // Recursive call
    reverseStack(s);

    // Insert removed element at bottom
    pushAtBottom(s, num);
}


// ======================================================
// MAIN
// ======================================================

int main()
{
    // ==================================================
    // INSERT AT BOTTOM - TEST CASE 1
    // ==================================================

    stack<int> st1;

    st1.push(10);
    st1.push(20);
    st1.push(30);
    st1.push(40);

    cout << "===== INSERT AT BOTTOM =====" << endl;

    cout << "\nTest Case 1" << endl;

    cout << "Before: ";
    printStack(st1);

    pushAtBottom(st1, 5);

    cout << "After:  ";
    printStack(st1);


    // ==================================================
    // INSERT AT BOTTOM - TEST CASE 2
    // ==================================================

    stack<int> st2;

    st2.push(1);
    st2.push(2);
    st2.push(3);

    cout << "\nTest Case 2" << endl;

    cout << "Before: ";
    printStack(st2);

    pushAtBottom(st2, 0);

    cout << "After:  ";
    printStack(st2);


    // ==================================================
    // INSERT AT BOTTOM - TEST CASE 3
    // ==================================================

    stack<int> st3;

    st3.push(100);
    st3.push(200);

    cout << "\nTest Case 3" << endl;

    cout << "Before: ";
    printStack(st3);

    pushAtBottom(st3, 50);

    cout << "After:  ";
    printStack(st3);


    // ==================================================
    // REVERSE STACK - TEST CASE 1
    // ==================================================

    stack<int> st4;

    st4.push(10);
    st4.push(20);
    st4.push(30);
    st4.push(40);

    cout << "\n\n===== REVERSE STACK =====" << endl;

    cout << "\nTest Case 1" << endl;

    cout << "Before: ";
    printStack(st4);

    reverseStack(st4);

    cout << "After:  ";
    printStack(st4);


    // ==================================================
    // REVERSE STACK - TEST CASE 2
    // ==================================================

    stack<int> st5;

    st5.push(1);
    st5.push(2);
    st5.push(3);
    st5.push(4);
    st5.push(5);

    cout << "\nTest Case 2" << endl;

    cout << "Before: ";
    printStack(st5);

    reverseStack(st5);

    cout << "After:  ";
    printStack(st5);


    // ==================================================
    // REVERSE STACK - TEST CASE 3
    // ==================================================

    stack<int> st6;

    st6.push(100);
    st6.push(200);
    st6.push(300);

    cout << "\nTest Case 3" << endl;

    cout << "Before: ";
    printStack(st6);

    reverseStack(st6);

    cout << "After:  ";
    printStack(st6);


    return 0;
}