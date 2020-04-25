#ifndef _TREE_HEADER
#define _TREE_HEADER

template<class T>
class BinaryTree
{
public:
    BinaryTree(T key);
    
    T data();

    void remove(T key);
    void insert(T key);
    BinaryTree* search(T key);
private:
    T p_data;
    BinaryTree *p_root = nullptr;
    BinaryTree *p_left = nullptr, *p_right = nullptr;

    void remove_(BinaryTree* root);
    BinaryTree* search_(BinaryTree* root, T key);
    BinaryTree* insert_(BinaryTree* root, BinaryTree * nbstree);
};

template<class T>
BinaryTree<T>::BinaryTree(T key): p_data(key) { }

template<class T>
T BinaryTree<T>::data()
{
    return p_data;
}

template<class T>
BinaryTree<T>* BinaryTree<T>::insert_(BinaryTree *root, BinaryTree * nbstree)
{
    if (root == nullptr)
        return nbstree;

    if (nbstree->data() < root->data())
        root->p_left = insert_(root->p_left, nbstree);
    else
        root->p_right = insert_(root->p_right, nbstree);
    return nbstree;
}

template<class T>
BinaryTree<T>* BinaryTree<T>::search_(BinaryTree* root, T key)
{
    if (root == nullptr)
        return nullptr;
    
    if (root->data() == key)
        return root;

    if (root->data() > key)
        return search_(root->p_left, key);
    else return search_(root->p_right, key);
}

template<class T>
void BinaryTree<T>::insert(T key)
{
    insert_(this, new BinaryTree(key));
}

template<class T>
BinaryTree<T>* BinaryTree<T>::search(T key)
{
    return search_(this, key);
}

#endif
