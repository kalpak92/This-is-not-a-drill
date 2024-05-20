/**
 * You are given the head of a linked list.
 * Remove every node which has a node with a greater value anywhere to the right side of it.
 * Return the head of the modified linked list.
 * 
 * Example 1:
 * Input: head = [5,2,13,3,8]
 * Output: [13,8]
 * 
 * Explanation: The nodes that should be removed are 5, 2 and 3.
 *      - Node 13 is to the right of node 5.
 *      - Node 13 is to the right of node 2.
 *      - Node 8 is to the right of node 3.
 * 
 * Example 2:
 * Input: head = [1,1,1,1]
 * Output: [1,1,1,1]
 * Explanation: Every node has value 1, so no nodes are removed.
 * 
 * Constraints:
 * The number of the nodes in the given list is in the range [1, 105].
 * 1 <= Node.val <= 105
*/

#include <iostream>
#include <stack>
#include "ListNode.h"

using namespace std;

class Solution {
public:
    ListNode* removeNodesUsingStack(ListNode* head) {
        stack<ListNode*> stack;

        ListNode* current = head;
        
        while (current != nullptr) {
            // if stack.top()->val < current->val
            // this means current element is greater than the previous element (left side)
            // This makes the element in the stack to be discarded.
            // Continue doing this until the condition is held true
            while (!stack.empty() && stack.top()->val < current->val) {
                stack.pop();
            }
            stack.push(current);
            current = current->next;
        }

        // Stack now has elements which are part of the result
        // Reverse the stack to obtain the modified linked list.
        ListNode* next = nullptr;   // acts as the tail
        while (!stack.empty()) {
            current = stack.top();
            stack.pop();
            current->next = next;
            next = current;
        }

        return current;
    }

    ListNode* removeNodes(ListNode* head) {
        ListNode* reversedHead = reverseList(head);
        ListNode* itr = reversedHead;

        while (itr->next != nullptr) {
            // if current node's val is > next node's val
            // remove the next node
            if (itr->val > itr->next->val)
                itr->next = itr->next->next;
            else
                itr = itr->next;
        }

        return reverseList(reversedHead);
    }

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

void printLinkedList(ListNode* head) {
    ListNode* current = head;

    while (current != nullptr) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Solution solution;
    ListNode* head = new ListNode(5);
    head->next = new ListNode(2);
    head->next->next = new ListNode(13);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(8);

    cout << "Original Linked List: ";
    printLinkedList(head);

    ListNode* result = solution.removeNodes(head);
    cout << "Modified Linked List: ";
    printLinkedList(result);

    return 0;
}