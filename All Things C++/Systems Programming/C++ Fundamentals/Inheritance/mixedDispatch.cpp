#include <iostream>

using namespace std;

class A {
    public:
        void m1() { cout << "a1, "; }
        virtual void m2() { cout << "a2"; }
};

class B : public A {
    public:
        void m1() { cout << "b1, "; }
        void m2() { cout << "b2"; }
};

int main(int argc, char** argv) {
    A a;
    B b;
    A* a_ptr_a = &a;
    A* a_ptr_b = &b;
    //B* ba_ptr = &a;  // compiler error
    B* b_ptr_b = &b;

    a_ptr_a->m1();
    a_ptr_a->m2();
    cout << endl;
    a_ptr_b->m1();
    a_ptr_b->m2();
    cout << endl;
    b_ptr_b->m1();
    b_ptr_b->m2();
    cout << endl;

    return 0;
}