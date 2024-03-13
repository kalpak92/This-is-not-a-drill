#include <cstdlib>

#include "../3d Point/ThreeDPoint.h"
#include "ThreeDBox.h"

int main(int argc, char **argv) {
    ThreeDPoint a(1,1,1), b(1,1,2), c(2,2,2), d(2,4,6);
    ThreeDBox empty(a, a), flat(a, b), small(a,c), big(a,d);
    ThreeDBox test = empty;

    cout << empty << endl;
    cout << flat << endl;
    cout << small << endl;
    cout << big << endl;

    cout << empty.Volume() << " " << flat.Volume() << " ";
    cout << small.Volume() << " " << big.Volume() << endl;

    cout << test << endl;
    test = big;
    cout << test << endl;

    cout << big.IsInside(small) << " ";
    cout << small.IsInside(big) << " ";
    cout << empty.IsInside(empty) << endl;

    return EXIT_SUCCESS;
}