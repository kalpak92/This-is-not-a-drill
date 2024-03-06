#include <iostream>
#include <cstdlib>
#include <string>

int main(int argc, char** argv) {
    std::string hello("Hello, ");
    std::string world("World!");
    std::string helloWorld = hello + world;
    
    std::cout << helloWorld << std::endl;
    return EXIT_SUCCESS;
}