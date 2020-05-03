#include "kdtree.hpp"

#include <iostream>

int main()
{
    KDTree kd;

    kd.insert(Point(5, 5));
    kd.insert(Point(3, 5));
    kd.insert(Point(2, 7));

    std::cout << "Buscando elementos 2" << std::endl;
    Point p2 = kd.find(Point(2, 7));
    std::cout << "Point(" << p2.x() << ", " << p2.y() << ")" << std::endl;

    // std::cout << "Inserindo ponto (5, 5)" << std::endl;
    // kd.insert(Point(5, 5));
    // // std::cout << kd.root << std::endl;
    // // std::cout << kd.root->p_left << std::endl;
    // // std::cout << kd.root->p_right << std::endl;
    
    // std::cout << "Inserindo ponto (2, 6)" << std::endl;
    // kd.insert(Point(2, 6));
    // // std::cout << kd.root << std::endl;
    // // std::cout << kd.root->p_left << std::endl;
    // // std::cout << kd.root->p_right << std::endl;

    // std::cout << "Inserindo ponto (3, 7)" << std::endl;
    // kd.insert(Point(3, 7));
    // // std::cout << kd.root->p_left << std::endl;
    // // std::cout << kd.root->p_left->p_left << std::endl;
    // // std::cout << kd.root->p_left->p_right << std::endl;
    
    // std::cout << "Inserindo ponto (2, 9)" << std::endl;
    // kd.insert(Point(2, 9));
    
    // std::cout << "Inserindo ponto (3, 9)" << std::endl;
    // kd.insert(Point(3, 9));

    // std::cout << "Inserindo ponto (3, 4)" << std::endl;
    // kd.insert(Point(3, 4));
    // // std::cout << kd.root->p_left << std::endl;
    // // std::cout << kd.root->p_left->p_left << std::endl;
    // // std::cout << kd.root->p_left->p_right << std::endl;

    // std::cout << "Buscando elementos" << std::endl;
    // Point p = kd.find(Point(3, 7));

    // std::cout << "Point(" << p.x() << ", " << p.y() << ")" << std::endl;
    
    // std::cout << "Buscando elementos 2" << std::endl;
    // Point p2 = kd.find(Point(5, 5));
    // std::cout << "Point(" << p2.x() << ", " << p2.y() << ")" << std::endl;
    
    // std::cout << "Buscando elementos 3" << std::endl;
    // Point p3 = kd.find(Point(2, 6));
    // std::cout << "Point(" << p3.x() << ", " << p3.y() << ")" << std::endl;
    
    // std::cout << "Buscando elementos 4" << std::endl;
    // Point p4 = kd.find(Point(3, 9));
    // std::cout << "Point(" << p4.x() << ", " << p4.y() << ")" << std::endl;

    // std::cout << "Buscando elemento que não está na árvore" << std::endl;
    // Point p2 = kd.find(Point(9, 9));
    // std::cout << p2.x << std::endl;

    return 0;
}
