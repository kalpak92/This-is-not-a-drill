/**
 * You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
 * Merge all the linked-lists into one sorted linked-list and return it.
 * 
 * Example 1:
 * Input: lists = [[1,4,5],[1,3,4],[2,6]]
 * Output: [1,1,2,3,4,4,5,6]
 * Explanation: The linked-lists are:
 * [
 *      1->4->5,
 *      1->3->4,
 *      2->6
 * ]
 * merging them into one sorted list:
 *      1->1->2->3->4->4->5->6
 * 
 * Example 2:
 * Input: lists = []
 * Output: []
 * 
 * Example 3:
 * Input: lists = [[]]
 * Output: []
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode* next) : val(val), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* result = new ListNode(-1);
        ListNode* current = result;

        auto compareNodeValues = [](ListNode* left, ListNode* right) {
            return left->val > right->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(compareNodeValues)> minHeap(compareNodeValues);

        // Put the first element from each of the lists
        for (auto elem : lists) {
            if (elem != nullptr)
                minHeap.push(elem);
        }

        while(!minHeap.empty()) {
            ListNode* temp = minHeap.top();
            current->next = temp;
            minHeap.pop();
            current = current->next;

            if (temp->next != nullptr)
                minHeap.push(temp->next);
        }
        return result->next;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution s;
    vector<ListNode*> lists = {
        new ListNode(1, new ListNode(4, new ListNode(5))),
        new ListNode(1, new ListNode(3, new ListNode(4))),
        new ListNode(2, new ListNode(6))
    };
    cout << "Given lists: " << endl;
    for (ListNode* list : lists) {
        printList(list);
    }
    cout << "Merged list: ";
    ListNode* mergedList = s.mergeKLists(lists);
    printList(mergedList);

    lists = {};
    cout << "Given lists: " << endl;
    for (ListNode* list : lists) {
        printList(list);
    }
    cout << "Merged list: ";
    mergedList = s.mergeKLists(lists);
    printList(mergedList);

    lists = {nullptr};
    cout << "Given lists: " << endl;
    for (ListNode* list : lists) {
        printList(list);
    }
    cout << "Merged list: ";
    mergedList = s.mergeKLists(lists);
    printList(mergedList);

    return 0;
}