#ifndef _MTREE_HEADER
#define _MTREE_HEADER

// Vector selecionado por conta do O(1) na seleção
#include <vector>
#include <cstddef>

template<class T>
class MTree
{
public:
    MTree(MTree* parent = nullptr);
    MTree(T data, MTree* parent = nullptr);

    const MTree* getParent();
    void push_back(T data);
    void insert(std::size_t tid, T data);

    const std::vector<MTree*> descendants();
private:
    int p_tid;
    T p_data;

    MTree *p_parent;
    std::vector<MTree*> p_descendants;
};

template<class T>
MTree<T>::MTree(MTree* parent): p_parent(parent) {}

template<class T>
MTree<T>::MTree(T data, MTree* parent): p_data(data), p_parent(parent) {}

template<class T>
void MTree<T>::push_back(T data)
{
    p_descendants.push_back(new MTree<T>(data, this));
}

template<class T>
void MTree<T>::insert(std::size_t tid, T data)
{
    MTree* tmp = new MTree(data);

    // adicionar possibilidade de não sobrescrever a posição.
}

#endif
