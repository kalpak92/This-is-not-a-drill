#include <iostream>  // cout, endl
#include <string>    // string
#include <cstdlib>   // EXIT_SUCCESS

// returns 0 if equal, 1 if value1 is bigger, -1 otherwise
template <typename T>
int compare(const T& value1, const T& value2) {
    if (value1 < value2) return -1;
    if (value2 < value1) return 1;
    return 0;
}

int main(int argc, char** argv) {
    std::string h("hello"), w("world");
    
    std::cout << compare(10, 20) << std::endl;  // ok
    std::cout << compare(h, w) << std::endl;  // ok
    std::cout << compare("Hello", "World") << std::endl;  // hm...

    return EXIT_SUCCESS;
}