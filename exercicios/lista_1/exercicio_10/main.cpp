#include "kdtree.hpp"

#include <iostream>

int main()
{
    KDTree kd;

    std::cout << "Inserindo ponto (5, 5)" << std::endl;
    kd.insert(Point(5, 5));
    std::cout << kd.root << std::endl;
    std::cout << kd.root->p_left << std::endl;
    std::cout << kd.root->p_right << std::endl;
    

    std::cout << "Inserindo ponto (2, 6)" << std::endl;
    kd.insert(Point(2, 6));
    std::cout << kd.root << std::endl;
    std::cout << kd.root->p_left << std::endl;
    std::cout << kd.root->p_right << std::endl;

    std::cout << "Inserindo ponto (3, 7)" << std::endl;
    kd.insert(Point(3, 7));
    std::cout << kd.root->p_left << std::endl;
    std::cout << kd.root->p_left->p_left << std::endl;
    std::cout << kd.root->p_left->p_right << std::endl;

    std::cout << "Inserindo ponto (3, 4)" << std::endl;
    kd.insert(Point(3, 4));
    std::cout << kd.root->p_left << std::endl;
    std::cout << kd.root->p_left->p_left << std::endl;
    std::cout << kd.root->p_left->p_right << std::endl;

    return 0;
}
