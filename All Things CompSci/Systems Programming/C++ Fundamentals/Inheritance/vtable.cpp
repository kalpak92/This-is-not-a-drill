#include <iostream>

class Base {
    public:
        virtual void f1() {
            std::cout << "Base::f1()" << std::endl;
        }

        virtual void f2() {
            std::cout << "Base::f2()" << std::endl;
        }
};

class Der1: public Base {
    public:
        virtual void f1() {
            std::cout << "Der1::f1()" << std::endl;
        }
};

int main(int argc, char** argv) {
    Der1 d1;
    d1.f1();
    Base* bptr = &d1;
    bptr->f1();
}

// g++ -g -o vtable vtable.cpp
// objdump -CDS vtable > vtable.d