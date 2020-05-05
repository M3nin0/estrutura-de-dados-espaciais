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

struct complex
{
    int a;
    int b;
};

int main()
{
    list<int> l;
    list<int> l2;

    l.push_front(1); l.push_front(2);
    l2.push_front(3); l2.push_front(4);l2.push_front(99);

    l.merge(l2);
    print<int>(l);

    l.pop_front();
    l.pop_back();
    print<int>(l);

    l.push_front(1);
    print<int>(l);

    std::cout << "Conteúdo inicial e final: " << l.front()->data << " " << l.back()->data << std::endl;

    std::cout << l.find(1)->data << std::endl;

    list<complex> l3;
    l3.insert(l3.begin(), complex());
    // l3.find(complex()); // erro

    return 0;
}