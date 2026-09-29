#include <iostream>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    // Destructor
    ~Node()
    {
        cout << "Memory free for node with data " << data << endl;
    }
};

// ================= INSERT NODE =================
void InsertNode(Node *&tail, int element, int d)
{
    // Empty list
    if (tail == NULL)
    {
        Node *newNode = new Node(d);

        tail = newNode;
        newNode->next = newNode;

        return;
    }

    // Non-empty list
    Node *curr = tail;

    // Find the element
    do
    {
        if (curr->data == element)
        {
            Node *temp = new Node(d);

            temp->next = curr->next;
            curr->next = temp;

            // If insertion is after tail,
            // new node becomes the new tail
            if (curr == tail)
            {
                tail = temp;
            }

            return;
        }

        curr = curr->next;

    } while (curr != tail);

    cout << "Element " << element << " not found!" << endl;
}

// ================= PRINT =================
void print(Node *tail)
{
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    Node *temp = tail->next; // head

    do
    {
        cout << temp->data << " ";
        temp = temp->next;

    } while (temp != tail->next);

    cout << endl;
}

// ================= DELETE NODE =================
void DeleteNode(Node *&tail, int value)
{
    // Empty list
    if (tail == NULL)
    {
        cout << "List is empty, please check again" << endl;
        return;
    }

    Node *prev = tail;
    Node *curr = tail->next;

    // Search for node
    do
    {
        if (curr->data == value)
        {
            break;
        }

        prev = curr;
        curr = curr->next;

    } while (curr != tail->next);

    // Value not found
    if (curr->data != value)
    {
        cout << "Value not found" << endl;
        return;
    }

    // Only one node
    if (curr == tail && curr->next == tail)
    {
        tail = NULL;
        curr->next = NULL;
        delete curr;
        return;
    }

    // Deleting head
    if (curr == tail->next)
    {
        prev->next = curr->next;
    }

    // Deleting tail
    else if (curr == tail)
    {
        prev->next = curr->next;
        tail = prev;
    }

    // Deleting middle node
    else
    {
        prev->next = curr->next;
    }

    curr->next = NULL;
    delete curr;
}

// ================= CIRCULAR CHECK =================
bool isCircular(Node *head)
{
    // empty list case
    if (head == NULL)
    {
        return NULL;
    }

    Node *temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }

    if (temp == head)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// =================== Loop Check ===================
// map approach 1

// bool detectLoop(Node *head)
// {
//     if (head == NULL)
//     {
//         return false;
//     }
//     map<Node *, bool>visited;

//     Node *temp = head;
//     while (temp != NULL)
//     {
//         if (visited[temp] == true)
//         {
//             return 1;
//         }
//         visited[temp] = true;
//         temp = temp->next;
//     }

//     return false;
// }

// approach 2

bool floydDetectLoop(Node *head)
{

    if (head == NULL)
        return false;

    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;

        if (slow == fast)
        {
            return 1;
        }
    }
    return false;
}

// ================= MAIN =================
int main()
{
    Node *tail = NULL;

    InsertNode(tail, 5, 3);
    print(tail);

    InsertNode(tail, 3, 5);
    print(tail);

    InsertNode(tail, 5, 7);
    print(tail);

    InsertNode(tail, 7, 9);
    print(tail);

    InsertNode(tail, 5, 6);
    print(tail);

    // DeleteNode(tail, 3);
    // print(tail);

    // ================= CIRCULAR CHECK =================

    Node *head = tail->next;

    if (isCircular(head))
    {
        cout << "Linked List is Circular" << endl;
    }
    else
    {
        cout << "Linked List is NOT Circular" << endl;
    }

    return 0;
}