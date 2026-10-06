#include <iostream>
#include <stack>
using namespace std;

/*class Stack
{
public:
    int *arr;
    int top;
    int size;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "stack overflow" << endl;
        }
    }

    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "stack underflow" << endl;
        }
    }

    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "stack is empty" << endl;
            return -1;
        }
        }

        bool isEmpty()
        {
            return top == -1;
            }
};*/

// int main()
// {
//     // Stack st(5);
//     // st.push(1);
//     // st.push(22);
//     // st.push(3);
//     // cout << st.peek() << endl;
//     // st.pop();
//     // cout << st.peek() << endl;
//     // if(st.isEmpty()){
//     //     cout << "stack is empty" << endl;
//     // }
//     // else{
//     //     cout << "stack is not empty" << endl;
//     // }
//     return 0;
// }

#include <iostream>
using namespace std;

class TwoStack
{
private:
    int *arr;
    int top1;
    int top2;
    int size;

public:
    // Constructor
    TwoStack(int size)
    {
        this->size = size;
        top1 = -1;
        top2 = size;

        arr = new int[size];
    }

    // Push in Stack 1
    void push1(int element)
    {
        if (top1 + 1 < top2)
        {
            top1++;
            arr[top1] = element;
        }
        else
        {
            cout << "Stack 1 Overflow!" << endl;
        }
    }

    // Push in Stack 2
    void push2(int element)
    {
        if (top2 - 1 > top1)
        {
            top2--;
            arr[top2] = element;
        }
        else
        {
            cout << "Stack 2 Overflow!" << endl;
        }
    }

    // Pop from Stack 1
    int pop1()
    {
        if (top1 >= 0)
        {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else
        {
            cout << "Stack 1 Underflow!" << endl;
            return -1;
        }
    }

    // Pop from Stack 2
    int pop2()
    {
        if (top2 < size)
        {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else
        {
            cout << "Stack 2 Underflow!" << endl;
            return -1;
        }
    }

    // Destructor
    ~TwoStack()
    {
        delete[] arr;
    }
};


// ======================================================
// MAIN FUNCTION
// ======================================================

int main()
{
    // ==================================================
    // TEST CASE 1
    // ==================================================

    cout << "========== TEST CASE 1 ==========" << endl;

    TwoStack st1(10);

    st1.push1(18);
    st1.push1(20);
    st1.push1(56);
    st1.push1(23);

    st1.push2(34);
    st1.push2(29);
    st1.push2(10);
    st1.push2(89);

    cout << "Stack 1 Pop: " << st1.pop1() << endl;
    cout << "Stack 1 Pop: " << st1.pop1() << endl;

    cout << "Stack 2 Pop: " << st1.pop2() << endl;
    cout << "Stack 2 Pop: " << st1.pop2() << endl;


    // ==================================================
    // TEST CASE 2
    // ==================================================

    cout << "\n========== TEST CASE 2 ==========" << endl;

    TwoStack st2(5);

    st2.push1(10);
    st2.push1(20);

    st2.push2(30);
    st2.push2(40);

    cout << "Stack 1 Pop: " << st2.pop1() << endl;
    cout << "Stack 2 Pop: " << st2.pop2() << endl;

    st2.push1(50);

    cout << "Stack 1 Pop: " << st2.pop1() << endl;


    // ==================================================
    // TEST CASE 3 - Overflow & Underflow
    // ==================================================

    cout << "\n========== TEST CASE 3 ==========" << endl;

    TwoStack st3(4);

    // Filling complete array
    st3.push1(100);
    st3.push1(200);

    st3.push2(300);
    st3.push2(400);

    // Now array is full
    cout << "\nTrying to push when array is full:" << endl;
    st3.push1(500);
    st3.push2(600);

    // Pop everything
    cout << "\nPopping elements:" << endl;

    cout << "Stack 1 Pop: " << st3.pop1() << endl;
    cout << "Stack 1 Pop: " << st3.pop1() << endl;

    cout << "Stack 2 Pop: " << st3.pop2() << endl;
    cout << "Stack 2 Pop: " << st3.pop2() << endl;

    // Underflow
    cout << "\nTrying to pop from empty stacks:" << endl;

    st3.pop1();
    st3.pop2();

    return 0;
}