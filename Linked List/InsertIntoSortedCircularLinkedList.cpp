/**
 * Given a Circular Linked List node, which is sorted in non-descending order, 
 * write a function to insert a value insertVal into the list such that it remains a sorted circular list. 
 * The given node can be a reference to any single node in the list and may not necessarily be the smallest value in the circular list.
 * 
 * If there are multiple suitable places for insertion, you may choose any place to insert the new value. 
 * After the insertion, the circular list should remain sorted.
 * 
 * If the list is empty (i.e., the given node is null), 
 * you should create a new single circular list and return the reference to that single node. 
 * Otherwise, you should return the originally given node.
 * 
 * Example 1:
 * Input: head = [3,4,1], insertVal = 2
 * Output: [3,4,1,2]
 * Explanation: In the figure above, there is a sorted circular list of three elements. 
 * You are given a reference to the node with value 3, and we need to insert 2 into the list. 
 * The new node should be inserted between node 1 and node 3. 
 * After the insertion, the list should look like this, and we should still return node 3.
 * 
 * Example 2:
 * Input: head = [], insertVal = 1
 * Output: [1]
 * Explanation: The list is empty (given head is null). 
 * We create a new single circular list and return the reference to that single node.
 * 
 * Example 3:
 * Input: head = [1], insertVal = 0
 * Output: [1,0]
*/

#include <iostream>

class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = nullptr;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* insert_node = new Node(insertVal);

        if (head == nullptr) {
            insert_node->next = insert_node;
            return insert_node;
        }

        Node* current = head;

        while (true) {
            /**
             * Case 1: insertVal is between 2 nodes
             *      Eg. 1->2->4, insert 3
             * condition: insertVal >= current.val  &&  insertVal <= current.next.val
             * 
             * Case 2: insertVal is >= largest node value or <= smallest node value
             *     Eg. 1->2->4, insert 0 or 1->2->4, insert 5
             * condition: current.next.val < current.val  &&  
             *              (insertVal >=  current.val ||  insertVal <= current.next.val)
             * Case 3: All the nodes in the tree have same value
             *      Eg. 1->1->1, insert 2
             * condition: current.next == head
            */
            if ((insert_node->val >= current->val && insert_node->val <= current->next->val) ||
                    (current->next->val < current->val && 
                        (insertVal >= current->val || insertVal <= current->next->val)) ||
                    current->next == head) {
                insert_node->next = current->next;
                current->next = insert_node;
                break;
            }
            current = current->next;
        }
        return head;

    }
};

void printCircularLinkedList(Node* head) {
    Node* current = head;
    do {
        std::cout << current->val << " ";
        current = current->next;
    } while (current != head);
    std::cout << std::endl;
}

int main() {
    Solution solution;
    Node* head = new Node(3);
    head->next = new Node(4);
    head->next->next = new Node(1);
    head->next->next->next = head;
    std::cout << "Original Linked List: ";
    printCircularLinkedList(head);

    std::cout << "Inserting 2 into the linked list: ";
    Node* result = solution.insert(head, 2);
    printCircularLinkedList(result);

    // Test case 2
    Node* head2 = nullptr;
    std::cout << "Inserting 1 into the linked list: ";
    Node* result2 = solution.insert(head2, 1);
    printCircularLinkedList(result2);

    // Test case 3
    Node* head3 = new Node(1);
    head3->next = head3;
    std::cout << "Inserting 0 into the linked list: ";
    Node* result3 = solution.insert(head3, 0);

    return 0;
}