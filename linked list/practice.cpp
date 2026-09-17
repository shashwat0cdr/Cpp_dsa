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

    // destructor
    ~Node()
    {
        int value = this->data;
        if (this->data != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for node with data " << value << endl;
    }
};

void insertAtHead(Node *&head, int d)
{
    // new node create
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}

void insertAtPos(Node *&head, Node *&tail, int pos, int d)
{

    // at starting waala case
    if (pos == 1)
    {
        insertAtHead(head, d);
        return;
    }
    Node *temp = head;
    int cnt = 1;

    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // at last wala case handle krenge
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(int pos, Node *&head)
{
    // first node handle
    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting any node handle
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while(cnt < pos){
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;

    }
}

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
    // creating a node
    Node *node1 = new Node(10);
    // cout << node1->data << endl;
    // cout << node1->next << endl;

    Node *head = node1;
    Node *tail = node1;
    print(head);
    insertAtHead(head, 12);
    print(head);
    insertAtTail(tail, 14);
    print(head);
    insertAtPos(head, tail, 4, 16);
    print(head);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;

    deleteNode(4, head);
    print(head);

    return 0;
}