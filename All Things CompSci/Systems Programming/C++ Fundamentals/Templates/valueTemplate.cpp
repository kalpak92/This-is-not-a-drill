#include <iostream>
#include <string>

// return pointer to new heap array with N copies of val (not quite
// realistic, but shows what’s possible -- better example would be a
// template whose non-type parameter specifies the size of a
// fixed-size queue or list in a class)
template <typename T, int N>
T* varray(const T &val) {
    T* a = new T[N];

    for(int i = 0; i < N; i++) {
        a[i] = val;
    }

    return a;
}

int main(int argc, char **argv) {
    int *ip = varray<int,10>(17);
    std::string *sp = varray<std::string,17>("hello");

    delete[] ip;
    delete[] sp;
    return EXIT_SUCCESS;
}