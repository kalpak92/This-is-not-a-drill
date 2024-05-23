/**
 * You are given the head of a linked list, and an integer k.
 * Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).
 * 
 * Example 1:
 * Input: head = [1,2,3,4,5], k = 2
 * Output: [1,4,3,2,5]
 * 
 * Example 2:
 * Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
 * Output: [7,9,6,6,8,7,3,0,9,5]
 * 
 * Constraints:
 * The number of nodes in the list is n.
 * 1 <= k <= n <= 10^5
 * 0 <= Node.val <= 100
*/



#include <iostream>
#include <algorithm>
#include "ListNode.h"

using namespace std;

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int length_of_list = 0;             // track the length of the list
        ListNode* front_node = nullptr;
        ListNode* end_node = nullptr;
        
        ListNode* current_node = head;      // used to traverse the linkedlist

        while (current_node != nullptr) {
            length_of_list++;               // increment the length of the list
            if (end_node != nullptr)        // move the end_node to the next node only after k nodes
                end_node = end_node->next;

            if (length_of_list == k) {      
                // We are at position k from the beginning
                // front_node is the node at position k from the beginning
                // end_node starts from head and moves to the kth node from the beginning
                front_node = current_node;
                end_node = head;
            }
            current_node = current_node->next;
        }

        // Swap the values. No need to swap the nodes explicitly
        swap(front_node->val, end_node->val);
        return head;
    }
};

int main() {
    Solution solution;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;
    ListNode* result = solution.swapNodes(head, k);
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    return 0;
}