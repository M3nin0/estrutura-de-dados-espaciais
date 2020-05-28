#include <iostream>
#include "kdtree.hpp"

int main()
{
    KDTree kdtree;

    Coordinate c1{120.0, 45}; 
    Coordinate c2{40, 88};
    Coordinate c3{-15.0, 13};

    kdtree.insert(c1);
    kdtree.insert(c2);
    kdtree.insert(c3);

    std::cout << kdtree.contains(c2) << std::endl;
    std::cout << kdtree.contains(Coordinate{121.0, 88}) << std::endl;

    return 0;
}
