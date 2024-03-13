#include <cstdlib>  // for EXIT_SUCCESS
#include <memory>   // for std::shared_ptr, std::weak_ptr

using std::shared_ptr;
using std::weak_ptr;

struct A {
    shared_ptr<A> next;
    weak_ptr<A> prev;
};

int main(int argc, char **argv) {
    shared_ptr<A> head(new A());
    head->next = shared_ptr<A>(new A());
    head->next->prev = head;            // weak cycle . OK!

    // head and head->next are now in a weak cycle and will be deleted.

    return EXIT_SUCCESS;
}