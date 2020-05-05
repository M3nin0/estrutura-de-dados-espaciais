#include <iostream>
#include "tree.hpp"

int Print(int t)
{
    std::cout << t << std::endl;

    return t * 2;
}

int main()
{
    BinaryTree<int> bt(5);
    
    // bt.insert
    bt.insert(3);
    bt.insert(7);
    bt.insert(6);
    bt.insert(9);

    bt.posOrder(Print);
    std::cout << "==== Versão após aplicação do functor" << std::endl;
    bt.posOrder(Print);

    return 0;
}
