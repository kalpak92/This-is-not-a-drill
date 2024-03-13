class A {
    public:
        int x;
};

class B {
    public:
        float x;
};

class C : public B {
    public:
        char x;
};

int main(int argc, char** argv) {
    B b; C c;

    // compiler error
    // A* aptr = static_cast<A*>(&b);

    // OK
    B* bptr = static_cast<B*>(&c); 
    
    // compiles, but dangerous
    C* cptr = static_cast<C*>(&b);

    return 0;
}