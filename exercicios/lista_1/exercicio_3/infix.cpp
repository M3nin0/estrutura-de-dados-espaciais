#include <stack>
#include <string>
#include <cstddef>
#include "infix.hpp"


bool isOperation(char& c)
{
    char operations[] = {
        '+',  '-',  // 1
        '*',  '/', 
        '^'
    };

    for(char op: operations)
    {
        if (op == c)
            return true;
    }
    return false;
}


std::size_t pemdas(char& c)
{
    switch (c)
    {
        case '^':
            return 5;
        case '*':
        case '/':
            return 3;
        case '+':
        case '-':
            return 1;
    }
    return 0;
}


std::string infixToPostfix(const std::string& infixexp)
{
    std::string result;
    std::stack<char> opStack;

    for(char c: infixexp)
    {
        if (std::isspace(c))
            continue;

        // 1. O símbolo lido é um operando
        if (std::isdigit(c))
            result.insert(result.end(), c);

        // 2. O símbolo indicado é uma operação (Operador)
        if (isOperation(c))
        {
            // O operador vai ser inserido na pilha, porém, antes disso
            // os operadores que possuem prioridade maior ou igual serão 
            // removidos
            if (opStack.size() == 0)
                opStack.push(c);
            else
            {
                char topc = opStack.top();
                if (topc == '(')
                    opStack.push(c);
                else
                    while(pemdas(topc) >= pemdas(c))
                    {
                        opStack.pop();
                        result.insert(result.end(), topc);
                        topc = opStack.top();
                    }
            }
        }

        // Este parentese está sendo salvo para indicar que,
        // um operador que na expressão infixa, possui uma precedência
        // maior do que aqueles que não estão
        if (c == '(')
            opStack.push(c);

        // Lógica complementar ao parentese acima, neste, os elementos são
        // adicionados ao resultado final
        if (c == ')')
        {
            while (opStack.top() != '(')
            {
                result.insert(result.end(), opStack.top());
                opStack.pop();
            }
            // Após o final, o topo será '(', desta forma, o mesmo
            // pode ser removido
            opStack.pop();
        }
    }

    // Para vários casos, ao final do processo a pilha pode não estar vazia
    // ao final da execução, assim é assumido que estes valores precisam ser inseridos
    // no resultado. Considere como exemplo a expressão 1 + 2, no final do processo o operador
    // '+' estará dentro da pilha no final
    while (opStack.size() != 0)
    {
        result.insert(result.end(), opStack.top());
        opStack.pop();
    }
    
    return result;
}
