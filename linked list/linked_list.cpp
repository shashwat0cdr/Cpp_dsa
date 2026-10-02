// Singly Linked List
#include <iostream>
#include <map>
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
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    if (head->next->next == NULL)
    {
        return head->next;
    }

    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}

// ======================== K - reverse ==================================

Node *K_reverse(Node *head, int k)
{
    // base call
    if (head == NULL || k <= 1)
    {
        return head;
    }

    // step 1: reverse first k nodes
    Node *next = NULL;
    Node *curr = head;
    Node *prev = NULL;

    int count = 0;
    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // step 2 recursion
    if (next != NULL)
    {
        head->next = K_reverse(next, k);
    }

    // step -3 return
    return prev;
}

// ================= CIRCULAR CHECK =================
bool isCircular(Node *head)
{
    // empty list case
    if (head == NULL)
    {
        return false;
    }

    Node *temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }

    return temp == head;
}

// =================== Loop Check ===================

bool detectLoop(Node *head)
{
    if (head == NULL)
    {
        return false;
    }

    map<Node *, bool> visited;

    Node *temp = head;
    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            cout << "present on element " << temp->data << endl;
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }

    return false;
}
// approach 2

Node *floydDetectLoop(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            cout << "Loop present at " << slow->data << endl;
            return slow;
        }
    }

    return NULL;
}

// ============ Starting Node ================
Node *getStartingNode(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *intersection = floydDetectLoop(head);
    if (intersection == NULL)
    {
        return NULL;
    }

    Node *slow = head;

    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

// =============== removal of loop ================

void removeLoop(Node *head)
{

    if (head == NULL)
    {
        return;
    }

    Node *startOfLoop = getStartingNode(head);
    Node *temp = startOfLoop;

    while (temp->next != startOfLoop)
    {
        temp = temp->next;
    }

    temp->next = NULL;
}

// ================== remove duplicates ===================
//- sorted linked list
Node *removeDupicates(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    // non empty list 
    Node *curr = head;

    while (curr != NULL)
    {
        if (curr->next != NULL && curr->data == curr->next->data)
        {
            Node *next_next = curr->next->next;
            Node *nodeToDelete = curr->next;
            delete nodeToDelete;
            curr -> next = next_next;
        }
        else
        {
            curr = curr->next;
        }
    }

    return head;
}

// unsorted linked list
// brute fore O(n^2)

Node *removeDuplicatesUnsorted(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *curr = head;

    while (curr != NULL)
    {
        Node *temp = curr;

        while (temp->next != NULL)
        {
            if (curr->data == temp->next->data)
            {
                Node *nodeToDelete = temp->next;

                temp->next = temp->next->next;

                delete nodeToDelete;
            }
            else
            {
                temp = temp->next;
            }
        }

        curr = curr->next;
    }

    return head;
}
// ================= MAIN =================

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    // Insert elements
    //insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 12);
    insertAtTail(head, tail, 15);

    cout << "Original List: ";
    // print(head);

    // Insert at position
   // insertAtPosition(head, tail, 2, 10);
    //insertAtPosition(head, tail, 3, 10);
    insertAtPosition(head, tail, 7, 11);
    //insertAtPosition(head, tail, 8, 11);
    //insertAtPosition(head, tail, 9, 11);

    // cout << "After inserting 11 at position 2: ";
    // print(head);

    // Insert at head
    insertAtHead(head, tail, 5);

    // cout << "After inserting 5 at head: ";
    // print(head);

    // Insert at tail
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 45);
    insertAtTail(head, tail, 23);
    
    // cout << "After inserting 20 at tail: ";
    print(head);

    // tail->next = head->next;

    cout << "\nHead: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    // Delete node
    // deleteNode(head, tail, 3);

    // cout << "\nAfter deleting position 3: ";
    // print(head);

    // cout << "Head: " << head->data << endl;
    // cout << "Tail: " << tail->data << endl;

    // Reverse
    // head = reverseList(head);

    // IMPORTANT: after reversing, old head becomes tail.
    // Do not iterate through the list after creating a cycle.
    // tail = temp;

    // cout << "\nReversed List: ";
    // print(head);

    // cout << "Head: " << head->data << endl;
    // cout << "Tail: " << tail->data << endl;

    // Node *ans = getMiddle(head);
    // if (ans != NULL)
    // {
    //     // cout << "Middle: " << ans->data << endl;
    // }
    // else
    // {
    //     // cout << "List is empty!" << endl;
    // }

    head = K_reverse(head, 5);
    Node *temp2 = head;

    while (temp2 != NULL && temp2->next != NULL)
    {
     temp2 = temp2->next;
     }

    tail = temp2;

    cout << "After K-reversal (k=5): ";
    print(head);
    // cout << "New Head: " << head->data << endl;
    // cout << "New Tail: " << tail->data << endl;

    // ================= CIRCULAR CHECK =================

    // if (isCircular(head))
    // {
    //     cout << "Linked List is Circular" << endl;
    // }
    // else
    // {
    //     cout << "Linked List is NOT Circular" << endl;
    // }

    // if (floydDetectLoop(head) != NULL)
    // {
    //     cout << "Cycle is present" << endl;
    //     Node *start = getStartingNode(head);
    //     if (start != NULL)
    //     {
    //         cout << "Loop starting at: " << start->data << endl;
    //     }
    // }
    // else
    // {
    //     cout << "no cycle" << endl;
    // }

    // removeLoop(head);
   // print(head);

    //removeDupicates(head);
   
    // removeDuplicatesUnsorted(head);
    // print(head);

    return 0;
}