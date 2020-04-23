#include <stack>
#include <string>
#include <cstddef>
#include "infix.hpp"


bool isoperand(char& c) 
{ 
    // Ideia do geeks-for-geeks
    // verifico se o valor da tabela ascii corresponde
    // ao alfabeto de letras maiúsculas ou minúsculas 
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        return true;
    return false;
}

int precedenceFactor(char c)
{
    switch (c)
    {
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 3;
        case '(':
            return 1;
    }
    return -1;
}

std::string infixToPostfix(const std::string& infixexp)
{
    std::string result;
    std::stack<char> operandStack;

    for(std::size_t i = 0; i < infixexp.size(); ++i)
    {
        char symbol = infixexp[i];
        if (isoperand(symbol))
            // Se é um operando, apenas adiciona ao resultado final
            result.append(&symbol);
        else if (symbol == '(')
            // Empilha para controlar o início de uma expressão
            operandStack.push(symbol);
        else if (symbol == ')')
        // ao encontrar um operador ')', é indicado o final de uma operação
        // então, nesta parte, os elementos serão desempilhados até encontrar
        // o elemento '(' (Que indica o final da operação dentro dos parenteses)
        {
            char topc = operandStack.top();
            operandStack.pop();

            while (topc != '(')
            {
                result.append(&topc);
                operandStack.pop();
                topc = operandStack.top();
            }
        } 
        else
        {
            // caso nenhuma das opções acima tenham ocorrido, é entendido que existe um operador
            // assim as predecêndias são verificadas para que os operadores vão sendo adicionados
            // no resultado na ordem correta
            while (!operandStack.empty() && 
                (precedenceFactor(operandStack.top()) >= precedenceFactor(symbol)))
            {
                result.append(&operandStack.top());
                operandStack.pop();
            }
            operandStack.push(symbol);
        }
    }
    // os demais elementos que estão na pilha e não foram tratados são inseridos no resultado
    // aqui normalmente haverá casos com operadores de menor grau e semelhantes.
    while (!operandStack.empty())
    {
        result.append(&operandStack.top());
        operandStack.pop();
    }

    return result;
}
