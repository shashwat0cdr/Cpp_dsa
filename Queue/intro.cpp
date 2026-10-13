// STL method

#include <iostream>
#include <queue>
using namespace std;

void printQueue(queue<int> *q)
{
    queue<int> temp = *q;

    while (!temp.empty())
    {
        cout << temp.front();
        temp.pop();

        if (!temp.empty())
        {
            cout << " -> ";
        }
    }

    cout << endl;
}

int main()
{

    // create a queue
    queue<int> q;
    q.push(10);
    q.push(23);
    q.push(343);
    q.push(3);
    q.push(34);
    printQueue(&q);

    cout << "size of the queue is: " << q.size() << endl;
    int popped = q.front();
    q.pop();
    printQueue(&q);
    cout << "the element is popped is: " << popped << endl;
    cout << "size of the queue after pop is: " << q.size() << endl;
    printQueue(&q);
    cout << "The front of queue is: " << q.front() << endl;

    if (q.empty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue is not empty" << endl;
    }

    return 0;
}