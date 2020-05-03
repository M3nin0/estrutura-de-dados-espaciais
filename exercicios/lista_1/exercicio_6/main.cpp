#include <iostream>
#include "tree.hpp"

int main()
{
    BinaryTree<int> bt(5);

    bt.insert(3);
    bt.insert(7);
    bt.insert(6);
    bt.insert(9);

    std::cout << bt.search(7) << std::endl;
    std::cout << bt.search(9) << std::endl;
    bt.remove(7);
    std::cout << bt.search(7) << std::endl;
    std::cout << bt.search(9) << std::endl;
    return 0;
}
