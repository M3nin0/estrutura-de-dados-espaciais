#ifndef _LIST_HEADER
#define _LIST_HEADER

#include <cassert>
#include <iostream>

template <class T>
class list
{
public:
    struct item
    {
        item *prev;
        item *next;
        T data;

        item() {};
        item(item *p, item *n, T d);
    };

    list();
    ~list();

    item* begin() const;
    item* end() const;

    item* insert(item *pos, T data);
    item* find(T data) const;

    T retrieve(item *pos);
    void erase(item *pos);

    item* next(item *pos) const;
    item* previous(item *post) const;

    void clear();
    bool empty() const;

    void push_front(T data);
    void push_back(T data);

    item* pop_front();
    item* pop_back();

    void splice(list<T>& l2);
    void merge(list<T>& l2);
    void reverse();

private:
    item sentinel_;

    // evitando cópias
    list(list&);
    list& operator=(list&);
};

template<class T>
list<T>::item::item(item *p, item *n, T d): 
                prev(p), next(n), data(d) 
{
}

template<class T>
list<T>::list()
{
    sentinel_.prev = &sentinel_;
    sentinel_.next = sentinel_.prev;
}

template<class T>
list<T>::~list()
{
    clear();
}

template<class T> typename list<T>::item* 
list<T>::find(T data) const
{
    item *i = sentinel_.next;

    while ((i != end()) && (i->data != data))
        i = i->next;
    return i;
}

template<class T>
T list<T>::retrieve(list<T>::item *pos)
{
    assert(pos);
    return pos->data;
}

template<class T> typename list<T>::item* 
list<T>::insert(list<T>::item *pos, T data)
{
    assert(pos);

    item *newItem = new item(pos->prev, pos, data);

    pos->prev->next = newItem;
    pos->prev = newItem;
    
    return newItem;
}

template<class T>
void list<T>::erase(list<T>::item *pos)
{
    assert(pos && (pos != end()));

    pos->prev->next = pos->next;
    pos->next->prev = pos->prev;

    delete pos;
}

template<class T>
void list<T>::clear()
{
    item *f = begin();
    item *l = end();

    while (f != l)
    {
        item *tmp = f;
        f = f->next;
        delete tmp;
    }
    sentinel_.prev = end();
    sentinel_.next = end();
}

template<class T>
inline bool list<T>::empty() const
{
    return (sentinel_.next == end());
}

template<class T> typename list<T>::item* 
list<T>::next(item *pos) const
{
    assert(pos);
    return pos->next;
}

template<class T> typename list<T>::item*
list<T>::previous(item *pos) const
{
    assert(pos);
    return pos->prev;
}

template<class T> typename list<T>::item* 
list<T>::begin() const
{
    return sentinel_.next;
}

template<class T> typename list<T>::item* 
list<T>::end() const
{
    // rev const_cast
    return const_cast<item*>(&sentinel_);
}

template<class T>
void list<T>::push_front(T data)
{
    insert(begin(), data);
}

template<class T>
void list<T>::push_back(T data)
{
    insert(end(), data);
}

template<class T> typename list<T>::item*
list<T>::pop_front()
{
    item* tmp = sentinel_.prev;
    erase(tmp);

    return tmp;
}

template<class T> typename list<T>::item*
list<T>::pop_back()
{
    item* tmp = sentinel_.prev;
    erase(tmp);

    return tmp;
}

// http://www.cplusplus.com/reference/list/list/splice/
template <class T>
void list<T>::splice(list<T>& l2)
{
    item *i = l2.begin();

    while(i != l2.end())
    {
        push_back(i->data);
        i = l2.next(i); 
    };

    // Melhor forma (Com manipulação de ponteiros)
    // Vou escrever sobre as duas formas...
    // item* tmp = l2.begin();
    // item* pos = end();

    // Alterando o final da primeira lista
    // tmp->prev = pos->prev;
    // pos->prev->next = tmp;
    // pos->prev = tmp;

    // l2.end()->next = pos;
    // end()->next = l2.end();
}

// http://www.cplusplus.com/reference/list/list/reverse/
template<class T>
void list<T>::reverse()
{
    item* tmp = sentinel_.prev;
    sentinel_.prev = sentinel_.next;
    sentinel_.next = tmp;
}

/**
 * 
 *  void splice(list<T> l2);
    void merge(list<T> l2);
    void reverse();
**/


#endif
