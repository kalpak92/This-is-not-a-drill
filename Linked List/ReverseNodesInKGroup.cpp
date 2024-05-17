/**
 * Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
 * k is a positive integer and is less than or equal to the length of the linked list. 
 * 
 * If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
 * You may not alter the values in the list's nodes, only nodes themselves may be changed.
 * 
 * Example 1:
 * Input: head = [1,2,3,4,5], k = 2
 * Output: [2,1,4,3,5]
 * 
 * Example 2:
 * Input: head = [1,2,3,4,5], k = 3
 * Output: [3,2,1,4,5]
*/

#include <iostream>
#include "ListNode.h"

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Test if we have more than k nodes
        // If less than k nodes, we return head.
        // Note: while reading the code, 
        // the reversal logic only takes place while unwinding the stack frame.
        ListNode* current = head;
        int count = 0;

        while (current != nullptr && count != k) {
            current = current->next;
            count++;
        }

        // Reverse k nodes at the current level
        if (count == k) {
            // Recursively call for the next k group of nodes.
            ListNode* prev = reverseKGroup(current, k);

            // We recentre current to the head node of the previous call stack (before calling reverseKGroup in line 29).
            // prev points to what got returned from the recursive call
            current = head;
            while (count > 0) {
                ListNode* next = current->next;
                current->next = prev;
                prev = current;
                current = next;
                count--;
            }
            head = prev;
        }
        return head;
    }
};

/**
 * Time Complexity: O(n)
 * Space Complexity: O(n/k) where n is the number of nodes in the linked list and k is the group size.
*/

int main() {
    Solution solution;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* result = solution.reverseKGroup(head, 2);
    while (result != nullptr) {
        std::cout << result->val << " ";
        result = result->next;
    }
    std::cout << std::endl;

    return 0;
}