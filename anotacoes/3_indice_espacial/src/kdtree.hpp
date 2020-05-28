#ifndef __KDTREE_HPP__
#define __KDTREE_HPP__

#include <vector>
#include <initializer_list>

#include "rectangle.hpp"
#include "coordinate.hpp"

struct Node
{
    Coordinate c_;
    Node *left_, *righ_;

    ~Node();
};

class KDTree
{
public:
    KDTree();
    KDTree(std::initializer_list<Coordinate> l);
    ~KDTree();

    void insert(const Coordinate& c);
    bool contains(const Coordinate& c) const;
    std::vector<Coordinate> search(const Rectangle& r) const;
private:
    Node* root_;

    bool contains_(Node* root, const Coordinate& c, bool isXDimension) const;
    void search_(const Node* root, std::vector<Coordinate>& coords, 
                                    const Rectangle& r, bool isXDimension) const;
};

#endif // __KDTREE_HPP__
