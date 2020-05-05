#include <iostream>
#include "tree.hpp"

int main()
{
    BinaryTree<int> bt(5);
    
    bt.insert(3);
    bt.insert(7);
    bt.insert(6);
    bt.insert(9);
    bt.insert(11);
    bt.insert(15);
    bt.insert(17);
    
    // Valor esperado: 6
    std::cout << bt.height() << std::endl;

    return 0;
}
