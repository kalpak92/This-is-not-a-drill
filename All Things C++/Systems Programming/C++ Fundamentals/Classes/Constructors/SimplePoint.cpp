#include <iostream>
#include <cmath>
#include <cstdlib>

#include "SimplePoint.h"

double SimplePoint::Distance(const SimplePoint &p) const {
    double distance = (x_ - p.x_) * (x_ - p.x_);
    distance += (y_ - p.y_) * (y_ - p.y_);
    return sqrt(distance);
}

void SimplePoint::SetLocation(const int x, const int y) {
    x_ = x;
    y_ = y;
}

void PrintSimplePoint(const SimplePoint& pt) {
    std::cout << "SimplePoint: (" << pt.get_x() << ", " << pt.get_y() << ")" << std::endl;
}

int main(int argc, char **argv) {
    SimplePoint x;     // invokes synthesized default constructor.
    PrintSimplePoint(x);

    SimplePoint y(x);  // invokes synthesized copy constructor.
    PrintSimplePoint(y);
    
    y = x;             // invokes synthesized assignment operator.
    PrintSimplePoint(y);
    return EXIT_SUCCESS;
}