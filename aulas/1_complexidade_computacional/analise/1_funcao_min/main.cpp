#include <vector>
#include <cstddef>
#include <iostream>

inline void printVec(std::vector<double> vec)
{
    std::vector<double>::iterator it;

    for(it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

double min(std::vector<double> vec)
{
    double minv = vec[0];

    for (std::size_t i = 1; i < vec.size(); ++i)
    {
        if (vec[i] < minv)
            minv = vec[i];
    }
    return minv;
}

int main()
{
    std::vector<double> vec {5, 6, 7, 0, -1, 23};

    printVec(vec);
    std::cout << "min value: " << min(vec) << std::endl;

    return 0;
}
