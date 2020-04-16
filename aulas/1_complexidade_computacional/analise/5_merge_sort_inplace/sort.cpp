#include <vector>
#include <cstddef>
#include <limits>

#include "sort.hpp"

// Alteração do código do diretório "2_insertion_sort"
void insertionSort(std::vector<double>& elements)
{
    for (std::size_t i = 1; i < elements.size(); ++i)
    {
        int j = i - 1;
        int actualKey = elements[i];
        
        // Processo para encontrar a posição do elemento 
        // atual na direita
        while (j >= 0 && elements[j] > actualKey)
        {
            elements[j + 1] = elements[j];
            --j;
        }
        elements[j + 1] = actualKey;
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
        insertionSort(vec);
    }
}
