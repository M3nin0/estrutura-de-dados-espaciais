#include "list.hpp"

#include <iostream>

template <class T>
void print(list<T>& l)
{
    typename list<T>::item *i = l.begin();

    while (i != l.end())
    {
        std::cout << i->data << " ";
        i = l.next(i);
    }
    std::cout << std::endl;
}


int main()
{
    list<int> l;

    // l.insert(l.begin(), 2);
    // // l.clear();
    // l.insert(l.begin(), 23);
    l.push_front(55);
    l.push_back(99);
    l.push_front(88);
    l.push_back(109);

    std::cout << l.pop_back() << std::endl;

    // std::cout << l.begin()->data << std::endl;
    // std::cout << l.begin()->next->data << std::endl;

    print<int>(l);

    // std::cout << l.end()->data << std::endl;

    // list<int>::item* i = l.begin();

    // std::cout << i->next << std::endl;
    // std::cout << "Aqui" << std::endl;

    // std::cout << l.begin() << std::endl;


    return 0;
}
