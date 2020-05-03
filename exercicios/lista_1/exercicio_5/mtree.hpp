#ifndef _MTREE_HEADER
#define _MTREE_HEADER

// Vector selecionado por conta do O(1) na seleção
#include <vector>
#include <cstddef>
#include <stdexcept>

template<class T>
class MTree
{
public:
    MTree(MTree* parent = nullptr);
    MTree(T data, MTree* parent = nullptr);

    void push_back(T data);
    MTree* getParent() const;
    void insert(std::size_t tid, T data);

    std::size_t countChildren() const;
    std::size_t countDescendant() const;
    MTree* getChildren(std::size_t tid) const;

    T data() const;
private:
    int p_tid;
    T p_data;

    MTree *p_parent;
    std::vector<MTree*> p_children;
};

template<class T>
MTree<T>::MTree(MTree* parent): p_parent(parent) {}

template<class T>
MTree<T>::MTree(T data, MTree* parent): p_data(data), p_parent(parent) {}

template<class T>
void MTree<T>::push_back(T data)
{
    p_children.push_back(new MTree<T>(data, this));
}

template<class T>
void MTree<T>::insert(std::size_t tid, T data)
{
    if (tid >= countChildren())
        throw std::runtime_error("Índice inválido!");

    p_children[tid]->push_back(data);
}

template<class T>
std::size_t MTree<T>::countChildren() const
{
    return p_children.size();
}

template<class T> 
MTree<T>* MTree<T>::getParent() const
{
    return p_parent;
}

template<class T>
MTree<T>* MTree<T>::getChildren(std::size_t tid) const
{
    if (tid >= countChildren())
        throw std::runtime_error("Índice inválido");
    return p_children[tid];
}

template<class T>
std::size_t countDescendantRecursive(const MTree<T>* root)
{
    std::size_t res = 0;
    std::size_t childrenSize = root->countChildren();
    if (childrenSize == 0)
        return 1;

    for(std::size_t i = 0; i < childrenSize; ++i)
    {
        res += countDescendantRecursive(root->getChildren(i));
    }

    // A soma é feita para considerar a raiz atual no cálculo dos descendentes
    return res + 1;
}

template<class T>
std::size_t MTree<T>::countDescendant() const
{
    // A subtração é feita já que, na recursão a raiz principal 
    // é considerada, então, esta subtração remove esta consideração
    return countDescendantRecursive(this) - 1;
}

template<class T>
T MTree<T>::data() const
{
    return p_data;
}

#endif
