// delete a middle element from the stack

#include <iostream>
#include <stack>
using namespace std;

// Recursive function to delete middle element
void solve(stack<int>& inputStack, int count, int N)
{
    // Base case
    if (count == N / 2)
    {
        inputStack.pop();
        return;
    }

    // Store top element
    int num = inputStack.top();
    inputStack.pop();

    // Recursive call
    solve(inputStack, count + 1, N);

    // Put the element back
    inputStack.push(num);
}

// Function to delete middle element
void deleteMiddle(stack<int>& inputStack, int N)
{
    int count = 0;
    solve(inputStack, count, N);
}

// Function to print stack
void printStack(stack<int> st)
{
    cout << "Stack (top -> bottom): ";

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    cout << endl;
}

int main()
{
    // ================= TEST CASE 1 =================
    stack<int> st1;

    st1.push(1);
    st1.push(2);
    st1.push(3);
    st1.push(4);
    st1.push(5);

    cout << "Test Case 1:" << endl;
    cout << "Before deletion: ";
    printStack(st1);

    int N1 = st1.size();
    deleteMiddle(st1, N1);

    cout << "After deletion:  ";
    printStack(st1);


    // ================= TEST CASE 2 =================
    stack<int> st2;

    st2.push(10);
    st2.push(20);
    st2.push(30);
    st2.push(40);
    st2.push(50);
    st2.push(60);
    st2.push(70);

    cout << "\nTest Case 2:" << endl;
    cout << "Before deletion: ";
    printStack(st2);

    int N2 = st2.size();
    deleteMiddle(st2, N2);

    cout << "After deletion:  ";
    printStack(st2);


    // ================= TEST CASE 3 =================
    stack<int> st3;

    st3.push(100);
    st3.push(200);
    st3.push(300);
    st3.push(400);

    cout << "\nTest Case 3:" << endl;
    cout << "Before deletion: ";
    printStack(st3);

    int N3 = st3.size();
    deleteMiddle(st3, N3);

    cout << "After deletion:  ";
    printStack(st3);

    return 0;
}