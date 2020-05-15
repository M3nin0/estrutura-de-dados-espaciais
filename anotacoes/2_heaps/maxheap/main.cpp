#include "heap.hpp"
#include <vector>
#include <algorithm>

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
    std::cout << "Foi sorteado corretamente ?" << std::is_sorted(sortedVec.begin(), sortedVec.end()) << std::endl;

    // Testando sort crescente
    std::cout << "Sort com ordem inversa" << std::endl;
    std::vector<int> vec2({98, 17, 86, 11, 16, 78, 85, 5, 8, 13, 9, 35, 46, 18, 70});

    MaxHeap<int> maxHeapSort;
    maxHeapSort.Sort(vec2);
    std::cout << "Foi sorteado corretamente ? " << std::is_sorted(vec2.begin(), vec2.end()) << std::endl;

    return 0;
}
