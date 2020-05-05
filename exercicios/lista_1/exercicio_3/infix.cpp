#include "infix.hpp"

#include <stack>
#include <string>
#include <cstddef>
#include <math.h>
#include <limits>


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

double evaluate(double a, double b, char op)
{
    switch (op)
    {
    case '^':
        return std::pow(a, b);
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
    // Caso não encontre a ideia é retornar um valor
    // que fique evidente o erro
    return std::numeric_limits<double>::max();
}

double evaluatePostfix(const std::string& postfixexp)
{
    std::stack<double> opStack;

    for(auto c: postfixexp)
    {
        if (std::isdigit(c))
            opStack.push(std::atof(&c));
        if (isOperation(c))
        {
            // Caso não seja digito é assumido que é necessário fazer uma operação
            // A ideia aqui é apenas consumir a estrutura da notação posfixa.
            double a = opStack.top();
            opStack.pop();
            double b = opStack.top();
            opStack.pop();

            opStack.push(evaluate(a, b, c));
        }
    }

    return opStack.top();
}
