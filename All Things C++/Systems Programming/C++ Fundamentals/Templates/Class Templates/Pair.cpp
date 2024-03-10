// Class template member functions defined outside of the
// class template definition need a template function
// declaration that matches the template parameter list.
// An instance of each template function is instantiated
// when the class template is instantiated and that member
// function is invoked somewhere in code.

// The template parameter list is usually found on a
// separate line from the template function due to the
// lengths of function parameter lists.
// There is no change in behavior, just readability.

#include "Pair.h"
#include <ostream>
template <typename Thing>
void Pair<Thing>::set_first(const Thing &copyme) {
    _first = copyme;
}

template <typename Thing>
void Pair<Thing>::set_second(const Thing &copyme) {
    _second = copyme;
}

template <typename Thing>
void Pair<Thing>::Swap() {
    Thing tmp = _first;
    _first = _second;
    _second = tmp;
}


// Nonmember function for ostream output -- individual
// template parameters can take any name, but usually we
// choose to be consistent.  T chosen here instead of Thing
// for brevity and for fitting onto lecture slides.
template <typename T>
std::ostream &operator<<(std::ostream &out, const Pair<T> &p) {
    return out << "Pair(" << p.get_first() << ", " << p.get_second() << ")";
}