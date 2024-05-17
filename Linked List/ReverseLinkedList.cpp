/**
 * Reverse a singly linked list.
 * 
 * Example:
 * Input: 1->2->3->4->5->NULL
 * Output: 5->4->3->2->1->NULL
 * 
 * **Follow up:**
 * A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

#include <iostream>
#include <vector>
#include "ListNode.h"

using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return head;

        ListNode* current = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while (current != nullptr) {
            // Store the next pointer and then change the next pointer to previous
            next = current->next;
            current->next = prev;

            // move the prev to current
            prev = current;

            // current moves to the next node which is stored locally
            current = next;
        }

        // Assign head as prev; since current is assigned to nullptr
        head = prev;
        return head;
    }
};

// Print the linked list
void printLinkedList(ListNode* head) {
    ListNode* current = head;

    while (current != nullptr) {
        std::cout << current->val << " -> ";
        current = current->next;
    }

    std::cout << "NULL" << std::endl;
}

int main() {
    Solution obj;

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original Linked List: ";
    printLinkedList(head);

    head = obj.reverseList(head);

    cout << "Reversed Linked List: ";
    printLinkedList(head);

    return 0;
}