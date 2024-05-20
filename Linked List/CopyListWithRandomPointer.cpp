/**
 * A linked list of length n is given such that each node contains an additional random pointer, 
 * which could point to any node in the list, or null.
 * 
 * Construct a deep copy of the list. 
 * The deep copy should consist of exactly n brand new nodes, 
 * where each new node has its value set to the value of its corresponding original node. 
 * Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. 
 * None of the pointers in the new list should point to nodes in the original list.
 * 
 * For example, if there are two nodes X and Y in the original list, where X.random --> Y, 
 * then for the corresponding two nodes x and y in the copied list, x.random --> y.
 * 
 * Return the head of the copied linked list.
 * The linked list is represented in the input/output as a list of n nodes. 
 * Each node is represented as a pair of [val, random_index] where:
 * val: an integer representing Node.val
 * random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
 * Your code will only be given the head of the original linked list.
*/

#include <iostream>

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return head;

        Node* current = head;

        // copy the nodes
        while (current != nullptr) {
            Node* new_node = new Node(current->val);
            new_node->next = current->next;
            current->next = new_node;
            current = current->next->next;
        }

        // copy the random pointers to the new_node
        current = head;
        while (current != nullptr) {
            if (current->random != nullptr)
                current->next->random = current->random->next;
            else
                current->next->random = nullptr;

            current = current->next->next;
        }

        // split the lists
        Node* list1 = head;
        Node* list2 = head->next;
        Node* cloned_head = head->next;

        while (list1 != nullptr) {
            list1->next = list1->next->next;        // hop list1

            if (list2->next != nullptr) {           // ensure the next node is not null since we reference the next of next
                list2->next = list2->next->next;    // hop list2
            } else {
                list2->next = nullptr;
            }

            list1 = list1->next;
            list2 = list2->next;
        }
        return cloned_head;
    }
};

int main() {
    Solution solution;
    Node* head = new Node(7);
    head->next = new Node(13);
    head->next->random = head;
    head->next->next = new Node(11);
    head->next->next->random = head->next;
    head->next->next->next = new Node(10);
    head->next->next->next->random = head->next->next;
    head->next->next->next->next = new Node(1);
    head->next->next->next->next->random = head;

    Node* result = solution.copyRandomList(head);
    while (result != nullptr) {
        std::cout << result->val << " ";
        result = result->next;
    }
    std::cout << std::endl;
    return 0;
}