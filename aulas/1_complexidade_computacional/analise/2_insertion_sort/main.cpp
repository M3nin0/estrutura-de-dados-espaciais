#include <iostream>
#include <cstddef>

#include "sort.hpp"

#include <chrono>
#include <ctime>


inline void printArray(double *elements, std::size_t size)
{
    for(std::size_t i = 0; i < size; ++i)
        std::cout << elements[i] << " ";
    std::cout << std::endl;
}


int main()
{
    double elements[] = {6, -2, 22, -1, 21, 88, 45};
    std::size_t size = sizeof(elements) / sizeof(double);

    printArray(elements, size); 
    insertionSort(elements, size);
    printArray(elements, size);

    return 0;
}
