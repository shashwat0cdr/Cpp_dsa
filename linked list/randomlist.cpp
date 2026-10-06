/*
    Problem: Clone a linked list with next and random pointer
    Link: https://leetcode.com/problems/copy-list-with-random-pointer/
    Difficulty: Medium
#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// Insert at tail
void insertAtTail(Node*& head, Node*& tail, int value)
{
    Node* newNode = new Node(value);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

// Print list
void printList(Node* head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout << "Value: " << temp->val;

        if (temp->random != NULL)
            cout << ", Random: " << temp->random->val;
        else
            cout << ", Random: NULL";

        cout << endl;

        temp = temp->next;
    }

    cout << endl;
}

// Clone using HashMap
Node* copyRandomList(Node* head)
{
    if (head == NULL)
        return NULL;

    // STEP 1: Create clone list
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    Node* temp = head;

    while (temp != NULL)
    {
        insertAtTail(cloneHead, cloneTail, temp->val);
        temp = temp->next;
    }

    // STEP 2: Create mapping
    unordered_map<Node*, Node*> oldToNew;

    Node* originalNode = head;
    Node* cloneNode = cloneHead;

    while (originalNode != NULL)
    {
        oldToNew[originalNode] = cloneNode;

        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

    // STEP 3: Copy random pointers
    originalNode = head;
    cloneNode = cloneHead;

    while (originalNode != NULL)
    {
        if (originalNode->random != NULL)
        {
            cloneNode->random =
                oldToNew[originalNode->random];
        }

        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

    return cloneHead;
}

int main()
{
    // =====================================================
    // TEST CASE 1
    // 1 -> 2 -> 3
    // Random:
    // 1 -> 3
    // 2 -> 1
    // 3 -> 2
    // =====================================================

    cout << "========== TEST CASE 1 ==========\n";

    Node* head1 = NULL;
    Node* tail1 = NULL;

    insertAtTail(head1, tail1, 1);
    insertAtTail(head1, tail1, 2);
    insertAtTail(head1, tail1, 3);

    head1->random = head1->next->next;       // 1 -> 3
    head1->next->random = head1;             // 2 -> 1
    head1->next->next->random = head1->next; // 3 -> 2

    cout << "Original:\n";
    printList(head1);

    Node* clone1 = copyRandomList(head1);

    cout << "Clone:\n";
    printList(clone1);


    // =====================================================
    // TEST CASE 2
    // 10 -> 20 -> 30
    // All random = NULL
    // =====================================================

    cout << "========== TEST CASE 2 ==========\n";

    Node* head2 = NULL;
    Node* tail2 = NULL;

    insertAtTail(head2, tail2, 10);
    insertAtTail(head2, tail2, 20);
    insertAtTail(head2, tail2, 30);

    cout << "Original:\n";
    printList(head2);

    Node* clone2 = copyRandomList(head2);

    cout << "Clone:\n";
    printList(clone2);


    // =====================================================
    // TEST CASE 3
    // 5 -> 15 -> 25 -> 35
    // Mixed random pointers
    // =====================================================

    cout << "========== TEST CASE 3 ==========\n";

    Node* head3 = NULL;
    Node* tail3 = NULL;

    insertAtTail(head3, tail3, 5);
    insertAtTail(head3, tail3, 15);
    insertAtTail(head3, tail3, 25);
    insertAtTail(head3, tail3, 35);

    head3->random = NULL;                    // 5 -> NULL
    head3->next->random = head3->next->next->next; // 15 -> 35
    head3->next->next->random = head3;       // 25 -> 5
    head3->next->next->next->random =
        head3->next;                         // 35 -> 15

    cout << "Original:\n";
    printList(head3);

    Node* clone3 = copyRandomList(head3);

    cout << "Clone:\n";
    printList(clone3);

    return 0;
}
*/


// method 2: without using extra space

