#ifndef _KDTREE_HEADER
#define _KDTREE_HEADER

#include <vector>
#include <cstddef>
#include "geometry.hpp"


struct KDNode
{
    KDNode(Point p);

    KDNode* left();
    KDNode* right();

    KDNode* p_left, *p_right;

    const Point point();
private:
    Point p_point;
};

KDNode::KDNode(Point p): p_point(p) {}

const Point KDNode::point()
{
    return p_point;
}

class KDTree
{
public:
    KDTree();

    KDNode* find(Point p);
    void insert(Point p);
    std::vector<KDNode*> search(Rectangle r);
private:
    KDNode* root = nullptr;

    KDNode* find_(KDNode* root, KDNode* fnode, std::size_t dim);
    KDNode* insert_(KDNode* root, KDNode* nnode, std::size_t dim);
    std::vector<KDNode*> search_(KDNode* root, Rectangle r, std::size_t dim);
};

KDTree::KDTree() { }

void KDTree::insert(Point p)
{
    root = insert_(root, new KDNode(p), 0);
}

KDNode* KDTree::insert_(KDNode* root, KDNode* nnode, std::size_t dim)
{
    if (root == nullptr)
        return nnode;

    if (root->point().dim(dim % 2) > nnode->point().dim(dim % 2))
        root->p_left = insert_(root->p_left, nnode, dim + 1);
    else
        root->p_right = insert_(root->p_right, nnode, dim + 1);
    return root;
}

KDNode* KDTree::find(Point p)
{
    return find_(root, new KDNode(p), 0);
}

KDNode* KDTree::find_(KDNode* root, KDNode* fnode, std::size_t dim)
{
    std::size_t actualDim = dim % 2;
    std::size_t nextDim = (dim + 1) % 2;

    if (root == nullptr)
        return nullptr;

    // Identifica se o nó atual possuí o elemento procurado
    if (fnode->point().dim(actualDim) == root->point().dim(actualDim) && 
            fnode->point().dim(nextDim) == root->point().dim(nextDim))
        return root;

    if (root->point().dim(actualDim) > fnode->point().dim(actualDim))
        return find_(root->p_left, fnode, dim + 1);
    else
        return find_(root->p_right, fnode, dim + 1);
    return nullptr;
}

std::vector<KDNode*> KDTree::search(Rectangle r)
{
    return search_(root, r, 0);
}

std::vector<KDNode*> KDTree::search_(KDNode* root, Rectangle r, std::size_t dim)
{
    std::vector<KDNode*> reported;
    std::vector<KDNode*> operational;

    std::size_t actualDim = dim % 2;
    std::size_t nextDim = (dim + 1) % 2;    
    Range actualDimRange = r.dim(actualDim);
    Range nextDimRange = r.dim(nextDim);    

    if (root == nullptr)
        return std::vector<KDNode*>();

    if (root->point().dim(actualDim) > actualDimRange.max())
        operational = search_(root->p_left, r, dim + 1);
    else
        operational = search_(root->p_right, r, dim + 1);

    if (root->point().dim(actualDim) >= actualDimRange.min() && 
        root->point().dim(actualDim) <= actualDimRange.max()) 
    {
        if (root->point().dim(nextDim) >= nextDimRange.min() && 
            root->point().dim(nextDim) <= nextDimRange.max())
            reported.push_back(root);
        
        std::vector<KDNode*> nodesInRange;

        nodesInRange = search_(root->p_left, r, dim + 1);
        reported.insert(reported.end(), nodesInRange.begin(), nodesInRange.end());
        nodesInRange.erase(nodesInRange.begin(), nodesInRange.end());

        nodesInRange = search_(root->p_right, r, dim + 1);
        reported.insert(reported.end(), nodesInRange.begin(), nodesInRange.end());

        return reported;
    }

    reported.insert(reported.end(), operational.begin(), operational.end());
    return reported;
}

#endif
