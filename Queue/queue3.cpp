// implementing queue using stack

#include <iostream>
#include <stack>|
using namespace std;

class Queue
{
    stack<int> s1;
    stack<int> s2;

public:
    // inserting an element
    void enqueue(int x)
    {
        s1.push(x);
        cout << x << "inserted" << endl;
    }

    void dequeue()
    {
        if (s1.empty() && s1.empty())
        {
            cout << "queue is empty" << endl;
        }

        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        cout << "deleted" << s2.top() << endl;
        s2.pop();
    }

    int getFront()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "Queue is Empty!" << endl;
            return -1;
        }

        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }

    // Check empty
    bool isEmpty()
    {
        return s1.empty() && s2.empty();
    }
};
