#include <iostream>
#include "ThreeDBox.h"

using namespace std;

// Copy constructor.
ThreeDBox::ThreeDBox(const ThreeDBox &bx) {
    a_ = bx.a_;
    b_ = bx.b_;
}

// Volume.
double ThreeDBox::Volume() const {
    double vol = 0.0;

    vol = b_.get_x() - a_.get_x();
    vol *= (b_.get_y() - a_.get_y());
    vol *= (b_.get_z() - a_.get_z());
    
    return vol;
}

// Test inside.
bool ThreeDBox::IsInside(const ThreeDBox &bx) const {
    if ((bx.a_.get_x() > a_.get_x()) ||
        (bx.b_.get_x() < b_.get_x()))
    return false;

    if ((bx.a_.get_y() > a_.get_y()) ||
        (bx.b_.get_y() < b_.get_y()))
    return false;
    
    if ((bx.a_.get_z() > a_.get_z()) ||
        (bx.b_.get_z() < b_.get_z()))
    return false;

    return true;
}

// Assignment operator.
ThreeDBox &ThreeDBox::operator=(const ThreeDBox &pt) {
    if (this != &pt) {
        a_ = pt.a_;
        b_ = pt.b_;
    }
    return *this;
}

// Override "<<" for std::ostream.
ostream &operator<<(ostream &out, const ThreeDBox &pt) {
    out << "[ " << pt.a_ << " -- " << pt.b_ << " ]";
    return out;
}