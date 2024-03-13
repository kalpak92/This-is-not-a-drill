#include <algorithm>  // for sort()
#include <cstdlib>    // for EXIT_SUCCESS
#include <iostream>   // for std::cout, std::endl
#include <memory>     // for std::unique_vec
#include <vector>     // for std::vector

using std::unique_ptr;
using std::vector;

bool sortfunction(const unique_ptr<int> &x,
		  const unique_ptr<int> &y) {
    return *x < *y;
}

void printfunction(unique_ptr<int> &x) {
    std::cout << *x << std::endl;
}

int main(int argc, char **argv) {
    vector<unique_ptr<int> > vec;

    vec.push_back(unique_ptr<int>(new int(9)));
    vec.push_back(unique_ptr<int>(new int(5)));
    vec.push_back(unique_ptr<int>(new int(7)));

    // buggy: sorts based on the values of the ptrs
    std::sort(vec.begin(), vec.end());
    std::cout << "Buggy Sorted:" << std::endl;
    std::for_each(vec.begin(), vec.end(), &printfunction);

    // better: sorts based on the pointed-to values
    std::sort(vec.begin(), vec.end(), &sortfunction);
    std::cout << "\nSorted:" << std::endl;
    std::for_each(vec.begin(), vec.end(), &printfunction);

    return EXIT_SUCCESS;
}