#ifndef _LIST_HEADER
#define _LIST_HEADER

#include <cassert>

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

    void pop_front();
    void pop_back();

    void splice(list<T>& l2);
    void merge(list<T>& l2);
    void reverse();

    item *front() const;
    item *back() const;
private:
    item sentinel_;

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
    sentinel_.next = &sentinel_;
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

template<class T>
void list<T>::pop_front()
{
    erase(begin());
}

template<class T>
void list<T>::pop_back()
{
    erase(end()->prev);
}

template<class T> typename list<T>::item*
list<T>::front() const
{
    return begin();
}

template<class T> typename list<T>::item*
list<T>::back() const
{
    return end()->prev;
}
 
// https://en.cppreference.com/w/cpp/container/list/splice
template <class T>
void list<T>::splice(list<T>& l2)
{
    // poderia ser melhorada com manipulação de ponteiros
    // neste caso, não haveria a remoção dos elementos.
    item *i = l2.begin();
    while(i != l2.end())
    {
        push_back(i->data);
        i = l2.next(i); 
    };
    l2.clear(); // stl based
}

// http://www.cplusplus.com/reference/list/list/reverse/
template<class T>
void list<T>::reverse()
{
    item *ptr = begin();
    item *tmp = nullptr;

    while (ptr != end())
    {
        tmp = next(ptr);        
        ptr->next = previous(ptr);
        ptr->prev = tmp;
        ptr = ptr->prev;
    }
    sentinel_.next = tmp->prev;
}

template<class T>
struct TreeNode
{
    T data;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode() {};
    TreeNode(T d): data(d) {};
};

template<class T>
TreeNode<T>* insert(TreeNode<T>* root, TreeNode<T>* nnode)
{
    if(root == nullptr)
        return nnode;

    if(nnode->data < root->data)
        root->left = insert(root->left, nnode);
    else
        root->right = insert(root->right, nnode);
    return root;
}

template<class T>
void inonderList(TreeNode<T>* root, list<T>& l)
{
    if (root->left != nullptr)
        inonderList(root->left, l);
    l.push_back(root->data);
    if(root->right != nullptr)
        inonderList(root->right, l);
}

template<class T>
void sortTree(list<T>& l)
{
    TreeNode<T> *root = nullptr;
    typename list<T>::item *i = l.begin();

    // insert elements
    while (i != l.end())
    {
        root = insert(root, new TreeNode<T>(i->data));
        i = l.next(i);
    }
    l.clear();
    inonderList(root, l);
}

template<class T>
void list<T>::merge(list<T>& l2)
{
    splice(l2);
    sortTree(*this); // utilizando árvore para o sort (Apenas para testar)
}

#endif
