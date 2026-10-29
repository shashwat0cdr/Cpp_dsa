#include <iostream>
using namespace std;

class kQueue
{
public:
    int n;
    int k;
    int *front;
    int *rear;
    int *arr;
    int freeSpot;
    int *next;

    kQueue(int n, int k)
    {
        this->n = n;
        this->k = k;

        front = new int[k];
        rear = new int[k];

        for (int i = 0; i < k; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }

        next = new int[n];

        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }

        next[n - 1] = -1;

        arr = new int[n];
        freeSpot = 0;
    }

    void enqueue(int data, int qn)
    {
        if (freeSpot == -1)
        {
            cout << "No Space Available!" << endl;
            return;
        }

        int index = freeSpot;
        freeSpot = next[index];

        if (front[qn - 1] == -1)
        {
            front[qn - 1] = index;
        }
        else
        {
            next[rear[qn - 1]] = index;
        }

        next[index] = -1;
        rear[qn - 1] = index;
        arr[index] = data;
    }

    int dequeue(int qn)
    {
        if (front[qn - 1] == -1)
        {
            cout << "Queue " << qn << " Underflow!" << endl;
            return -1;
        }

        int index = front[qn - 1];

        front[qn - 1] = next[index];

        if (front[qn - 1] == -1)
        {
            rear[qn - 1] = -1;
        }

        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }

    ~kQueue()
    {
        delete[] front;
        delete[] rear;
        delete[] arr;
        delete[] next;
    }
};

int main()
{
    // Total array size = 10, number of queues = 3
    kQueue q(10, 3);

    // Test Case 1: Insert into different queues
    cout << "Test Case 1: Enqueue" << endl;

    q.enqueue(10, 1);
    q.enqueue(20, 1);
    q.enqueue(30, 2);
    q.enqueue(40, 3);
    q.enqueue(50, 2);

    cout << "Inserted elements into Queue 1, Queue 2 and Queue 3."
         << endl << endl;

    // Test Case 2: Dequeue elements
    cout << "Test Case 2: Dequeue" << endl;

    cout << "Queue 1: " << q.dequeue(1) << endl;
    cout << "Queue 2: " << q.dequeue(2) << endl;
    cout << "Queue 3: " << q.dequeue(3) << endl;

    cout << endl;

    // Test Case 3: Reuse freed space
    cout << "Test Case 3: Reuse Free Space" << endl;

    q.enqueue(60, 3);
    q.enqueue(70, 1);

    cout << "Queue 1: " << q.dequeue(1) << endl;
    cout << "Queue 2: " << q.dequeue(2) << endl;
    cout << "Queue 3: " << q.dequeue(3) << endl;

    return 0;
}