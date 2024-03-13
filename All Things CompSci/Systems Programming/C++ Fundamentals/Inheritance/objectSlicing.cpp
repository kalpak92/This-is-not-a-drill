class Base {
    public:
        Base(int x) : x(x) { }
        int x;
};

class Der1 : public Base {
    public:
        Der1(int y) : Base(16), y(y) { }
        int y;
};

int main(int argc, char** argv) {
    Base b(1);
    Der1 d(2);
    b = d;  // what happens to y?
    // d = b;  // compiler error
}