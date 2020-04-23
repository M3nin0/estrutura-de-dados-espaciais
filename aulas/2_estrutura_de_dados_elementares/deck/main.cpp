#include "deck.hpp"

#include <iostream>

template<class T>
void printDeck(deck<T>& d)
{
    typename deck<T>::deckitem *init = d.begin();

    while (init != nullptr)
    {
        std::cout << init->data << " ";
        init = init->next;
    }
    std::cout << std::endl;
}

int main()
{
    deck<int> d;
    d.addBegin(2);
    d.addBegin(5);
    d.addEnd(7);

    d.addAt(2, 99);

    printDeck(d);


    return 0;
}
