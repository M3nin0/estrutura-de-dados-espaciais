#include "stack.hpp"

#include <cstddef>
#include <iostream>

inline void print(int v)
{
    std::cout << v << std::endl;
}

void putRandomValues(Stack& s, std::size_t size)
{
    for(std::size_t i = 0; i < size; ++i)
        s.push(std::rand() % (i + 10));
}

int main()
{
    Stack s;

    // Testando as exceções (Comentadas para evitar erros durante a execução)
    // s.pop();
    // s.top();
    
    // adicionando e removendo elementos e verificando o topo
    s.push(2);
    print(s.top());

    s.push(23);
    print(s.top());

    s.pop();
    print(s.top());

    // Testando o cresimento da pilha
    putRandomValues(s, 500);
    // como forma de validar que as operações funcionam, um elemento fora do range
    // aleatório é inserido na pilha
    s.push(999);
    print(s.top());
    s.pop();
    print(s.top());

    return 0;
}
