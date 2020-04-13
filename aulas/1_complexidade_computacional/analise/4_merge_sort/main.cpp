#include <vector>
#include <iostream>
#include "sort.hpp"


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
    std::vector<double> vec {6, 7, 8, 9, 2, 1, 5, 3, 65, 45, 54};

    printVec(vec);
    mergeSort(vec, 0, vec.size() - 1);
    printVec(vec);

    return 0;
}
