#ifndef _COMPLEX_H_
#define _COMPLEX_H_

// Here's our typedef for a Complex number.  We choose to
// expose the type to customers, so that customers can directly
// access fields instead of having to use accessor functions.
//
// A complex number is ((real) + i*(imaginary))
typedef struct {
    double real;
    double imaginary;
} Complex, *ComplexPtr;

// Adds a and b, returns the result.
Complex ComplexAdd(Complex a, Complex b);

// Subtracts b from a, returns the result.
Complex ComplexSubtract(Complex a, Complex b);

// Multplies a times b, returns the result.
Complex ComplexMultiply(Complex a, Complex b);

// Divides a by b, returns the result.  On some
// architectures and compilers, this function
// might cause a divide-by-zero exception to be thrown
// to the OS for some values of b; on other architectures,
// this might cause the fields of the returned complex
// to be set to floating point NAN.
Complex ComplexDivide(Complex a, Complex b);

#endif  // _COMPLEX_H_