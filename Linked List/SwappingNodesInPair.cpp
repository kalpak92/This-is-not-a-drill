/**
 * Given a linked list, swap every two adjacent nodes and return its head. 
 * You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
 * 
 * Example 1:
 * Input: head = [1,2,3,4]
 * Output: [2,1,4,3]
 * 
 * Example 2:
 * Input: head = []
 * Output: []
 * 
 * Example 3:
 * Input: head = [1]
 * Output: [1]
 * 
 * Constraints:
 * The number of nodes in the list is in the range [0, 100].
 * 0 <= Node.val <= 100
*/

#include <iostream>
#include "ListNode.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* current = head;

        while ((current != nullptr) && (current->next != nullptr)) {
            // Nodes to be swapped
            ListNode* first_node = current;
            ListNode* second_node = current->next;

            // Swap the Nodes
            prev->next = second_node;
            first_node->next = second_node->next;
            second_node->next = first_node;

            prev = first_node; // firstNode is now the prev for the next swapping pair
            current = first_node->next; // jump
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
    std::cout << std::endl;
}

int main() {
    Solution solution;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    std::cout << "Original Linked List: ";
    printLinkedList(head);

    ListNode* result = solution.swapPairs(head);
    std::cout << "Swapped Linked List: ";
    printLinkedList(result);

    return 0;
}