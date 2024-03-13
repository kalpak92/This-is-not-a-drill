#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <signal.h>
#include <math.h>

#include "complex.h"

// We use the following global variable to check whether
// a divide-by-zero exception is expected or not.  We'll
// start out not expecting it, and we'll set this to 1 when
// we test a complex division that should trigger a divide by
// zero exception.
static int expect_divzero = 0;

// This is a "signal handler"; in main(), we register this function
// with the operating system using the "sigaction()" system call.
// Do a "man sigaction" to learn about it.
static void handle_divzero(int sig, siginfo_t *si, void *data) {
    assert(expect_divzero == 1);
    exit(0);  // terminate the process; same as "return 0;" from main
}


// Because floating points are an approximate rather than exact
// representation, you can't directly compare two C doubles and
// expect it to work.  Instead, you need to compare for equality
// within some threshold.  This helper function DoubleEqualsEpsilon
// and EPSILON #define do this.
#define EPSILON ((double) 0.000000000001)
static int DoubleEqualsEpsilon(double a, double b) {
    if (a > b) {
        // a > b case
        if ((a - b) < EPSILON)
            return 1;

        return 0;
    }

    // b <= a case
    if ((b - a) < EPSILON)
    return 1;
    return 0;
}

int main(int argc, char **argv) {
    Complex a = {1, 2}, b = {3, 4}, c = {0, 0};
    Complex res;
    struct sigaction act, oldact;

    // register our SIGFPE floating point handler
    act.sa_flags = SA_RESTART | SA_SIGINFO | SA_ONSTACK;
    act.sa_sigaction = &handle_divzero;
    assert(sigaction(SIGFPE, &act, &oldact) == 0);

    res = ComplexAdd(a, b);
    assert(DoubleEqualsEpsilon(res.real, 4.0) == 1);
    assert(DoubleEqualsEpsilon(res.imaginary, 6.0) == 1);

    res = ComplexSubtract(a, b);
    assert(DoubleEqualsEpsilon(res.real, -2.0) == 1);
    assert(DoubleEqualsEpsilon(res.imaginary, -2.0) == 1);

    res = ComplexMultiply(a, b);
    assert(DoubleEqualsEpsilon(res.real, -5) == 1);
    assert(DoubleEqualsEpsilon(res.imaginary, 2.0) == 1);

    res = ComplexDivide(a, b);
    assert(DoubleEqualsEpsilon(res.real, 0.44) == 1);
    assert(DoubleEqualsEpsilon(res.imaginary, 0.08) == 1);

    // Test the "divide by zero" case.  On modern Intel
    // machines and Linux, this causes the returned
    // Complex to contain the value "NAN" in both the
    // real and imaginary components.  The <math.h>
    // function "isnan()" is how we compare to NAN.
    // But, to be super paranoid, we've also set up
    // a signal handler to catch a SIGFPE floating point
    // exception (which integer divide by zero throws).
    expect_divzero = 1;
    res = ComplexDivide(a, c);
    assert(isnan(res.real));
    assert(isnan(res.imaginary));

    return EXIT_SUCCESS;
}