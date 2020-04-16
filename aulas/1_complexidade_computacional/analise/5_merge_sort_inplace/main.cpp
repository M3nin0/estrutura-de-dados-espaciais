#include <vector>
#include <iostream>
#include "sort.hpp"
#include "../utils/number.hpp"
#include "../benchmark/pbenchmark.hpp"

inline void printVec(std::vector<double> vec)
{
    std::vector<double>::iterator it;

    for(it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main()
{
    {
        PBanchmark::Timer timer("MergeSort com 5 elementos");
        std::vector<double> vec = magic(5);

        mergeSort(vec, 0, vec.size() - 1);
    }
    {
        PBanchmark::Timer timer("MergeSort com 100 elementos");
        std::vector<double> vec = magic(100);

        mergeSort(vec, 0, vec.size() - 1);
    }
    {
        PBanchmark::Timer timer("MergeSort com 1000 elementos");
        std::vector<double> vec = magic(1000);
        
        mergeSort(vec, 0, vec.size() - 1);
    }
    {
        PBanchmark::Timer timer("MergeSort com 10000 elementos");
        std::vector<double> vec = magic(10000);

        mergeSort(vec, 0, vec.size() - 1);
    }

    return 0;
}
