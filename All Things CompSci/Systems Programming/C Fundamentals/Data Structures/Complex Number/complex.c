#include "complex.h"

Complex ComplexAdd(Complex a, Complex b) {
    Complex res;

    res.real = a.real + b.real;
    res.imaginary = a.imaginary + b.imaginary;
    return res;
}

Complex ComplexSubtract(Complex a, Complex b) {
    Complex res;

    res.real = a.real - b.real;
    res.imaginary = a.imaginary - b.imaginary;
    return res;
}

Complex ComplexMultiply(Complex a, Complex b) {
    Complex res;

    res.real = (a.real * b.real) - (a.imaginary * b.imaginary);
    res.imaginary = (a.imaginary * b.real) - (a.real * b.imaginary);
    return res;
}

Complex ComplexDivide(Complex a, Complex b) {
    // This is the hard one.  See Wikipedia for the formula. ;)
    Complex res;

    res.real =
    ((a.real * b.real) + (a.imaginary * b.imaginary)) /
    ((b.real * b.real) + (b.imaginary * b.imaginary));

    res.imaginary =
    ((a.imaginary * b.real) - (a.real * b.imaginary)) /
    ((b.real * b.real) + (b.imaginary * b.imaginary));

    return res;
}