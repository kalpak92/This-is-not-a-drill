/**
 * A string is a sequence of characters. In C++, a string is represented by the std::string class.
 * The definitions of the operations are supplied via the Traits template parameter:
 *      - A specialization of std::char_traits or a compatible traits class.
 *      - The default is std::char_traits<char>, which treats the characters as simple bytes.
 * 
 * 
 * The class template basic_string_view describes an object that can refer to a constant contiguous sequence of CharT with the first element of the sequence at position zero.
 * For a basic_string_view str, pointers, iterators, and references to elements of str are invalidated when an operation invalidates a pointer in the range [str.data(), str.data() + str.size()).
 * A typical implementation holds only two members: a pointer to constant CharT and a size.
 * 
*/

#include <iostream>
#include <string>
#include <string_view>

int main() {
    // std::string
    std::string str = "Hello, World!";
    std::cout << "String: " << str << std::endl;

    // std::string_view
    std::string_view strView = str;
    std::cout << "String View: " << strView << std::endl;

    // Size of the string and string view
    std::cout << "Size of the string: " << str.size() << std::endl;
    std::cout << "Size of the string view: " << strView.size() << std::endl;

    // Accessing elements
    std::cout << "First character: " << str[0] << std::endl;
    std::cout << "First character using at(): " << str.at(0) << std::endl;

    // Modifying elements
    str[0] = 'h';
    std::cout << "Modified string: " << str << std::endl;

    // Iterating over the string
    for (char c : str) {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    // Concatenation
    std::string str2 = " C++";
    str += str2;
    std::cout << "Concatenated string: " << str << std::endl;

    // Substring
    std::string subStr = str.substr(0, 5);
    std::cout << "Substring: " << subStr << std::endl;

    // Find
    size_t pos = str.find("C++");
    if (pos != std::string::npos) {
        std::cout << "Found at position: " << pos << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }

    // Erase
    str.erase(0, 6);
    std::cout << "Erased string: " << str << std::endl;

    // Clear
    str.clear();
    std::cout << "Cleared string: " << str << std::endl;

    return 0;
}