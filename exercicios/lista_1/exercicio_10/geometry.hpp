#ifndef _GEOMETRY_HEADER
#define _GEOMETRY_HEADER

struct Point
{
public:
    Point();
    Point(double x, double y);

    double x();
    double y();
private:
    double p_x, p_y;
};

Point::Point()
{
    p_x = 0;
    p_y = 0;
}

Point::Point(double x, double y): p_x(x), p_y(y) {}

double Point::x()
{
    return p_x;
}

double Point::y()
{
    return p_y;
}

#endif
