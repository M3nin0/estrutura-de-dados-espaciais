#include <vector>
#include <iostream>
#include "sort.hpp"
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
        PBanchmark::Timer timer("MergeSort com 11 elementos");
        std::vector<double> vec {6, 7, 8, 9, 2, 1, 5, 3, 65, 45, 54};
        
        mergeSort(vec, 0, vec.size() - 1);
    }
    {
        PBanchmark::Timer timer("MergeSort com 22 elementos");
        std::vector<double> vec {6, 7, 8, 9, 2, 1, 5, 3, 65, 45, 54,
                                6, 7, 8, 9, 2, 1, 5, 3, 65, 45, 54};

        mergeSort(vec, 0, vec.size() - 1);
    }

    return 0;
}
