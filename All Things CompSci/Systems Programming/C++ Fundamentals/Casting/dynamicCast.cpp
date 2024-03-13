#include <cassert>

class Base {
    public:
        // virtual function included to make hierarchy polymorphic
        virtual void foo() { }
        float x;
};

class Der1 : public Base {
    public:
        char x;
};

int main(int argc, char** argv) {
    Base b; Der1 d;

    // OK (run-time check passes)
    Base* bptr = dynamic_cast<Base*>(&d);
    assert(bptr != nullptr);

    // OK (run-time check passes)
    Der1* dptr = dynamic_cast<Der1*>(bptr);
    assert(dptr != nullptr);

    // Run-time check fails, so the cast returns nullptr
    /**
     * The selected code is using a dynamic cast to attempt to convert a base class pointer (`bptr`) to a derived class pointer (`dptr`). 
     * The `dynamic_cast` operator in C++ is used for converting polymorphic types. 
     * It's primarily used for safely converting a pointer (or reference) of a base class type to a derived class type. 
     * The safety comes from the fact that `dynamic_cast` performs a runtime check to ensure the conversion is valid.
     * 
     * In the code snippet, `bptr` is assigned the address of `b`. 
     * Then, `dynamic_cast` is used to attempt to convert `bptr` (which is a pointer to [`Base`]). 
     * If the object `bptr` is pointing to is indeed a [`Der1`] object, the cast will fail, and `dynamic_cast` will return `nullptr`.
     */
    bptr = &b;
    dptr = dynamic_cast<Der1*>(bptr);
    assert(dptr != nullptr);

    return 0;
}