void foo(int* x) {
    (*x)++;
}

// const_cast is used to add or remove const-ness from a pointer or reference.
// It is the only C++ cast that can be used to remove const-ness.
void bar(const int* x) {
    //foo(x);                    // compiler error
    foo(const_cast<int*>(x));  // succeeds
}

int main(int argc, char** argv) {
    int x = 7;
    bar(&x);

    return 0;
}