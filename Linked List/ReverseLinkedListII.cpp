/**
 * Given the head of a singly linked list and two integers left and right where left <= right, 
 * reverse the nodes of the list from position left to position right, and return the reversed list.
 * 
 * Example 1:
 * Input: head = [1,2,3,4,5], left = 2, right = 4
 * Output: [1,4,3,2,5]
 * 
 * Example 2:
 * Input: head = [5], left = 1, right = 1
 * Output: [5]
*/

#include <iostream>
#include "ListNode.h"

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        // Create a dummy node to keep track of the head node
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        // Create current and prev pointers
        ListNode* current = head;
        ListNode* prev = dummy;

        // Set the current pointer to the place from where it needs to be reversed
        for (int i = 1; i < left; i++) {
            prev = current;
            current = current->next;
        }

        // Store the current and prev nodes to connect them after reversing.
        // current is now at [left]
        // prev is at [left - 1]
        ListNode* currentCopy = current;
        ListNode* prevCopy = prev;
        ListNode* next = nullptr;

        // Reverse linked from [left, right]
        for (int i = left; i <= right; i++) {
            next = currentCopy->next;
            currentCopy->next = prevCopy;
            prevCopy = currentCopy;
            currentCopy = next;
        }

        // Connect the remaining part to the reversed linked list.
        prev->next = prevCopy;
        current->next = currentCopy;

        // return head stored by the dummy pointer
        return dummy->next;
    }
};

int main() {
    Solution solution;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* result = solution.reverseBetween(head, 2, 4);
    std::cout << "Linked List reversed from position 2 to 4: ";
    while (result != nullptr) {
        std::cout << result->val << " ";
        result = result->next;
    }
    std::cout << std::endl;

    return 0;
}