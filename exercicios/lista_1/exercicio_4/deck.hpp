#ifndef _DECK_HEADER
#define _DECK_HEADER

#include <iostream>
#include <cstddef>
#include <cassert>
#include <stdexcept>


template<class T>
class deck
{
public:
    deck();
    deck(std::size_t maxsize);
    ~deck();

    void addEnd(T data);
    void addBegin(T data);
    void addAt(std::size_t pos, T data);

    void removeEnd();
    void removeBegin();

    std::size_t end() const;
    std::size_t begin() const;

    std::size_t size() const;

    T at(std::size_t idx);
    T& operator[](std::size_t idx);
private:
    T* index;

    int size_ = 0;
    int p_max_decksize = 10;
    // Nesta parte, durante a segunda implementação, foi percebido que
    // a manipulação dos elementos no modo inverso é mais fácil, principalmente
    // para as operações de inserção e deleção.
    // O mesmo pode ser feito considerando a ordem normal dos vetores, porém, ao que
    // se percebeu, era necessário a adição de mais lógica para tal.
    int p_head = 10, p_tail = 0;

    std::size_t pos(std::size_t p);
};

template<class T>
deck<T>::deck()
{
    index = new T[p_max_decksize];
}

template<class T>
deck<T>::deck(std::size_t maxsize)
{
    index = new T[maxsize];
    p_max_decksize = maxsize;

    // ajustando os índices
    p_head = maxsize;
}

template<class T>
deck<T>::~deck()
{
    delete[] index;
}

template<class T>
void deck<T>::addBegin(T data)
{
    if((p_head-2) == p_tail || size_ == p_max_decksize)
        throw std::out_of_range("Limite do deque atingido");

    size_++;
    index[(--p_head) % p_max_decksize] = data;
}

template<class T>
void deck<T>::addEnd(T data)
{
    if ((p_tail+2) == p_head || size_ == p_max_decksize)
        throw std::out_of_range("Limite do deque atingido");

    size_++;
    index[(p_tail++) % p_max_decksize] = data;
}

template<class T>
void deck<T>::addAt(std::size_t idx, T data)
{
    std::size_t idxat = pos(idx);
    std::size_t tailpos = (p_tail) % p_max_decksize;

    T tmp2;
    T tmp = index[idxat];
    index[idxat] = data;

    while (idxat != tailpos)
    {
        idxat = pos(idx++);
        tmp2 = index[idxat];
        index[idxat] = tmp;

        tmp = tmp2;
    }
}

template<class T>
T& deck<T>::operator[](std::size_t idx)  
{
    return index[pos(idx)];
}

template<class T>
T deck<T>::at(std::size_t idx)
{
    idx = pos(idx);
    std::size_t tailpos = p_tail % p_max_decksize;
    std::size_t headerpos = p_head % p_max_decksize;

    // Verifica se a posição a ser verificada está em uma posição
    // que ainda não foi atribuída
    if (idx < headerpos - 1 && idx > tailpos - 1)
        throw std::out_of_range("Índice inválido");
    return index[idx];
}

template<class T>
std::size_t deck<T>::pos(std::size_t idx)
{
    return (idx + p_head) % p_max_decksize;
}

template<class T>
std::size_t deck<T>::end() const
{
    return (p_tail) % p_max_decksize;
}

template<class T>
std::size_t deck<T>::begin() const
{
    return (p_head - 1) % p_max_decksize;
}

template<class T>
std::size_t deck<T>::size() const
{
    return size_;
}

template<class T>
void deck<T>::removeEnd()
{
    if (size_ == 0)
        throw std::out_of_range("O deque está vazio!");

    size_--;
    p_tail--;
}

template<class T>
void deck<T>::removeBegin()
{
    if (size_ == 0)
        throw std::out_of_range("O deque está vazio");

    size_--;
    p_head++;
}

/**
 * A implementação realizada abaixo utiliza a abordagem de listas duplamente
 * encadeadas, porém, com esta, os requisitos de acesso aos elementos em tempo 
 * constante O(1) não estavam sendo respeitados. A implementação acima realiza tal
 * feito, seguindo também, todas as demais exigências da estrutura de dados proposta no
 * exercício 4
 */
// template<class T>
// class deck
// {
// public:
//     struct deckitem
//     {
//         T data;
//         deckitem *next, *prev;

//         deckitem() {};
//         deckitem(T d): data(d) {};
//     };

//     deck();
//     ~deck();

//     void addBegin(T data);
//     void addEnd(T data);
//     void addAt(std::size_t pos, T data);

//     deckitem* begin();
//     deckitem* end();
// private:
//     deckitem head;
//     std::size_t decksize;
// };

// template<class T>
// deck<T>::deck()
// {
//     head.next = nullptr;
//     head.prev = head.next;
// }

// template<class T>
// deck<T>::~deck()
// {
// }

// template<class T> typename deck<T>::deckitem*
// deck<T>::begin()
// {
//     return head.next;
// }

// template<class T> typename deck<T>::deckitem*
// deck<T>::end()
// {
//     return head.prev;
// }

// template<class T>
// void deck<T>::addBegin(T data)
// {
//     decksize++;
//     deckitem *newDeckItem = new deckitem(data);
    
//     if (head.next == nullptr)
//     {
//         head.next = newDeckItem;
//         head.prev = newDeckItem;
//     }
//     else
//     {
//         newDeckItem->next = head.next;
//         newDeckItem->next->prev = newDeckItem;

//         head.next = newDeckItem;
//     }
// }

// template<class T>
// void deck<T>::addEnd(T data)
// {
//     decksize++;
//     deckitem *newDeckItem = new deckitem(data);

//     if (head.next == nullptr)
//     {
//         head.next = newDeckItem;
//         head.prev = newDeckItem;
//     }
//     else
//     {
//         newDeckItem->prev = head.prev;
//         newDeckItem->prev->next = newDeckItem;

//         head.prev = newDeckItem;
//     }   
// }

// template<class T>
// void deck<T>::addAt(std::size_t pos, T data)
// {
//     if (pos == 0)
//         addBegin(data);
//     else if (pos == decksize)
//         addEnd(data);
//     else
//     {
//         assert(pos < decksize);
//         deckitem *item = head.next;
//         deckitem *newDeckItem = new deckitem(data);

//         for(std::size_t i = 1; i < pos; ++i)
//             item = item->next;
        
//         newDeckItem->prev = item;
//         newDeckItem->next = item->next;
//         newDeckItem->next->prev = newDeckItem;

//         item->next = newDeckItem;
//     }
// }

#endif