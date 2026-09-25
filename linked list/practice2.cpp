#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << " Memory is free for node with data " << value << endl;
    }
};

void InsertAtHead(Node *&head, Node *&tail, int d)
{
    // new Node
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node *&head, Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}

void InsertAtPos(Node *&head, Node *&tail, int pos, int d)
{
    // pos 1
    if (pos == 1)
    {
        InsertAtHead(head, tail, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }
    // last pos
    if (temp->next = NULL)
    {
        InsertAtTail(head, tail, d);
        return;
    }

    // creating a node for d
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

// deleting a node

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    InsertAtTail(head, tail, 20);
    print(head);
    InsertAtHead(head, tail, 60);
    print(head);
    InsertAtPos(head, tail, 4,80);
    print(head);
}