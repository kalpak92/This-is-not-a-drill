#ifndef _PAIR_H_
#define _PAIR_H_

/**
 * Ckass template definition for a pair of values
 */
template <typename Thing> class Pair {
    public:
        Pair() {}; // default constructor

        Thing get_first() const { return _first; }
        Thing get_second() const { return _second; }

        void set_first(const Thing &value);
        void set_second(const Thing &value);

        void Swap();

    private:
        Thing _first;
        Thing _second;
};

/**
 * Non-member function declaration
*/

template <typename T>
std::ostream &operator<<(std::ostream &out, const Pair<T> &p);

#include "Pair.cpp"

#endif  // _PAIR_H_