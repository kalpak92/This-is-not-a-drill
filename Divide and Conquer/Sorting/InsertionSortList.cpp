/**
 * Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.
 * 
 * The steps of the insertion sort algorithm:
 * - Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
 * - At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
 * - It repeats until no input elements remain.
 * 
 * Input: head = [4,2,1,3]
 * Output: [1,2,3,4]
 * 
 * Input: head = [-1,5,3,4,0]
 * Output: [-1,0,3,4,5]
 * 
 * Constraints:
 * The number of nodes in the list is in the range [1, 5000].
 * -5000 <= Node.val <= 5000
*/


#include <climits>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(INT_MIN);
        dummy->next = head;

        ListNode *prev = dummy;
        ListNode *current = head;

        while (current) {
            ListNode *candidate = current->next;
            
            // If candidate's value is lesser than current's value
            if ((candidate) && (candidate->val < current->val)) {
                // Find the position to enter the candidate
                while ((prev->next) && (prev->next->val < candidate->val)) {
                    prev = prev->next;
                }

                ListNode* temp = prev->next;        // we need to store prev's next as the candidate is to be inserted here
                prev->next = candidate;             // make the alteration
                current->next = candidate->next;    // alter the current list to next element of the candidate, since candidate has found it's place
                candidate->next = temp;             // restore candidate's next to point to temp
                
                // reset prev
                prev = dummy;
            }
            else {
                current = current->next;    // shift current to the next one
            }
        }
        return dummy -> next;
    }
};

int main(int argc, char const *argv[])
{
    ListNode *head = new ListNode(5);
    head->next = new ListNode(2);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(6);
    head->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next = new ListNode(3);

    ListNode *result = Solution().insertionSortList(head);

    ListNode *expectedOutput = new ListNode(1);
    expectedOutput->next = new ListNode(2);
    expectedOutput->next->next = new ListNode(3);
    expectedOutput->next->next->next = new ListNode(4);
    expectedOutput->next->next->next->next = new ListNode(5);
    expectedOutput->next->next->next->next->next = new ListNode(6);

    // Check if the result is as expected
    while (result) {
        if (result->val != expectedOutput->val) {
            std::cout << "Test failed" << std::endl;
            return -1;
        }
        result = result->next;
        expectedOutput = expectedOutput->next;
    }
    std::cout << "Test passed" << std::endl;

    return 0;
}
