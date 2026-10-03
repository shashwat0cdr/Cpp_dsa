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
        // cout << "Memory is free for node with data " << value << endl;
    }
};

// Insert node at tail
void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

// Print Linked List
void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

// Sort 0s, 1s and 2s
// approach 1
Node *sortList1(Node *head)
{
    int ZeroCount = 0;
    int OneCount = 0;
    int TwoCount = 0;

    Node *temp = head;

    // Count 0, 1 and 2
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            ZeroCount++;
        }
        else if (temp->data == 1)
        {
            OneCount++;
        }
        else if (temp->data == 2)
        {
            TwoCount++;
        }

        temp = temp->next;
    }

    // Put values back in sorted order
    temp = head;

    while (temp != NULL)
    {
        if (ZeroCount != 0)
        {
            temp->data = 0;
            ZeroCount--;
        }
        else if (OneCount != 0)
        {
            temp->data = 1;
            OneCount--;
        }
        else if (TwoCount != 0)
        {
            temp->data = 2;
            TwoCount--;
        }

        temp = temp->next;
    }

    return head;
}

// approach 2
void position(Node *&tail, Node *curr)
{
    tail->next = curr;
    tail = curr;
    curr->next = NULL;
}

Node *sortList(Node *head)
{
    Node *zerohead = new Node(-1);
    Node *zerotail = zerohead;

    Node *onehead = new Node(-1);
    Node *onetail = onehead;

    Node *twohead = new Node(-1);
    Node *twotail = twohead;

    Node *curr = head;

    while (curr != NULL)
    {
        Node *next = curr->next;
        int value = curr->data;

        if (value == 0)
        {
            position(zerotail, curr);
        }
        else if (value == 1)
        {
            position(onetail, curr);
        }
        else if (value == 2)
        {
            position(twotail, curr);
        }
        curr = next;
    }

    if (onehead->next != NULL)
    {
        zerotail->next = onehead->next;
    }
    else
    {
        zerotail->next = twohead->next;
    }
    onetail->next = twohead->next;
    twotail->next = NULL;

    head = zerohead->next;

    zerohead->next = NULL;
    onehead->next = NULL;
    twohead->next = NULL;

    delete zerohead;
    delete onehead;
    delete twohead;

    return head;
}

int main()
{
    // =========================
    // TEST CASE 1
    // =========================

    Node *head1 = NULL;
    Node *tail1 = NULL;

    insertAtTail(head1, tail1, 1);
    insertAtTail(head1, tail1, 2);
    insertAtTail(head1, tail1, 0);
    insertAtTail(head1, tail1, 2);
    insertAtTail(head1, tail1, 1);
    insertAtTail(head1, tail1, 0);

    cout << "Test Case 1:" << endl;

    cout << "Before Sorting: ";
    print(head1);

    head1 = sortList(head1);

    cout << "After Sorting:  ";
    print(head1);

    cout << endl;

    // =========================
    // TEST CASE 2
    // =========================

    Node *head2 = NULL;
    Node *tail2 = NULL;

    insertAtTail(head2, tail2, 2);
    insertAtTail(head2, tail2, 2);
    insertAtTail(head2, tail2, 1);
    insertAtTail(head2, tail2, 0);
    insertAtTail(head2, tail2, 1);
    insertAtTail(head2, tail2, 0);
    insertAtTail(head2, tail2, 2);

    cout << "Test Case 2:" << endl;

    cout << "Before Sorting: ";
    print(head2);

    head2 = sortList(head2);

    cout << "After Sorting:  ";
    print(head2);

    return 0;
}

