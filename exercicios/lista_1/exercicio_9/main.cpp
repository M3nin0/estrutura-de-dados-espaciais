#include "../exercicio_8/tree.hpp"
#include <random>
#include <cstddef>
#include <math.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


BinaryTree<double>* applyRandomValuesInTree(std::size_t n)
{
    BinaryTree<double>* bt = new BinaryTree<double>();

    std::random_device randomDevice; // Utilizado para gerar a seed
    std::mt19937 engine(randomDevice()); // Engine de geração de números aleatórios com o algoritmo Mersenne Twister
    std::uniform_real_distribution<> dist(1.0, std::pow(10, n));

    std::size_t sentinel = 0;

    while (sentinel < std::pow(10, n))
    {
        double tmp = dist(engine) / 1500;

        // Estrutura criada para garantir que elementos repetidos
        // não sejam contabilizados. Apenas para dar confiabilidade ao teste
        if (bt->search(tmp) == nullptr) 
        {
            bt->insert(tmp);
            sentinel++;
        } 
    } 
    return bt;
}


int main()
{
    BinaryTree<double>* bt;    
    std::ofstream outFile; //output file stream

    try
    {
        outFile.open("alturas.csv", std::ios::trunc);
        outFile << "n, altura, log2n, teste\n";

        // Faz uma bateria de testes
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
