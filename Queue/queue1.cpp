// Queue implementation using array
#include <iostream>
using namespace std;

class Queue
{
    int *arr;
    int frontIndex;
    int rear;
    int size;

public:
    Queue()
    {
        size = 10000001;
        arr = new int[size];
        frontIndex = 0;
        rear = 0;
    }

    bool isEmpty()
    {
        return frontIndex == rear;
    }

    void enqueue(int data)
    {
        if (rear == size)
        {
            cout << "Queue is Full" << endl;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue()
    {
        if (frontIndex == rear)
        {
            return -1;
        }

        int ans = arr[frontIndex];
        arr[frontIndex] = -1;
        frontIndex++;

        if (frontIndex == rear)
        {
            frontIndex = 0;
            rear = 0;
        }

        return ans;
    }

    int getFront()
    {
        if (frontIndex == rear)
        {
            return -1;
        }

        return arr[frontIndex];
    }

    int getRear(){
        if(frontIndex == rear){
            return -1;
        }

        return arr[rear - 1];
    }

    ~Queue()
    {
        delete[] arr;
    }

    void printQueue()
    {
        if(isEmpty()){
            cout << "Queue is Empty" << endl;
            return;
        }
        
        for(int i = frontIndex; i < rear; i++){
            cout << arr[i];
            if(i<rear-1){
                cout << " -> ";
            }
        }
        cout << endl;
    }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(80);

    cout << "Front element: " << q.getFront() << endl;

    //cout << "Dequeued: " << q.dequeue() << endl;
    //cout << "Dequeued: " << q.dequeue() << endl;

    cout << "Last element: " << q.getRear() << endl;

    cout << "Is queue empty? "
         << (q.isEmpty() ? "Yes" : "No") << endl;

   // q.dequeue();

    cout << "Is queue empty? "
         << (q.isEmpty() ? "Yes" : "No") << endl;

    q.printQueue();
    return 0;
}
