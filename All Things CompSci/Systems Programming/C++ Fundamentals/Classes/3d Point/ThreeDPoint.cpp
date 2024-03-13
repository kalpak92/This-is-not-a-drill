#include "ThreeDPoint.h"

using namespace std;

// Copy constructor.
ThreeDPoint::ThreeDPoint(const ThreeDPoint &pt) {
    x_ = pt.x_;
    y_ = pt.y_;
    z_ = pt.z_;
}

// Inner product.
double ThreeDPoint::InnerProduct(const ThreeDPoint &pt) const {
    double retval = 0.0;

    retval += (x_ * pt.x_);
    retval += (y_ * pt.y_);
    retval += (z_ * pt.z_);
    return retval;
}

// Arithmetic operators.
ThreeDPoint ThreeDPoint::operator+(const ThreeDPoint &pt) const {
    ThreeDPoint retval(*this);  // Uses our copy constructor!
    retval.x_ += pt.x_;
    retval.y_ += pt.y_;
    retval.z_ += pt.z_;

    return retval;
}

ThreeDPoint ThreeDPoint::operator-(const ThreeDPoint &pt) const {
    ThreeDPoint retval(*this);  // Uses our copy constructor!
    retval.x_ -= pt.x_;
    retval.y_ -= pt.y_;
    retval.z_ -= pt.z_;
    
    return retval;
}

// Arithmetic + assign operators.
ThreeDPoint &ThreeDPoint::operator+=(const ThreeDPoint &pt) {
    x_ += pt.x_;
    y_ += pt.y_;
    z_ += pt.z_;
    
    return *this;
}

ThreeDPoint &ThreeDPoint::operator-=(const ThreeDPoint &pt) {
    x_ -= pt.x_;
    y_ -= pt.y_;
    z_ -= pt.z_;
    return *this;
}

// Assignment operator.
ThreeDPoint &ThreeDPoint::operator=(const ThreeDPoint &pt) {
    if (this != &pt) {
        x_ = pt.x_;
        y_ = pt.y_;
        z_ = pt.z_;
    }
    return *this;
}

// Override "<<" for std::ostream.  Note that this is not
// a member function of ThreeDPoint, but a global non-member function.
// The "friend" is there so we can directly access pt's x_, y_, z_
// privates.
ostream &operator<<(ostream &out, const ThreeDPoint &pt) {
    out << "(" << pt.x_ << "," << pt.y_ << "," << pt.z_ << ")";
    return out;
}