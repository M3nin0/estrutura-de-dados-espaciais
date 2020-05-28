#include <iostream>
#include "kdtree.hpp"

int main()
{
    KDTree kdtree;

    Coordinate c1{120.0, 45}; 
    Coordinate c2{40, 88};
    Coordinate c3{-15.0, 13};
    Coordinate c4{-15.0, 99};

    kdtree.insert(c1);
    kdtree.insert(c2);
    kdtree.insert(c3);
    kdtree.insert(c4);

    // Verificando se a coordenada está na árvore
    std::cout << kdtree.contains(c2) << std::endl;
    std::cout << kdtree.contains(Coordinate{121.0, 88}) << std::endl;

    // Recuperando pontos com range (Sem resultado)
    Coordinate ll{25, 0};
    Coordinate ur{125, 30};
    Rectangle r{ll, ur};
    std::vector<Coordinate> res1 = kdtree.search(r);

    // Recuperando pontos com range (Com resultado)
    Coordinate ll2{25, 30};
    Coordinate ur2{125, 90};
    Rectangle r2{ll2, ur2};
    std::vector<Coordinate> res2 = kdtree.search(r2);

    return 0;
}
