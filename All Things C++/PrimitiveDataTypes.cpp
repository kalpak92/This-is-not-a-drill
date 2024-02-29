/**
 * Data models
 * The choices made by each implementation about the sizes of the fundamental types are collectively known as data model. 
 * Four data models found wide acceptance:
 * 32 bit systems:
 *      LP32 or 2/4/4 (int is 16-bit, long and pointer are 32-bit)
 *          Win16 API
 *      ILP32 or 4/4/4 (int, long, and pointer are 32-bit);
 *          Win32 API
 *          Unix and Unix-like systems (Linux, macOS)
 *  64 bit systems:
 *      LLP64 or 4/4/8 (int and long are 32-bit, pointer is 64-bit)
 *          Win32 API (also called the Windows API) with compilation target 64-bit ARM (AArch64) or x86-64 (a.k.a. x64)
 *      LP64 or 4/8/8 (int is 32-bit, long and pointer are 64-bit)
 *          Unix and Unix-like systems (Linux, macOS)
*/

#include <iostream>

int main() {
    std::cout << "Size of char: " << sizeof(char) << " byte" << std::endl;
    std::cout << "Size of unsigned char: " << sizeof(unsigned char) << " byte" << std::endl;
    std::cout << "Size of signed char: " << sizeof(signed char) << " byte" << std::endl;
    std::cout << "Size of int: " << sizeof(int) << " bytes" << std::endl;
    std::cout << "Size of unsigned int: " << sizeof(unsigned int) << " bytes" << std::endl;
    std::cout << "Size of signed int: " << sizeof(signed int) << " bytes" << std::endl;
    std::cout << "Size of short int: " << sizeof(short int) << " bytes" << std::endl;
    std::cout << "Size of long int: " << sizeof(long int) << " bytes" << std::endl;
    std::cout << "Size of unsigned long int: " << sizeof(unsigned long int) << " bytes" << std::endl;
    std::cout << "Size of long long int: " << sizeof(long long int) << " bytes" << std::endl;
    std::cout << "Size of unsigned long long int: " << sizeof(unsigned long long int) << " bytes" << std::endl;

    std::cout << "Size of bool: " << sizeof(bool) << " bytes" << std::endl;

    std::cout << "Size of void*: " << sizeof(void*) << " bytes" << std::endl;
    std::cout << "Size of nullptr: " << sizeof(nullptr) << " bytes" << std::endl;

    std::cout << "Size of float: " << sizeof(float) << " bytes" << std::endl;
    std::cout << "Size of double: " << sizeof(double) << " bytes" << std::endl;
}