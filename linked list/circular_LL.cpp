#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory free for node with data " << value << endl;
    }
};

void InsertNode(Node *&tail, int element, int d)
{
    // asuming that the elemrnt is present in the list

    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        // non-empty list
        // assuming that the element is present in the list

        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        // elemnt found and current is representing
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node *&tail)
{
    Node *temp = tail;
    if(tail == NULL){
        cout << "list is empty" << endl;
        return;
    }
    do
    {
        cout << temp->data << " ";
        tail = temp->next;
    } while (temp != temp);
    cout << endl;
}

void DeleteNode(Node *&tail, int value)
{
    // empty list
    if (tail == NULL)
    {
        cout << "List is empty, please check again" << endl;
        return;
    }

    Node *prev = tail;
    Node *curr = prev->next;

    // Find the node
    while (curr->data != value)
    {
        prev = curr;
        curr = curr->next;

        // value doesn't exist
        if (curr == tail->next)
        {
            cout << "Value not found" << endl;
            return;
        }
    }

    // Only one node
    if (curr == prev)
    {
        tail = NULL;
    }

    // More than one node
    else
    {
        prev->next = curr->next;

        // deleting tail node
        if (curr == tail)
        {
            tail = prev;
        }
    }

    curr->next = NULL;
    delete curr;
}

int main()
{
    Node *tail = NULL;

    InsertNode(tail, 5, 3);
    print(tail);
    InsertNode(tail, 3, 5);
    print(tail);
    // InsertNode(tail, 5, 7);
    // print(tail);
    // InsertNode(tail, 7, 9);
    // print(tail);
    // InsertNode(tail, 5, 6);
    // print(tail);
    DeleteNode(tail, 3);
    print(tail);
    return 0;
}