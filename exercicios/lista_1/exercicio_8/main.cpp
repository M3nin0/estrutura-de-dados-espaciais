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

    bt.posOrder(Print);

    return 0;
}
