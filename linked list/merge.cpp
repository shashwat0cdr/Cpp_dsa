// merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

#include <iostream>
using namespace std;

// Node class
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
};

// Insert node at tail
void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);

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

// Print linked list
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

// --------------------------------------------------
// Merge two sorted linked lists
// --------------------------------------------------

Node *solve(Node *first, Node *second)
{
    Node *curr1 = first;
    Node *next1 = curr1->next;

    Node *curr2 = second;
    Node *next2 = curr2->next;

    if (next1 == NULL)
    {
        curr1->next = curr2;
        return first;
    }

    while (next1 != NULL && curr2 != NULL)
    {
        // Insert curr2 between curr1 and next1
        if (curr2->data >= curr1->data &&
            curr2->data <= next1->data)
        {
            // Add node between first list
            curr1->next = curr2;

            // Save next node of second list
            next2 = curr2->next;

            // Connect curr2 to next1
            curr2->next = next1;

            // Update pointers
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            // Move forward in first list
            curr1 = next1;
            next1 = next1->next;

            // If first list ends,
            // attach remaining second list
            if (next1 == NULL)
            {
                curr1->next = curr2;
            }
        }
    }

    return first;
}

// Main function to merge two sorted lists
Node *sortTwoLists(Node *first, Node *second)
{
    // If first list is empty
    if (first == NULL)
    {
        return second;
    }

    // If second list is empty
    if (second == NULL)
    {
        return first;
    }

    // Make first point to the list
    // having smaller first element
    if (first->data < second->data)
    {
        return solve(first, second);
    }
    else
    {
        return solve(second, first);
    }
}

// --------------------------------------------------
// MAIN
// --------------------------------------------------

int main()
{
    // ============================================
    // TEST CASE 1
    // ============================================

    Node *head1 = NULL;
    Node *tail1 = NULL;

    Node *head2 = NULL;
    Node *tail2 = NULL;

    // First sorted list
    insertAtTail(head1, tail1, 1);
    insertAtTail(head1, tail1, 3);
    insertAtTail(head1, tail1, 5);
    insertAtTail(head1, tail1, 7);

    // Second sorted list
    insertAtTail(head2, tail2, 2);
    insertAtTail(head2, tail2, 4);
    insertAtTail(head2, tail2, 6);
    insertAtTail(head2, tail2, 8);

    cout << "========== TEST CASE 1 ==========" << endl;

    cout << "First List:  ";
    print(head1);

    cout << "Second List: ";
    print(head2);

    Node *ans1 = sortTwoLists(head1, head2);

    cout << "Merged List: ";
    print(ans1);

    cout << endl;

    // ============================================
    // TEST CASE 2
    // ============================================

    Node *head3 = NULL;
    Node *tail3 = NULL;

    Node *head4 = NULL;
    Node *tail4 = NULL;

    // First sorted list
    insertAtTail(head3, tail3, 1);
    insertAtTail(head3, tail3, 4);
    insertAtTail(head3, tail3, 7);
    insertAtTail(head3, tail3, 10);

    // Second sorted list
    insertAtTail(head4, tail4, 2);
    insertAtTail(head4, tail4, 3);
    insertAtTail(head4, tail4, 8);
    insertAtTail(head4, tail4, 9);

    cout << "========== TEST CASE 2 ==========" << endl;

    cout << "First List:  ";
    print(head3);

    cout << "Second List: ";
    print(head4);

    Node *ans2 = sortTwoLists(head3, head4);

    cout << "Merged List: ";
    print(ans2);

    cout << endl;

    // ============================================
    // TEST CASE 3: [1] + [2]
    // ============================================

    Node *head5 = NULL;
    Node *tail5 = NULL;

    Node *head6 = NULL;
    Node *tail6 = NULL;

    // First list: [1]
    insertAtTail(head5, tail5, 1);

    // Second list: [2]
    insertAtTail(head6, tail6, 2);

    cout << "========== TEST CASE 3 ==========" << endl;

    cout << "First List:  ";
    print(head5);

    cout << "Second List: ";
    print(head6);

    Node *ans3 = sortTwoLists(head5, head6);

    cout << "Merged List: ";
    print(ans3);

    return 0;
}