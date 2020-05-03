#ifndef _KDTREE_HEADER
#define _KDTREE_HEADER

#include <cstddef>
#include "geometry.hpp"


struct KDNode
{
    KDNode(Point p);

    KDNode* left();
    KDNode* right();

    // i = 0; x
    // i = 1; y
    double dim(std::size_t i);

    KDNode* p_left, *p_right;

private:
    Point p_point;
};

KDNode::KDNode(Point p): p_point(p) {}

double KDNode::dim(std::size_t i)
{
    if (i == 0)
        return p_point.x();
    else if (i == 1)
    {
        return p_point.y();
    }
    return -1;
}

class KDTree
{
public:
    KDTree();

    void insert(Point p);
    KDNode* root = nullptr;
private:

    KDNode* insert_(KDNode* root, KDNode* nnode, std::size_t dim);
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

    if (root->dim(dim % 2) > nnode->dim(dim % 2))
        root->p_left = insert_(root->p_left, nnode, dim + 1);
    else
        root->p_right = insert_(root->p_right, nnode, dim + 1);
    return root;
}


#endif
