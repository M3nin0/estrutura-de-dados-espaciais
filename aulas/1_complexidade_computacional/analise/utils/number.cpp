#include "number.hpp"

#include <vector>
#include <cstddef> // size_t
#include <cstdlib> // rand

std::vector<double> magic(std::size_t size)
{
    std::vector<double> res;
    for(std::size_t i = 0; i < size; ++i)
    {
        res.push_back(rand() % 1000);
    }
    return res;
}
