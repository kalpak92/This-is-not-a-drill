#include <iostream>
#include <cstdlib>
#include <string>

int main(int argc, char** argv) {
    // Here we are instantiating a std::string object on the stack (an ordinary local variable)
    // Passing the C string "Hello, World!" to its constructor method
    std::string hello("Hello, World!");
    std::cout << hello << std::endl;
    return EXIT_SUCCESS;
}