/**
 * You are given two non-empty linked lists representing two non-negative integers. 
 * The most significant digit comes first and each of their nodes contains a single digit. 
 * Add the two numbers and return the sum as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * 
 * Example 1:
 * Input: l1 = [7,2,4,3], l2 = [5,6,4]
 * Output: [7,8,0,7]
 * 
 * Example 2:
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [8,0,7]
 * 
 * Example 3:
 * Input: l1 = [0], l2 = [0]
 * Output: [0]
*/


#include <iostream>
#include <stack>
#include "ListNode.h"

using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* current = head;

        int carry = 0;
        stack<int> s1;
        stack<int> s2;

        while (l1 != nullptr) {
            s1.push(l1->val);
            l1 = l1->next;
        }

        while (l2 != nullptr) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        while (!s1.empty() || !s2.empty()) {
            int sum = carry;

            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }

            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }

            // Addition is complete
            // Compute the carry and single digit sum
            carry = sum / 10;
            sum = sum % 10;

            ListNode* result = new ListNode(sum);
            result->next = current; // add the result node to the head of the list (adding in reverse order)
            current = result;
        }

        // check for residual carry
        if (carry != 0) {
            ListNode* result = new ListNode(carry);
            result->next = current;
            current = result;
        }
        return current;
    }
};

int main() {
    Solution solution;
    ListNode* l1 = new ListNode(7);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    l1->next->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode* result = solution.addTwoNumbers(l1, l2);
    while (result != nullptr) {
        std::cout << result->val << " ";
        result = result->next;
    }
    std::cout << std::endl;
    
    return 0;

}