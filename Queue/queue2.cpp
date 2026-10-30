// implementing a queue using a linked list

#include <iostream>
using namespace std;

class Queue
{
    struct Node
    {
        int data;
        Node *next;

        Node(int val)
        {
            data = val;
            next = NULL;
        }
    };

    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int val)
    {
        Node *temp = new Node(val);
        if (rear == NULL)
        {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    void dequeue()
    {
        if (front == NULL)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        Node *temp = front;
        front = front->next;

        // if queue becomes empty
        if (front == NULL)
        {
            rear = NULL;
        }

        delete temp;
    }
    // Get front element
    int getFront()
    {
        if (front == NULL)
        {
            cout << "Queue is Empty!" << endl;
            return -1;
        }

        return front->data;
    }

    // Check empty
    bool isEmpty()
    {
        return front == NULL;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return;
        }

        Node *temp = front;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    // Destructor
    ~Queue()
    {
        while (front != NULL)
        {
            Node *temp = front;
            front = front->next;
            delete temp;
        }

        rear = NULL;
    }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << "Queue: ";
    q.display();

    cout << "Front Element: " << q.getFront() << endl;

    q.dequeue();

    cout << "After Dequeue: ";
    q.display();

    q.enqueue(50);

    cout << "After Enqueue: ";
    q.display();

    cout << "Front Element: " << q.getFront() << endl;

    return 0;
}