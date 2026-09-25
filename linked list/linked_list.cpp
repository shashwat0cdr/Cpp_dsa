// Singly Linked List
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // Destructor
    ~Node()
    {
        cout << "Memory freed for node with data "
             << data << endl;
    }
};

// ================= INSERT AT HEAD =================

void insertAtHead(Node *&head, Node *&tail, int d)
{
    Node *newNode = new Node(d);

    // Empty list
    if (head == NULL)
    {
        head = tail = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;
}

// ================= INSERT AT TAIL =================

void insertAtTail(Node *&head, Node *&tail, int d)
{
    Node *newNode = new Node(d);

    // Empty list
    if (head == NULL)
    {
        head = tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

// ================= INSERT AT POSITION =================

void insertAtPosition(Node *&head, Node *&tail, int pos, int d)
{
    // Position 1
    if (pos <= 1)
    {
        insertAtHead(head, tail, d);
        return;
    }

    // Empty list
    if (head == NULL)
    {
        cout << "Invalid position!" << endl;
        return;
    }

    Node *temp = head;

    // Reach node at pos - 1
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++)
    {
        temp = temp->next;
    }

    // If inserting after current tail
    if (temp == tail)
    {
        insertAtTail(head, tail, d);
        return;
    }

    Node *newNode = new Node(d);

    newNode->next = temp->next;
    temp->next = newNode;
}

// ================= DELETE NODE =================

void deleteNode(Node *&head, Node *&tail, int pos)
{
    // Empty list
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    // Delete first node
    if (pos == 1)
    {
        Node *temp = head;

        head = head->next;

        // If only one node existed
        if (head == NULL)
        {
            tail = NULL;
        }

        temp->next = NULL;
        delete temp;

        return;
    }

    Node *prev = head;
    Node *curr = head->next;

    // Reach required position
    for (int i = 2; i < pos && curr != NULL; i++)
    {
        prev = curr;
        curr = curr->next;
    }

    // Invalid position
    if (curr == NULL)
    {
        cout << "Invalid position!" << endl;
        return;
    }

    // If deleting tail
    if (curr == tail)
    {
        tail = prev;
    }

    prev->next = curr->next;
    curr->next = NULL;

    delete curr;
}

// ================= PRINT =================

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

// ================= REVERSE =================
// recursive approach
Node *reverse1(Node *head)
{
    // base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *smallHead = reverse1(head->next);

    head->next->next = head;
    head->next = NULL;

    return smallHead;
}
void reverse(Node *&head, Node *curr, Node *prev)
{
    // base case
    if (curr == NULL)
    {
        head = prev;
        return;
    }

    // recursive case
    Node *forward = curr->next;
    reverse(head, forward, curr);
    curr->next = prev;
};

// normal approach
Node *reverseList(Node *head)
{
    return reverse1(head);
    // Node *prev = NULL;
    // Node *curr = head;

    // while (curr != NULL)
    // {
    //     Node *forward = curr->next;

    //     curr->next = prev;

    //     prev = curr;
    //     curr = forward;
    // }

    // reverse(head, curr, prev);

    // return head;
}
// ============== Middle of list =================

int getLength(Node *head)
{
    int len = 0;
    while (head != NULL)
    {
        len++;
        head = head->next;
    }

    return len;
}
// approach 1 but not optimized
Node *findMiddle(Node *head)
{
    int len = getLength(head);
    int ans = (len / 2);
    Node *temp = head;
    int cnt = 0;
    while (cnt < ans)
    {
        temp = temp->next;
        cnt++;
    }
    return temp;
}

// approach 2 but optimized
Node *getMiddle(Node *head)
{

    // empty list
    if (head == NULL || head -> next == NULL)
    {
        return head;
    }
    if(head -> next -> next == NULL){
        return head -> next;
    }

    Node* slow = head;
    Node* fast = head-> next;
    while(fast != NULL){
        fast = fast -> next;
        if(fast != NULL){
            fast = fast -> next;
        } 
        slow = slow -> next;
    }
    return slow;
}
// ================= MAIN =================

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    // Insert elements
    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 12);
    insertAtTail(head, tail, 15);

    cout << "Original List: ";
    //print(head);

    // Insert at position
    insertAtPosition(head, tail, 2, 11);

    //cout << "After inserting 11 at position 2: ";
    //print(head);

    // Insert at head
    insertAtHead(head, tail, 5);

    //cout << "After inserting 5 at head: ";
   // print(head);

    // Insert at tail
    insertAtTail(head, tail, 20);

    //cout << "After inserting 20 at tail: ";
    print(head);

   // cout << "\nHead: " << head->data << endl;
   // cout << "Tail: " << tail->data << endl;

    // Delete node
    //deleteNode(head, tail, 3);

   // cout << "\nAfter deleting position 3: ";
   // print(head);

   // cout << "Head: " << head->data << endl;
   // cout << "Tail: " << tail->data << endl;

    // Reverse
    //head = reverseList(head);

    // IMPORTANT: after reversing, old head becomes tail
    // So update tail
    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    tail = temp;

    //cout << "\nReversed List: ";
    //print(head);

    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    Node *ans = getMiddle(head);
    if (ans != NULL)
    {
        cout << "Middle: " << ans->data << endl;
    }
    else
    {
        cout << "List is empty!" << endl;
    }
    return 0;
}