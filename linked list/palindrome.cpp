
#include <iostream>
using namespace std;

// ============================================
// NODE CLASS
// ============================================

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int data) {
        val = data;
        next = nullptr;
    }
};

// ============================================
// INSERT AT TAIL
// ============================================

void insertAtTail(ListNode*& head, ListNode*& tail, int data) {
    ListNode* newNode = new ListNode(data);

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

// ============================================
// PRINT LINKED LIST
// ============================================

void print(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// ============================================
// PALINDROME SOLUTION
// ============================================

class Solution {
private:

    // STEP 1: Find middle node
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    // STEP 2: Reverse linked list
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

public:

    bool isPalindrome(ListNode* head) {

        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        // Find middle
        ListNode* middle = getMid(head);

        // Reverse second half
        ListNode* temp = middle->next;
        middle->next = reverse(temp);

        // Compare both halves
        ListNode* head1 = head;
        ListNode* head2 = middle->next;

        bool palindrome = true;

        while (head2 != nullptr) {

            if (head1->val != head2->val) {
                palindrome = false;
                break;
            }

            head1 = head1->next;
            head2 = head2->next;
        }

        // Restore original linked list
        temp = middle->next;
        middle->next = reverse(temp);

        return palindrome;
    }
};

// ============================================
// DELETE LINKED LIST
// ============================================

void deleteList(ListNode*& head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// ============================================
// MAIN FUNCTION
// ============================================

int main() {

    Solution obj;

    // ============================================
    // TEST CASE 1: Odd length palindrome
    // 1 -> 2 -> 3 -> 2 -> 1
    // ============================================

    ListNode* head1 = nullptr;
    ListNode* tail1 = nullptr;

    insertAtTail(head1, tail1, 1);
    insertAtTail(head1, tail1, 2);
    insertAtTail(head1, tail1, 3);
    insertAtTail(head1, tail1, 2);
    insertAtTail(head1, tail1, 1);

    cout << "TEST CASE 1" << endl;
    print(head1);

    cout << "Palindrome: "
         << (obj.isPalindrome(head1) ? "YES" : "NO")
         << endl;

    cout << "After checking: ";
    print(head1);

    cout << endl;


    // ============================================
    // TEST CASE 2: Even length palindrome
    // 1 -> 2 -> 2 -> 1
    // ============================================

    ListNode* head2 = nullptr;
    ListNode* tail2 = nullptr;

    insertAtTail(head2, tail2, 1);
    insertAtTail(head2, tail2, 2);
    insertAtTail(head2, tail2, 2);
    insertAtTail(head2, tail2, 1);

    cout << "TEST CASE 2" << endl;
    print(head2);

    cout << "Palindrome: "
         << (obj.isPalindrome(head2) ? "YES" : "NO")
         << endl;

    cout << "After checking: ";
    print(head2);

    cout << endl;


    // ============================================
    // TEST CASE 3: Not a palindrome
    // 1 -> 2 -> 3 -> 4 -> 5
    // ============================================

    ListNode* head3 = nullptr;
    ListNode* tail3 = nullptr;

    insertAtTail(head3, tail3, 1);
    insertAtTail(head3, tail3, 2);
    insertAtTail(head3, tail3, 3);
    insertAtTail(head3, tail3, 4);
    insertAtTail(head3, tail3, 5);

    cout << "TEST CASE 3" << endl;
    print(head3);

    cout << "Palindrome: "
         << (obj.isPalindrome(head3) ? "YES" : "NO")
         << endl;

    cout << "After checking: ";
    print(head3);

    // Free allocated memory
    deleteList(head1);
    deleteList(head2);
    deleteList(head3);

    return 0;
}
