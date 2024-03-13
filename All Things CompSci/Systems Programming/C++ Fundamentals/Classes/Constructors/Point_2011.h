#ifndef _POINT_2011_H_
#define _POINT_2011_H_

class Point {
    public:
        Point(const int x, const int y);  // constructor

        // disable copy constructor and assignment operator by specifying
        // them as deleted functions (new in C++ 2011)
        Point(const Point &copyme) = delete;
        Point &operator=(const Point &rhs) = delete;

        int get_x() const { return x_; }  // inline member function
        int get_y() const { return y_; }  // inline member function

        void CopyFrom(const Point &copy_from_me);    // update self
        double Distance(const Point &p) const;
        void SetLocation(const int x, const int y);

    private:
        int x_;  // data member
        int y_;  // data member
};  // class Point

#endif  // _POINT_2011_H_