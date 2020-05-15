#include "heap.hpp"
#include <vector>

template <class T>
inline void PrintVector(std::vector<T>& vec)
{
    for(auto el: vec)
    {
        std::cout << el << ", ";
    }
    std::cout << std::endl;
}


int main()
{
    std::vector<int> vec({98, 17, 86, 11, 16, 78, 85, 5, 8, 13, 9, 35, 46, 18, 70});

    MaxHeap<int> maxHeap(vec);
    std::vector<int> sortedVec = maxHeap.ExtractHeap(maxHeap.End());

    // resultados
    std::cout << "Antes de sortear" << std::endl;
    PrintVector(vec);
    std::cout << "Depois de sortear" << std::endl;
    PrintVector(sortedVec);

    return 0;
}
