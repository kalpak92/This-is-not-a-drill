#ifndef _THREEDPOINT_H_
#define _THREEDPOINT_H_

#include <iostream>

using namespace std;

// A "ThreeDPoint" is a class representing a three-dimensional point.
// Internally, a ThreeDPoint is represented with doubles for the x, y,
// and z axis values.
class ThreeDPoint {
    public:

        // Constructors; we use initialization lists to initialize.
        ThreeDPoint() : x_(0), y_(0), z_(0) { }
        ThreeDPoint(const double x, const double y, const double z)
          : x_(x), y_(y), z_(z) { }

        // Copy constructor.
        ThreeDPoint(const ThreeDPoint &pt);

        // Accessors (inlined).
        double get_x() const { return x_; }
        double get_y() const { return y_; }
        double get_z() const { return z_; }

        // Inner product.
        double InnerProduct(const ThreeDPoint &pt) const;

        // Add, subtract operators.
        ThreeDPoint operator+(const ThreeDPoint &pt) const;
        ThreeDPoint operator-(const ThreeDPoint &pt) const;

        // Add/subtract and assign operators.
        ThreeDPoint &operator+=(const ThreeDPoint &pt);
        ThreeDPoint &operator-=(const ThreeDPoint &pt);

        // Assignment operator.
        ThreeDPoint &operator=(const ThreeDPoint &pt);

        // Override "<<" for std::ostream.
        friend ostream &operator<<(ostream &out, const ThreeDPoint &pt);

    private:
    double x_, y_, z_;
};

#endif  // _THREEDPOINT_H_