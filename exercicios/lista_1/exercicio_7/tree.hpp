#ifndef _TREE_HEADER
#define _TREE_HEADER

template<class T>
class BinaryTree
{
public:
    BinaryTree();
    BinaryTree(T key);
    ~BinaryTree();

    T data();

    void remove(T key);
    void insert(T key);
    BinaryTree* search(T key);

    void preOrder(T (*functor)(T key));
    void inOrder(T (*functor)(T key));
    void posOrder(T (*functor)(T key));
private:
    T p_data;
    BinaryTree *p_root = nullptr;
    BinaryTree *p_left = nullptr, *p_right = nullptr;

    BinaryTree* remove_(BinaryTree* root, T key);
    BinaryTree* search_(BinaryTree* root, T key);
    BinaryTree* insert_(BinaryTree* root, BinaryTree * nbstree);

    void preOrder_(BinaryTree* root, T (*functor)(T key));
    void inOrder_(BinaryTree* root, T (*functor)(T key));
    void posOrder_(BinaryTree* root, T (*functor)(T key));

    void delete_(BinaryTree* root);
};

template<class T>
BinaryTree<T>::BinaryTree() {}

template<class T>
BinaryTree<T>::BinaryTree(T key): p_data(key) {}


template<class T>
void BinaryTree<T>::delete_(BinaryTree* root)
{
    if (root->p_left != nullptr)
       delete(root->p_left);

    if (root->p_right != nullptr)
        delete(root->p_right);
    delete root->p_root;
}

template<class T>
BinaryTree<T>::~BinaryTree()
{
    delete_(this);
}

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

    if (root->data() > nbstree->data())
        root->p_left = insert_(root->p_left, nbstree);
    else
        root->p_right = insert_(root->p_right, nbstree);
    return root;
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
BinaryTree<T>* BinaryTree<T>::remove_(BinaryTree* root, T key)
{
    BinaryTree *res = nullptr;

    if (root == nullptr)
        return res;

    if (root->data() > key)
    {
        root->p_left = remove_(root->p_left, key);
        res = root;
    } else if (root->data() < key)
    {
        root->p_right = remove_(root->p_right, key);
        res = root;
    } else
    {
        // Tratamento dos três casos base
        // 1° Caso (O elemento a ser removido é um nó folha)
        if (root->p_left == nullptr && root->p_right == nullptr)
        {
            res = root->p_right;
        }
        // 2° Caso (Nó intermediário com apenas um filho)
        // 2.1 (Lado esquerdo possui filho)
        else if (root->p_left != nullptr && root->p_right == nullptr)
        {
            res = root->p_left;
        }
        // 2.2 (Lado direito possui filho)
        else if (root->p_right != nullptr && root->p_left == nullptr)
        {
            res = root->p_right;
        }
        // 3° Caso (Nó intermediário com dois filhos)
        // Duas estratégias podem ser utilizadas
        //  - 1° Substituir este nó pelo maior nó da sub-árvore da esquerda
        //  - 2° Substituir este nó pelo menor nó da sub-árvore da direita
        else 
        {
            // Utilizando o 1° caso (maior elemento da sub-árvore da esquerda)
            res = root->p_left;
            
            while (res->p_right != nullptr)
            {
                res = res->p_right;
            }   
            // salvando os dados antes de remover o nó
            T data = res->data();

            root = remove_(root, data);
            root->p_data = data;

            res = root;
        }
    }

    return res;
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

template<class T>
void BinaryTree<T>::remove(T key)
{
    BinaryTree<T>* bt = remove_(this, key);

    p_data = bt->p_data;
    p_root = bt->p_root;
    p_left = bt->p_left;
    p_right = bt->p_right;
}

template<class T>
void BinaryTree<T>::preOrder(T (*functor)(T key))
{
    preOrder_(this, functor);
}

template<class T>
void BinaryTree<T>::inOrder(T (*functor)(T key))
{
    inOrder_(this, functor);
}

template<class T>
void BinaryTree<T>::posOrder(T (*functor)(T key))
{
    posOrder_(this, functor);
}

template<class T>
void BinaryTree<T>::preOrder_(BinaryTree* root, T (*functor)(T key))
{
    root->p_data = functor(root->data());

    if (root->p_left != nullptr)
        preOrder_(root->p_left, functor);

    if (root->p_right != nullptr)
        preOrder_(root->p_right, functor);
}

template<class T>
void BinaryTree<T>::inOrder_(BinaryTree* root, T (*functor)(T key))
{
    if (root->p_left != nullptr)
        inOrder_(root->p_left, functor);

    root->p_data = functor(root->data());

    if (root->p_right != nullptr)
        inOrder_(root->p_right, functor);
}

template<class T>
void BinaryTree<T>::posOrder_(BinaryTree* root, T (*functor)(T key))
{
    if (root->p_left != nullptr)
        posOrder_(root->p_left, functor);

    if (root->p_right != nullptr)
        posOrder_(root->p_right, functor);
    root->p_data = functor(root->data());
}

#endif
