#include <iostream>
#include "tree.hpp"

int main()
{
    BinaryTree<int> bt(23);
    
    bt.insert(2);
    bt.insert(6);
    bt.insert(99);

    std::cout << bt.search(6)->data() << std::endl;

    return 0;
}
