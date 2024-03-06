#include <iostream>
#include <cstdlib>
#include <iomanip>  // set of stream manipulator functions

int main(int argc, char** argv) {
    // setw(x) sets the width of the next field to x
    std::cout << "Hi! " << std::setw(4) << 5 << " " << 5 << std::endl;
    // hex, dec, and oct set the numerical base for integer output to the stream
    // Stays in effect until you set the stream to another base (i.e. it is persistent)
    std::cout << std::hex << 16 << " " << 13 << std::endl;
    std::cout << std::dec << 16 << " " << 13 << std::endl;

    return EXIT_SUCCESS;
}