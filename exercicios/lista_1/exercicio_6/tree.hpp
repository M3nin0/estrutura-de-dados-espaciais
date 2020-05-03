#ifndef _TREE_HEADER
#define _TREE_HEADER

template<class T>
class BinaryTree
{
public:
    BinaryTree();
    BinaryTree(T key);

    T data();

    void remove(T key);
    void insert(T key);
    BinaryTree* search(T key);
private:
    T p_data;
    BinaryTree *p_root = nullptr;
    BinaryTree *p_left = nullptr, *p_right = nullptr;

    BinaryTree* remove_(BinaryTree* root, T key);
    BinaryTree* search_(BinaryTree* root, T key);
    BinaryTree* insert_(BinaryTree* root, BinaryTree * nbstree);
};

template<class T>
BinaryTree<T>::BinaryTree() {}

template<class T>
BinaryTree<T>::BinaryTree(T key): p_data(key) {}

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

    if (root != nullptr)
    {
        if (root->data() > key)
        {
            root->p_left = remove_(root->p_left, key);
        } else if (root->data() < key)
        {
            root->p_right = remove_(root->p_right, key);
        } else
        {
            // Tratamento dos três casos base
            // 1° Caso (O elemento a ser removido é um nó folha)
            if (root->p_left == nullptr && root->p_right == nullptr)
            {
                delete root; // testar deleção de ponteiro
            }
            // 2° Caso (Nó intermediário com apenas um filho)
            // 2.1 (Lado esquerdo possui filho)
            else if (root->p_left != nullptr && root->p_right == nullptr)
            {
                res = root->p_left;
                delete root;
            }
            // 2.2 (Lado direito possui filho)
            else if (root->p_right != nullptr && root->p_left == nullptr)
            {
                res = root->p_right;
                delete root;
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
                root->p_data = res->data();
                remove_(res, res->data());
                res = root;
            }
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
    remove_(this, key);
}

#endif
