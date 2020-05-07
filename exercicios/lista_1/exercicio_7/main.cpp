#include <iostream>
#include "tree.hpp"

int printAndSquare(int t)
{
    std::cout << t * 4 << std::endl;

    return t * 4;
}

int onlyPrint(int t)
{
    std::cout << t << std::endl;
    return t;
}

int main()
{
    BinaryTree<int> bt(5);
    
    bt.insert(3);
    bt.insert(7);
    bt.insert(6);
    bt.insert(9);

    bt.posOrder(printAndSquare);
    std::cout << "==== Versão após aplicação do functor" << std::endl;
    bt.posOrder(onlyPrint);

    return 0;
}
