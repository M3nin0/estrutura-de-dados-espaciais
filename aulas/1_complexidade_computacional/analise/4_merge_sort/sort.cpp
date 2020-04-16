#include <vector>
#include <cstddef>
#include <limits>

#include "sort.hpp"


std::vector<double> select(std::vector<double>& vec, std::size_t start, std::size_t final)
{
    std::vector<double> vecResult;
    for(std::size_t i = start; i <= final; ++i)
    {
        vecResult.push_back(vec[i]);
    }
    return vecResult;
}


void merge(std::vector<double>& vec, std::size_t left, std::size_t mid, std::size_t right)
{
    int i = 0, j = 0;
    std::vector<double> leftVec = select(vec, left, mid);
    std::vector<double> rightVec = select(vec, mid + 1, right);

    // adição dos sentinelas para evitar problemas com
    // lados vazios
    double sentinel = std::numeric_limits<double>::max();
    leftVec.push_back(sentinel);
    rightVec.push_back(sentinel);

    for (std::size_t k = left; k <= right; ++k)
    {
        if (leftVec[i] <= rightVec[j])
        {
            vec[k] = leftVec[i++];
        } else 
        {
            vec[k] = rightVec[j++];
        }
    }
}


void mergeSort(std::vector<double>& vec, std::size_t left, std::size_t right)
{
    if (left < right)
    {
        std::size_t mid = (left + right) / 2;
        mergeSort(vec, left, mid);
        mergeSort(vec, mid + 1, right);

        // Merge de duas sequências ordenadas
        merge(vec, left, mid, right);
    }
}
