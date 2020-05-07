#include <iostream>
#include "mtree.hpp"

int main()
{
    MTree<int> mt;

    mt.push_back(2);
    mt.push_back(3);
    mt.push_back(6);

    mt.insert(0, 23);
    mt.insert(1, 44);

    MTree<int>* mt2 = mt.getChildren(0);
    mt2->push_back(23);
    MTree<int>* mt3 = mt2->getChildren(0);
    mt3->push_back(55);

    MTree<int>* mt4 = mt.getChildren(2);
    mt4->push_back(7);
    mt4->getChildren(0)->push_back(9);
    mt4->getChildren(0)->push_back(8);

    std::cout << mt2->countChildren() << std::endl;
    std::cout << mt2->getChildren(0)->data() << std::endl;
    // std::cout << mt2->getChildren(1)->data() << std::endl; // Para testar o exception
    // std::cout << mt2->getChildren(2)->data() << std::endl; // Para testar o exception

    std::cout << mt3->countDescendant() << std::endl;
    std::cout << mt3->countChildren() << std::endl;
    std::cout << mt.countChildren() << std::endl;    
    std::cout << mt.countDescendant() << std::endl;

    return 0;
}
