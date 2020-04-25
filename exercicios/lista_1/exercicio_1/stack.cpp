#include "stack.hpp"

#include <cstddef>
#include <algorithm>
#include <stdexcept>

Stack::Stack()
{
    p_elements = new int[10];
}

Stack::Stack(std::size_t size)
{
    p_size = size;
    p_elements = new int[size];
}

Stack::~Stack()
{
    delete[] p_elements;
}

void Stack::push(int v)
{
    // Caso o índice chegue ao tamanho total,
    // então a estrutura de dados projetada automaticamente
    // dobra a quantidade de posições possíveis na estrutura;
    if (p_idx == p_size)
    {
        int *tmp = new int[p_size*2];
        std::copy(p_elements, p_elements + (p_size*2), tmp);
        p_size *= 2;
    }

    p_elements[p_idx++] = v;
}

bool Stack::empty()
{
    return p_idx == 0;
}

void Stack::pop()
{
    if (empty())
        throw std::runtime_error("A pilha está vazia!");
    p_idx--;
}

int Stack::top()
{
    if (empty())
        throw std::runtime_error("A pilha está vazia");

    return p_elements[p_idx-1];
}
