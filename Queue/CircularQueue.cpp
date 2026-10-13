
#include <iostream>
using namespace std;

class MyCircularQueue
{
    int *arr;
    int frontIndex;
    int rear;
    int size;

public:
    MyCircularQueue(int k)
    {
        size = k;
        arr = new int[size];
        frontIndex = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        return frontIndex == -1;
    }

    bool isFull()
    {
        return (rear + 1) % size == frontIndex;
    }

    bool enQueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is Full!" << endl;
            return false;
        }

        if (isEmpty())
        {
            frontIndex = rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }

        arr[rear] = value;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return false;
        }

        if (frontIndex == rear)
        {
            frontIndex = rear = -1;
        }
        else
        {
            frontIndex = (frontIndex + 1) % size;
        }

        return true;
    }

    int Front()
    {
        if (isEmpty())
            return -1;

        return arr[frontIndex];
    }

    int Rear()
    {
        if (isEmpty())
            return -1;

        return arr[rear];
    }

    void printQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return;
        }

        int i = frontIndex;

        while (true)
        {
            cout << arr[i];

            if (i == rear)
                break;

            cout << " -> ";
            i = (i + 1) % size;
        }

        cout << endl;
    }

    ~MyCircularQueue()
    {
        delete[] arr;
    }
};

int main()
{
    MyCircularQueue q(3);

    cout << "Enqueue 10: " << q.enQueue(10) << endl;
    cout << "Enqueue 20: " << q.enQueue(20) << endl;
    cout << "Enqueue 30: " << q.enQueue(30) << endl;

    cout << "\nQueue: ";
    q.printQueue();

    cout << "Front: " << q.Front() << endl;
    cout << "Rear: " << q.Rear() << endl;

    cout << "\nEnqueue 40: " << q.enQueue(40) << endl;

    cout << "\nDequeue: " << q.deQueue() << endl;

    cout << "Queue after dequeue: ";
    q.printQueue();

    cout << "\nEnqueue 40: " << q.enQueue(40) << endl;

    cout << "Queue after circular insertion: ";
    q.printQueue();

    cout << "Front: " << q.Front() << endl;
    cout << "Rear: " << q.Rear() << endl;

    cout << "\nIs Empty: " << (q.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is Full: " << (q.isFull() ? "Yes" : "No") << endl;

    return 0;
}
