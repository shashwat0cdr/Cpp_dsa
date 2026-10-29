
// ============= STL Method ======================= //
// #include <iostream>
// #include <queue>
// using namespace std;
// int main()
// {
//     deque<int> d;
//     d.push_front(12);
//     d.push_back(14);
//     cout << d.front() << endl;
//     cout << d.back() << endl;
//     d.pop_front();
//     cout << d.front() << endl;
//     cout << d.back() << endl;
//     if(d.empty()){
//         cout << "queue is empty" << endl;
//     }
//     else{
//         cout << "queue is not empty" << endl;
//     }
//     return 0;
// }

// ================== implementation method ============ //

#include <iostream>
using namespace std;

class MyCircularDeque
{
    int *arr;
    int frontIndex;
    int rear;
    int size;

public:
    MyCircularDeque(int k)
    {
        size = k;
        arr = new int[size];
        frontIndex = -1;
        rear = -1;
    }

    ~MyCircularDeque()
    {
        delete[] arr;
    }

    bool insertFront(int value)
    {
        if (isFull())
            return false;

        if (isEmpty())
        {
            frontIndex = rear = 0;
        }
        else if (frontIndex == 0)
        {
            frontIndex = size - 1;
        }
        else
        {
            frontIndex--;
        }

        arr[frontIndex] = value;
        return true;
    }

    bool insertLast(int value)
    {
        if (isFull())
            return false;

        if (isEmpty())
        {
            frontIndex = rear = 0;
        }
        else if (rear == size - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }

        arr[rear] = value;
        return true;
    }

    bool deleteFront()
    {
        if (isEmpty())
            return false;

        if (frontIndex == rear)
        {
            frontIndex = rear = -1;
        }
        else if (frontIndex == size - 1)
        {
            frontIndex = 0;
        }
        else
        {
            frontIndex++;
        }

        return true;
    }

    bool deleteLast()
    {
        if (isEmpty())
            return false;

        if (frontIndex == rear)
        {
            frontIndex = rear = -1;
        }
        else if (rear == 0)
        {
            rear = size - 1;
        }
        else
        {
            rear--;
        }

        return true;
    }

    int getFront()
    {
        return isEmpty() ? -1 : arr[frontIndex];
    }

    int getRear()
    {
        return isEmpty() ? -1 : arr[rear];
    }

    bool isEmpty()
    {
        return frontIndex == -1;
    }

    bool isFull()
    {
        if (isEmpty())
            return false;

        return (frontIndex == 0 && rear == size - 1) ||
               (frontIndex == rear + 1);
    }

    // Display elements from front to rear
    void display()
    {
        if (isEmpty())
        {
            cout << "Deque is empty\n";
            return;
        }

        int i = frontIndex;

        cout << "Deque: ";
        while (true)
        {
            cout << arr[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % size;
        }

        cout << endl;
    }
};

int main()
{
    MyCircularDeque dq(3);

    cout << boolalpha;

    cout << "insertLast(1): "
         << dq.insertLast(1) << endl;

    cout << "insertLast(2): "
         << dq.insertLast(2) << endl;

    cout << "insertFront(3): "
         << dq.insertFront(3) << endl;

    cout << "insertFront(4): "
         << dq.insertFront(4) << endl;

    dq.display();

    cout << "getFront(): "
         << dq.getFront() << endl;

    cout << "getRear(): "
         << dq.getRear() << endl;

    cout << "isFull(): "
         << dq.isFull() << endl;

    cout << "deleteLast(): "
         << dq.deleteLast() << endl;

    cout << "insertFront(4): "
         << dq.insertFront(4) << endl;

    dq.display();

    cout << "getFront(): "
         << dq.getFront() << endl;

    cout << "\n--- Edge Case: Capacity 1 ---\n";

    MyCircularDeque dq2(1);

    cout << "insertFront(10): "
         << dq2.insertFront(10) << endl;

    cout << "isFull(): "
         << dq2.isFull() << endl;

    cout << "insertLast(20): "
         << dq2.insertLast(20) << endl;

    cout << "deleteFront(): "
         << dq2.deleteFront() << endl;

    cout << "isEmpty(): "
         << dq2.isEmpty() << endl;

    return 0;
}
