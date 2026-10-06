#include <iostream>
using namespace std;

// ============================================
// NODE
// ============================================

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int data)
    {
        val = data;
        next = nullptr;
    }
};

// ============================================
// INSERT AT TAIL
// ============================================

void insertAtTail(ListNode *&head, ListNode *&tail, int value)
{

    ListNode *temp = new ListNode(value);

    if (head == nullptr)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

// ============================================
// PRINT LINKED LIST
// ============================================

void print(ListNode *head)
{

    while (head != nullptr)
    {
        cout << head->val << " -> ";
        head = head->next;
    }

    cout << "NULL" << endl;
}

// ============================================
// DELETE LINKED LIST
// ============================================

void deleteList(ListNode *&head)
{

    while (head != nullptr)
    {

        ListNode *temp = head;
        head = head->next;

        delete temp;
    }
}

// ============================================
// SOLUTION
// ============================================

class Solution
{

private:
    void insertAtTail(ListNode *&head,
                      ListNode *&tail,
                      int value)
    {

        ListNode *temp = new ListNode(value);

        if (head == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        int carry = 0;

        ListNode *ansHead = nullptr;
        ListNode *ansTail = nullptr;

        while (l1 != nullptr ||
               l2 != nullptr ||
               carry != 0)
        {

            int val1 = 0;
            int val2 = 0;

            if (l1 != nullptr)
            {
                val1 = l1->val;
            }

            if (l2 != nullptr)
            {
                val2 = l2->val;
            }

            // Calculate sum
            int sum = val1 + val2 + carry;

            // Get digit
            int digit = sum % 10;

            // Get carry
            carry = sum / 10;

            // Insert digit
            insertAtTail(ansHead, ansTail, digit);

            // Move l1
            if (l1 != nullptr)
            {
                l1 = l1->next;
            }

            // Move l2
            if (l2 != nullptr)
            {
                l2 = l2->next;
            }
        }

        return ansHead;
    }
};

// ============================================
// MAIN
// ============================================

int main()
{

    Solution obj;

    // ============================================
    // TEST CASE 1
    //
    // 342 + 465 = 807
    //
    // LeetCode representation:
    // 2 -> 4 -> 3
    // 5 -> 6 -> 4
    //
    // Answer:
    // 7 -> 0 -> 8
    // ============================================

    ListNode *head1 = nullptr;
    ListNode *tail1 = nullptr;

    ListNode *head2 = nullptr;
    ListNode *tail2 = nullptr;

    insertAtTail(head1, tail1, 2);
    insertAtTail(head1, tail1, 4);
    insertAtTail(head1, tail1, 3);

    insertAtTail(head2, tail2, 5);
    insertAtTail(head2, tail2, 6);
    insertAtTail(head2, tail2, 4);

    cout << "============================" << endl;
    cout << "TEST CASE 1" << endl;
    cout << "============================" << endl;

    cout << "List 1: ";
    print(head1);

    cout << "List 2: ";
    print(head2);

    ListNode *ans1 = obj.addTwoNumbers(head1, head2);

    cout << "Answer: ";
    print(ans1);

    cout << endl;

    // ============================================
    // TEST CASE 2
    //
    // 999 + 1 = 1000
    //
    // 9 -> 9 -> 9
    // 1
    //
    // Answer:
    // 0 -> 0 -> 0 -> 1
    // ============================================

    ListNode *head3 = nullptr;
    ListNode *tail3 = nullptr;

    ListNode *head4 = nullptr;
    ListNode *tail4 = nullptr;

    insertAtTail(head3, tail3, 9);
    insertAtTail(head3, tail3, 9);
    insertAtTail(head3, tail3, 9);

    insertAtTail(head4, tail4, 1);

    cout << "============================" << endl;
    cout << "TEST CASE 2" << endl;
    cout << "============================" << endl;

    cout << "List 1: ";
    print(head3);

    cout << "List 2: ";
    print(head4);

    ListNode *ans2 = obj.addTwoNumbers(head3, head4);

    cout << "Answer: ";
    print(ans2);

    cout << endl;

    // ============================================
    // TEST CASE 3
    //
    // 0 + 0 = 0
    //
    // 0
    // 0
    //
    // Answer:
    // 0
    // ============================================

    ListNode *head5 = nullptr;
    ListNode *tail5 = nullptr;

    ListNode *head6 = nullptr;
    ListNode *tail6 = nullptr;

    insertAtTail(head5, tail5, 0);
    insertAtTail(head6, tail6, 0);

    cout << "============================" << endl;
    cout << "TEST CASE 3" << endl;
    cout << "============================" << endl;

    cout << "List 1: ";
    print(head5);

    cout << "List 2: ";
    print(head6);

    ListNode *ans3 = obj.addTwoNumbers(head5, head6);

    cout << "Answer: ";
    print(ans3);

    cout << endl;

    // ============================================
    // TEST CASE 4
    //
    // 9999 + 999 = 10998
    //
    // 9 -> 9 -> 9 -> 9
    // 9 -> 9 -> 9
    //
    // Answer:
    // 8 -> 9 -> 9 -> 0 -> 1
    // ============================================

    ListNode *head7 = nullptr;
    ListNode *tail7 = nullptr;

    ListNode *head8 = nullptr;
    ListNode *tail8 = nullptr;

    insertAtTail(head7, tail7, 9);
    insertAtTail(head7, tail7, 9);
    insertAtTail(head7, tail7, 9);
    insertAtTail(head7, tail7, 9);

    insertAtTail(head8, tail8, 9);
    insertAtTail(head8, tail8, 9);
    insertAtTail(head8, tail8, 9);

    cout << "============================" << endl;
    cout << "TEST CASE 4" << endl;
    cout << "============================" << endl;

    cout << "List 1: ";
    print(head7);

    cout << "List 2: ";
    print(head8);

    ListNode *ans4 = obj.addTwoNumbers(head7, head8);

    cout << "Answer: ";
    print(ans4);

    cout << endl;

    // ============================================
    // DELETE MEMORY
    // ============================================

    deleteList(head1);
    deleteList(head2);
    deleteList(ans1);

    deleteList(head3);
    deleteList(head4);
    deleteList(ans2);

    deleteList(head5);
    deleteList(head6);
    deleteList(ans3);

    deleteList(head7);
    deleteList(head8);
    deleteList(ans4);

    return 0;
}