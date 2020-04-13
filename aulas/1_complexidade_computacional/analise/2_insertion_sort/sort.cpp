#include <cstddef>
#include "sort.hpp"

void insertionSort(double elements[], std::size_t size)
{
    for (std::size_t i = 1; i < size; ++i)
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
