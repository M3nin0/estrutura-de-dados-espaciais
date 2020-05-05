#include "deck.hpp"

#include <iostream>

int main()
{
    deck<int> d(20);

    d.addBegin(2);
    d.addBegin(3);
    d.addBegin(4);
    d.addEnd(23);
    d.addEnd(27);
    d.addEnd(29);
    d.addAt(d.end(), 31);

    std::cout << d[0] << std::endl;
    std::cout << d[4] << std::endl;

    return 0;
}
