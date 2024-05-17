/**
 * Linked List
*/

#include <iostream>
#include <vector>

using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode* next) : val(val), next(next) {}
};

// Create a linked list using the ListNode class
ListNode* createLinkedList(vector<int> nums) {
    if (nums.empty()) {
        return nullptr;
    }

    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;

    for (int i = 1; i < nums.size(); i++) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }

    return head;
}

// Insert a new node at the beginning of the linked list
ListNode* insertAtBeginning(ListNode* head, int val) {
    ListNode* newHead = new ListNode(val);
    newHead->next = head;

    return newHead;
}

// Insert a new node at the end of the linked list
ListNode* insertAtEnd(ListNode* head, int val) {
    if (head == nullptr) {
        return new ListNode(val);
    }

    ListNode* current = head;

    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = new ListNode(val);

    return head;
}

// Print the linked list
void printLinkedList(ListNode* head) {
    ListNode* current = head;

    while (current != nullptr) {
        std::cout << current->val << " -> ";
        current = current->next;
    }

    std::cout << "NULL" << std::endl;
}

int main() {
    vector<int> nums{1, 2, 3, 4, 5};
   
    ListNode* head = createLinkedList(nums);
    printLinkedList(head);

    head = insertAtBeginning(head, 0);
    printLinkedList(head);

    head = insertAtEnd(head, 6);
    printLinkedList(head);

    return 0;
}