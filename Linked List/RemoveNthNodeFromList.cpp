/**
 * Given the head of a linked list, remove the nth node from the end of the list and return its head.
 * 
 * Example 1:
 * Input: head = [1,2,3,4,5], n = 2
 * Output: [1,2,3,5]
 * 
 * Example 2:
 * Input: head = [1], n = 1
 * Output: []
 * 
 * Example 3:
 * Input: head = [1,2], n = 1
 * Output: [1]
 * 
 * Constraints:
 * The number of nodes in the list is sz.
 * 1 <= sz <= 30
 * 0 <= Node.val <= 100
 * 1 <= n <= sz
*/

#include <iostream>
#include "ListNode.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr)
            return head;
        
        ListNode* slow = head;
        ListNode* fast = head;

        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Now check is fast is null or not.
        if (fast == nullptr)
            return head->next;

        // move the two pointers until fast->next != null 
        // this is because we want to reach the node prior to the target node
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // slow points to the previous node to target.
        // remove target by stitching the next of slow to its next of next
        slow->next = slow->next->next;
        
        return head;
    }
};

void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Solution solution;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "The given linked list is: ";
    printLinkedList(head);
    std::cout << "The linked list after removing the nth node from the end is: ";
    ListNode* result = solution.removeNthFromEnd(head, 2);
    printLinkedList(result);

    return 0;
}