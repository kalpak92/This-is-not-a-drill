/**
 * Given the head of a sorted linked list, delete all nodes that have duplicate numbers, 
 * leaving only distinct numbers from the original list. 
 * Return the linked list sorted as well.
 * 
 * Example 1:
 * Input: head = [1,2,3,3,4,4,5]
 * Output: [1,2,5]
 * 
 * Example 2:
 * Input: head = [1,1,1,2,3]
 * Output: [2,3]
*/

#include <iostream>
#include "ListNode.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prev = dummy;

        while (head != nullptr) {
            if (head->next != nullptr && head->val == head->next->val) {
                // traver to the last node of the duplicate sub list
                while (head->next != nullptr && head->val == head->next->val)
                    head = head->next;
                
                prev->next = head->next; // skip all duplicate nodes
            } else {
                prev = prev->next;
            }
            head = head->next;
        }

        return dummy->next;    
    }
};


void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << "NULL" << std::endl;
}

int main() {
    Solution solution;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);
    std::cout << "Original List: ";
    printLinkedList(head);
    std::cout << "Modified List: ";
    printLinkedList(solution.deleteDuplicates(head));

    head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(3);
    std::cout << "Original List: ";
    printLinkedList(head);
    std::cout << "Modified List: ";
    printLinkedList(solution.deleteDuplicates(head));
    return 0;
}