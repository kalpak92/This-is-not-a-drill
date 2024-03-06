#ifndef _THREEDBOX_H_
#define _THREEDBOX_H_

#include <iostream>
#include "../3d Point/ThreeDPoint.h"

using namespace std;

// A "ThreeDBox" is a class representing a three-dimensional box
// aligned with the axis with right angles.  
// Internally, we represent a ThreeDBox with two ThreeDPoint objects: a and b,
// where a.x_ <= b.x_, a.y_ <= b.y_, a.z_ <= b.z_.

class ThreeDBox {
    public:
        // Constructors; use initialization lists to initialize.
        ThreeDBox() : a_(), b_() {}
        ThreeDBox(const ThreeDPoint &a, const ThreeDPoint &b)
        : a_(a), b_(b) { }

        // Copy constructor.
        ThreeDBox(const ThreeDBox &bx);

        // Accessors (inlined).
        ThreeDPoint get_a() const { return a_; }
        ThreeDPoint get_b() const { return b_; }

        // Volume.
        double Volume() const;

        // Tests if self is inside bx.
        bool IsInside(const ThreeDBox &bx) const;

        // Assignment operator.
        ThreeDBox &operator=(const ThreeDBox &pt);

        // Override "<<" for std::ostream.
        friend ostream &operator<<(ostream &out, const ThreeDBox &pt);

    private:
        ThreeDPoint a_, b_;
};

#endif  // _THREEDBOX_H_