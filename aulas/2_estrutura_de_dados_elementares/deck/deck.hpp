#ifndef _DECK_HEADER
#define _DECK_HEADER

#include <iostream>
#include <cstddef>
#include <cassert>

template<class T>
class deck
{
public:
    struct deckitem
    {
        T data;
        deckitem *next, *prev;

        deckitem() {};
        deckitem(T d): data(d) {};
    };

    deck();
    ~deck();

    void addBegin(T data);
    void addEnd(T data);
    void addAt(std::size_t pos, T data);

    deckitem* begin();
    deckitem* end();
private:
    deckitem head;
    std::size_t decksize;
};

template<class T>
deck<T>::deck()
{
    head.next = nullptr;
    head.prev = head.next;
}

template<class T>
deck<T>::~deck()
{
}

template<class T> typename deck<T>::deckitem*
deck<T>::begin()
{
    return head.next;
}

template<class T> typename deck<T>::deckitem*
deck<T>::end()
{
    return head.prev;
}

template<class T>
void deck<T>::addBegin(T data)
{
    decksize++;
    deckitem *newDeckItem = new deckitem(data);
    
    if (head.next == nullptr)
    {
        head.next = newDeckItem;
        head.prev = newDeckItem;
    }
    else
    {
        newDeckItem->next = head.next;
        newDeckItem->next->prev = newDeckItem;

        head.next = newDeckItem;
    }
}

template<class T>
void deck<T>::addEnd(T data)
{
    decksize++;
    deckitem *newDeckItem = new deckitem(data);

    if (head.next == nullptr)
    {
        head.next = newDeckItem;
        head.prev = newDeckItem;
    }
    else
    {
        newDeckItem->prev = head.prev;
        newDeckItem->prev->next = newDeckItem;

        head.prev = newDeckItem;
    }   
}

template<class T>
void deck<T>::addAt(std::size_t pos, T data)
{
    if (pos == 0)
        addBegin(data);
    else if (pos == decksize)
        addEnd(data);
    else
    {
        assert(pos < decksize);
        deckitem *item = head.next;
        deckitem *newDeckItem = new deckitem(data);

        for(std::size_t i = 1; i < pos; ++i)
            item = item->next;
        
        newDeckItem->prev = item;
        newDeckItem->next = item->next;
        newDeckItem->next->prev = newDeckItem;

        item->next = newDeckItem;
    }
}

#endif
