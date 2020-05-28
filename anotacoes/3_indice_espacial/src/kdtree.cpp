#include "kdtree.hpp"
#include "rectangle.hpp"
#include <initializer_list>

Node::~Node()
{
    delete left_;
    delete righ_;
}

KDTree::KDTree()
    : root_(nullptr)
{
}

KDTree::KDTree(std::initializer_list<Coordinate> l)
{
    for(Coordinate c: l)
    {
        insert(c);
    }
}

KDTree::~KDTree()
{
    delete root_;
}

void KDTree::insert(const Coordinate& c)
{
    Node* n = root_;
    Node* parent = nullptr;

    bool x = true;
    while (n != nullptr) // Enquanto não chegar em uma folha
    {
        parent = n;

        if (x) // Particinando o espaço ao longo do eixo X
        {
            // Caso o valor de X seja menor, vai para esquerda, se não
            // vai para a direita
            n = (c.x_ < n->c_.x_) ? n->left_ : n->righ_;
        }
        else // Particinando o espaço ao longo do eixo X
        {
            n = (c.y_ < n->c_.y_) ? n->left_ : n->righ_;
        }
        x = !x;
    }
    Node* nn = new Node{c, nullptr, nullptr};

    // Caso particular, a árvore está vazia
    if(parent == nullptr)
        root_ = nn;
    else if (x) // O parent (Valor anterior ao atual) foi particionado em Y
    {
        if (c.y_ < parent->c_.y_)
            parent->left_ = nn;
        else
            parent->righ_ = nn;
    }
    else
    {
        if (c.x_ < parent->c_.x_)
            parent->left_ = nn;
        else
            parent->righ_ = nn;
    }
}

bool KDTree::contains(const Coordinate& c) const
{
    return contains_(root_, c, true);
}

bool KDTree::contains_(Node* root, const Coordinate& c, bool isXDimension) const
{
    if (root == nullptr)
        return false;

    // Verifica se o elemento da raiz atual é o pesquisado
    if (isXDimension)
    {
        // Verifica a dimensão X, caso seja igual, verifica em Y
        if (c.x_ == root->c_.x_ && c.y_ == root->c_.y_)
            return true;
    }
    else
    {
        // Verifica a dimensão Y, caso seja igual, verifica em X
        if (c.y_ == root->c_.y_ && c.x_ == root->c_.x_)
            return true;
    }

    // Caso não seja, então busca nos filhos (Mesma lógica que a árvore binária)
    if (isXDimension)
    {
        if (c.x_ > root->c_.x_)
            return contains_(root_->righ_, c, !isXDimension);
        else
            return contains_(root_->left_, c, !isXDimension);
    }
    else
    {
        if (c.y_ > root_->c_.y_)
            return contains_(root_->righ_, c, !isXDimension);
        else
            return contains_(root->left_, c, !isXDimension);        
    }
    return false;
}

std::vector<Coordinate> KDTree::search(const Rectangle& r) const
{
    std::vector<Coordinate> reportedCoordinates;
    search_(root_, reportedCoordinates, r, true); // Busca e reporta

    return reportedCoordinates;
}

void KDTree::search_(const Node* root, 
                                std::vector<Coordinate> coords, 
                                const Rectangle& r, bool isXDimension) const
{
    if (root_ == nullptr)
        return; // Ponto de parada

    if (r.contains(root_->c_)) // Verifica todas as dimensões disponíveis (X e Y)
        coords.push_back(root_->c_);

    // Verificando qual dos lados deve ser consultado para a pesquisa atual
    if(isXDimension)
    {
        // Verifica se as dimensões de X estão dentro do intervalo
        if (r.ll_.x_ <= root_->c_.x_) // Verifica se a raiz está do lado direito de xmin
            search_(root_->left_, coords, r, !isXDimension);
        if (r.ur_.x_ >= root_->c_.x_) // Verifica se a raiz está do lado esquerdo de xmax
            search_(root_->righ_, coords, r, !isXDimension);
    }
    else
    {
        // Verifica se as dimensões de Y estão dentro do intervalo
        if (r.ll_.y_ <= root_->c_.y_) // Verifica se a raiz está acima de ymin
            search_(root_->left_, coords, r, !isXDimension);
        if (r.ur_.y_ >= root_->c_.y_) // Verifica se a raiz está abaixo de ymax
            search_(root_->righ_, coords, r, !isXDimension);
    }

    return;
}
