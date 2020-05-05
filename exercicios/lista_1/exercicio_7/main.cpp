#include <iostream>
#include "tree.hpp"

int Print(int t)
{
    std::cout << t << std::endl;

    return t;
}

int main()
{
    BinaryTree<int> bt(5);
    
    // bt.insert
    bt.insert(3);
    bt.insert(7);
    bt.insert(6);
    bt.insert(9);

    // bt.insert(3);
    // bt.insert(10);
    // bt.insert(11);
    // bt.insert(8);
    // bt.insert(9);
    // bt.insert(7);

    // BinaryTree<int> bt(15);
    // bt.insert(13);
    // bt.insert(14);
    // bt.insert(10);
    // bt.insert(12);
    // bt.insert(6);
    // bt.insert(7); 
    // bt.insert(5);
    // bt.insert(30);
    // bt.insert(25);
    // bt.insert(35);

    // bt.insert(6);
    // bt.insert(9);

    // bt.remove(7);
    // std::cout << bt.search(6) << std::endl;

    bt.remove(7);
    // bt.remove(9);
    bt.posOrder(Print);
    // std::cout << "==== Versão após aplicação do functor" << std::endl;
    // bt.posOrder(Print);

    return 0;
}
