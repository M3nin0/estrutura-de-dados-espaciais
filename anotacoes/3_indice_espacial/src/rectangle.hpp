#ifndef __RECTANGLE_HPP__
#define __RECTANGLE_HPP__

#include "coordinate.hpp"

struct Rectangle
{
    Coordinate ll_;
    Coordinate ur_;

    bool contains(const Coordinate& c) const
    {
        // Aqui, todas as dimensões estão sendo verificadas..
        if (c.x_ < ll_.x_)
            return false;
        if (c.x_ > ur_.x_)
            return false;
        if (c.y_ < ll_.y_)
            return false;
        if (c.y_ > ur_.y_)
            return false;
        return true;
    }
};

#endif
