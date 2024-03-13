#include <iostream>
#include <string>
#include <cstdlib>

template <typename T>
int compare(const T &value1, const T &value2) {
    if (value1 < value2) return -1;
    if (value2 < value1) return 1;
    return 0;
}

int main(int argc, char **argv) {
    std::string h("Hello"), w("World");
    std::cout << compare<int>(10, 20) << std::endl;
    std::cout << compare<std::string>(h, w) << std::endl;
    std::cout << compare<double>(10.5, 10.5) << std::endl;

    return EXIT_SUCCESS;
}