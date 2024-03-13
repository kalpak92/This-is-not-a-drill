#ifndef _COMPLEX_H_
#define _COMPLEX_H_

#include <iostream>

namespace complex {

    class Complex {
        // Style tip: always put your public members before private members.
        public:
            Complex(const double real, const double imag);  // Constructor
            Complex(const double real);                     // overloaded Constructor
            Complex(const Complex& copyme);                 // Copy constructor
            ~Complex();                                     // Destructor

            // Accessors / mutators, defined inline.
            double real() const { return real_; }
            double imag() const { return imag_; }
            void set_real(const double real) { real_ = real; }
            void set_imag(const double imag) { imag_ = imag; }

            // Override the "-", "=", "+=", and "-=" operators.
            // Note that "-", like "+", could have been a non-member
            // function.  That would generally be better style since it can reduce
            // the amount of code with access to private instance data, and allows
            // "-" to treat its operators symmetrically, but we made it a member
            // function here as an example of what is possible.
            // "=", "+=", and "-=" normally should be member functions since
            // they do mutate the object's state instead of producing a new
            // object as a result.
            Complex operator-(const Complex &a) const;
            Complex &operator=(const Complex &a);
            Complex &operator+=(const Complex &a);
            Complex &operator-=(const Complex &a);

            // Overload ">>" for istream.  Note that this is a global
            // function, not a member function of class Complex.  It could
            // have been implemented as an ordinary, non-friend function
            // using the set_real() and set_imag() member functions and that
            // would generally be better style since it reduces the code that
            // has access to private data.  See "<<" for an example of a
            // non-friend stream i/o function.
            friend std::istream &operator>>(std::istream &in, Complex &a);

        private:
            double real_, imag_;  // Member variables.
            };  // class Complex

            // additional overloaded operators (not member or friend functions)
            // (see above notes above about "-" and "<<", which should usually
            // be done this way also when possible)

            Complex operator+(const Complex &a, const Complex &b);

            std::ostream &operator<<(std::ostream &out, const Complex &a);

}  // namespace complex

#endif  // _COMPLEX_H_