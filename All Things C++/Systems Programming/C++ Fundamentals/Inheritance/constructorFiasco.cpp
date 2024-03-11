// Base has a default constructor.
class Base {
    public:
        int y;
};

// Works.
class Der1 : public Base {
    public:
        int z;
};

// Works.
class Der2 : public Base {
    public:
        Der2(int z) : z(z) { }
        int z;
};

int main(int argc, char **argv) {
    Base b;      // OK
    Der2 d2(1);  // OK
    Der1 d1;     // OK
    return 0;
}