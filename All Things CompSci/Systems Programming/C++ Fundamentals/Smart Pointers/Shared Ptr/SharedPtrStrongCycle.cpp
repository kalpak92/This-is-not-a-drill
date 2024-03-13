#include <cstdlib>  // for EXIT_SUCCESS
#include <memory>   // for std::shared_ptr

using std::shared_ptr;

struct A {
    shared_ptr<A> next;
    shared_ptr<A> prev;
};

int main(int argc, char **argv) {
    shared_ptr<A> head(new A());
    head->next = shared_ptr<A>(new A());
    head->next->prev = head;            // strong cycle . Uf oh!

    // head and head->next are now in a strong cycle and will never be deleted.

    return EXIT_SUCCESS;
}