#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// Insert at tail
void insertAtTail(Node *&head, Node *&tail, int value)
{
    Node *newNode = new Node(value);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

// Print list
void printList(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << "Value: " << temp->val;

        if (temp->random != NULL)
            cout << ", Random: " << temp->random->val;
        else
            cout << ", Random: NULL";

        cout << endl;

        temp = temp->next;
    }

    cout << endl;
}

// =====================================================
// CLONE USING INTERWEAVING
// =====================================================

Node *copyRandomList(Node *head)
{
    if (head == NULL)
        return NULL;

    // =================================================
    // STEP 1: Create clone nodes and insert them
    // between original nodes
    //
    // Original:
    // 1 -> 2 -> 3
    //
    // After:
    // 1 -> 1' -> 2 -> 2' -> 3 -> 3'
    // =================================================

    Node *curr = head;

    while (curr != NULL)
    {
        Node *cloneNode = new Node(curr->val);

        cloneNode->next = curr->next;
        curr->next = cloneNode;

        curr = cloneNode->next;
    }

    // =================================================
    // STEP 2: Copy random pointers
    // =================================================

    curr = head;

    while (curr != NULL)
    {
        Node *cloneNode = curr->next;

        if (curr->random != NULL)
        {
            cloneNode->random = curr->random->next;
        }
        else
        {
            cloneNode->random = NULL;
        }

        // Move to next original node
        curr = cloneNode->next;
    }

    // =================================================
    // STEP 3: Separate original and clone lists
    //
    // Before:
    //
    // 1 -> 1' -> 2 -> 2' -> 3 -> 3'
    //
    // After:
    //
    // Original:
    // 1 -> 2 -> 3
    //
    // Clone:
    // 1' -> 2' -> 3'
    // =================================================

    Node *original = head;
    Node *cloneHead = head->next;

    while (original != NULL)
    {
        Node *clone = original->next;

        original->next = clone->next;

        if (clone->next != NULL)
        {
            clone->next = clone->next->next;
        }
        else
        {
            clone->next = NULL;
        }

        original = original->next;
    }

    return cloneHead;
}

int main()
{
    // =====================================================
    // TEST CASE 1
    // 1 -> 2 -> 3
    // =====================================================

    cout << "========== TEST CASE 1 ==========\n";

    Node *head1 = NULL;
    Node *tail1 = NULL;

    insertAtTail(head1, tail1, 1);
    insertAtTail(head1, tail1, 2);
    insertAtTail(head1, tail1, 3);

    head1->random = head1->next->next;       // 1 -> 3
    head1->next->random = head1;             // 2 -> 1
    head1->next->next->random = head1->next; // 3 -> 2

    cout << "Original:\n";
    printList(head1);

    Node *clone1 = copyRandomList(head1);

    cout << "Clone:\n";
    printList(clone1);

    // =====================================================
    // TEST CASE 2
    // All random pointers NULL
    // =====================================================

    cout << "========== TEST CASE 2 ==========\n";

    Node *head2 = NULL;
    Node *tail2 = NULL;

    insertAtTail(head2, tail2, 10);
    insertAtTail(head2, tail2, 20);
    insertAtTail(head2, tail2, 30);

    cout << "Original:\n";
    printList(head2);

    Node *clone2 = copyRandomList(head2);

    cout << "Clone:\n";
    printList(clone2);

    // =====================================================
    // TEST CASE 3
    // Mixed random pointers
    // =====================================================

    cout << "========== TEST CASE 3 ==========\n";

    Node *head3 = NULL;
    Node *tail3 = NULL;

    insertAtTail(head3, tail3, 5);
    insertAtTail(head3, tail3, 15);
    insertAtTail(head3, tail3, 25);
    insertAtTail(head3, tail3, 35);

    head3->random = NULL; // 5 -> NULL
    head3->next->random =
        head3->next->next->next; // 15 -> 35
    head3->next->next->random =
        head3; // 25 -> 5
    head3->next->next->next->random =
        head3->next; // 35 -> 15

    cout << "Original:\n";
    printList(head3);

    Node *clone3 = copyRandomList(head3);

    cout << "Clone:\n";
    printList(clone3);

    return 0;
}