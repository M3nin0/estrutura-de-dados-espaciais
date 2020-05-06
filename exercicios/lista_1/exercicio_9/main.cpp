#include "../exercicio_8/tree.hpp"
#include <random>
#include <cstddef>
#include <math.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


BinaryTree<int>* applyRandomValuesInTree(std::size_t n)
{
    BinaryTree<int>* bt = new BinaryTree<int>();

    std::random_device randomDevice; // Utilizado para gerar a seed
    std::mt19937 engine(randomDevice()); // Engine de geração de números aleatórios com o algoritmo Mersenne Twister
    std::uniform_int_distribution<> dist(1, std::pow(10, n));

    for(std::size_t i = 0; i < std::pow(10, n); ++i)
    {
        bt->insert(dist(engine));
    }

    return bt;
}


int main()
{
    BinaryTree<int>* bt;    
    std::ofstream outFile; //output file stream

    try
    {
        outFile.open("alturas.csv", std::ios::trunc);
        outFile << "n, altura, log2n, teste\n";

        for(std::size_t t = 1; t <= 10; ++t)
        {
            for(std::size_t i = 1; i <= 6; ++i)
            {
                bt = applyRandomValuesInTree(i);
                double log2h = std::log2(std::pow(10, i));
                outFile << i << "," << bt->height() << "," << log2h << "," << t << std::endl;
            }
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    outFile.close();
    return 0;
}
