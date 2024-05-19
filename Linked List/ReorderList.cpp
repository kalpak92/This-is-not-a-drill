/**
 * You are given the head of a singly linked-list. 
 * 
 * The list can be represented as:
 * L0 → L1 → … → Ln - 1 → Ln
 * 
 * Reorder the list to be on the following form:
 * L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
 * 
 * You may not modify the values in the list's nodes. 
 * Only nodes themselves may be changed.
 * 
 * Example 1:
 * Input: head = [1,2,3,4]
 * Output: [1,4,2,3]
 * 
 * Example 2:
 * Input: head = [1,2,3,4,5]
 * Output: [1,5,2,4,3]
 * 
 * Constraints:
 * The number of nodes in the list is in the range [1, 5 * 10^4].
 * 1 <= Node.val <= 1000
 * 
*/

#include <iostream>
#include "ListNode.h"

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return;
        
        // Find the middle of the linkedlist
        ListNode* prev = nullptr;
        ListNode* head1 = head;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Separate the lists
        prev->next = nullptr;
        ListNode* head2 = slow;

        // Reverse the 2nd half of the linked list
        head2 = reverseLL(head2);

        // Merge the two Linkedlists alternatively
        mergeLL(head1, head2);

    }

    ListNode* reverseLL(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* current = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }

    void mergeLL(ListNode* head1, ListNode* head2) {
        while (head1 != nullptr) {
            // Store the next pointers of both the lists
            ListNode* temp1 = head1->next;
            ListNode* temp2 = head2->next;

            // Assign the alternalte list pointers to the next pointer of both heads
            head1->next = head2;

            if (temp1 == nullptr)
                break;          
            head2->next = temp1;

            // Now assign temp points to head
            head1 = temp1;
            head2 = temp2;
        }
    }
};

void printLinkedList(ListNode* head) {
    ListNode* current = head;

    while (current != nullptr) {
        std::cout << current->val << " -> ";
        current = current->next;
    }

    std::cout << "NULL" << std::endl;
}

int main() {
    Solution solution;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    solution.reorderList(head);
    printLinkedList(head);

    return 0;
}