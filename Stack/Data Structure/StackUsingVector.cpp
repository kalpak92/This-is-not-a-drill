/**
 * Stack using vector as the underlying container.
*/

#include <iostream>
#include <stack>
#include <vector>

// Print a stack
void printStack(std::stack<int, std::vector<int>> s) {
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
}

int main() {
    std::stack<int, std::vector<int>> myStack;

    // Pushing elements into the stack
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    std::cout << "Top element: " << myStack.top() << std::endl;
    int holdOntoTopElement = myStack.top(); // Hold onto the top element before popping
    myStack.pop();
    std::cout << "Top element after pop: " << myStack.top() << std::endl;

    std::stack<int> myStack2({-3, -2, -1}); // Initialize stack with elements
    std::cout << "Printing elements in myStack2" << std::endl;
    while (!myStack2.empty()) {
        std::cout << "\tresult: " << myStack2.top() << std::endl;
        myStack2.pop();
    }

    std::cout << "Printing elements in myStack3" << std::endl;
    std::stack<int, std::vector<int>> myStack3({-3, -2, -1, 0}); // Initialize stack with elements
    printStack(myStack3);
}