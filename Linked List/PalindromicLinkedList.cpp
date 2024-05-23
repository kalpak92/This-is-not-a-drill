/**
 * Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
 * 
 * Example 1:
 * Input: head = [1,2,2,1]
 * Output: true
 * 
 * Example 2:
 * Input: head = [1,2]
 * Output: false
 * 
 * Constraints:
 * The number of nodes in the list is in the range [1, 105].
 * 0 <= Node.val <= 9
 * 
 * Follow up: Could you do it in O(n) time and O(1) space?
*/

#include <iostream>
#include "ListNode.h"
#include <ios>

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow = reverseList(slow);
        fast = head;

        while (slow != nullptr) {
            if (slow->val != fast->val)
                return false;
            else {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return true;
    }

private:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
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

int main() {
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    std::cout << "Is the linked list palindrome: " << std::boolalpha << s.isPalindrome(head) << std::endl;
    return 0;
}