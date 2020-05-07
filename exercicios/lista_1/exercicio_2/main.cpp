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
    // Este comando foi adicionado para mostrar que, caso 
    // a estrutura de dados não tenha os operadores de comparação implementados
    // problemas serão apresentados
    // l3.find(complex()); // erro

    std::cout << "Merge" << std::endl;
    l.clear();
    l2.clear();

    l.push_front(1); l.push_front(2);
    l2.push_front(99); l2.push_front(22);l2.push_front(106);

    std::cout << "- Antes do merge" << std::endl;
    print<int>(l);
    print<int>(l2);
    std::cout << "- Depois do merge" << std::endl;
    l.merge(l2);
    print<int>(l);
    print<int>(l2);

    std::cout << "Splice" << std::endl;
    l2.push_back(567); l2.push_back(789);
    l.splice(l2);
    print<int>(l);

    std::cout << "Mostrando a lista com merge e splice invertida" << std::endl;
    l.reverse();
    print<int>(l);

    return 0;
}
