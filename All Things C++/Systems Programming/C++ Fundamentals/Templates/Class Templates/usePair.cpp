#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

#include "Pair.h"

int main(int argc, char **argv) {
    Pair<std::string> ps;  // this usage instantiates a class Pair<std::string>
    std::string x("foo"), y("bar");

    ps.set_first(x);   // first_ = "foo", second_ = ""
    ps.set_second(y);  // first_ = "foo", second_ = "bar"
    std::cout << ps << std::endl;  // nonmember overloaded operator<< invoked
    ps.Swap();         // first_ = "bar", second_ = "foo"
    std::cout << ps << std::endl;  // nonmember overloaded operator<< invoked

    return EXIT_SUCCESS;
}