#include "infix.hpp"
#include <iostream>


int main()
{
    std::cout << infixToPostfix("1+2") << std::endl;
    std::cout << evaluatePostfix(infixToPostfix("1+2")) << std::endl;

    std::cout << infixToPostfix("(1 + 2) * (1 + 2)") << std::endl;
    std::cout << evaluatePostfix(infixToPostfix("(1 + 2) * (1 + 2)")) << std::endl;

    std::cout << infixToPostfix("5 * (((9 + 8) * (4 * 6)) + 7)") << std::endl;
    std::cout << evaluatePostfix(infixToPostfix("5 * (((9 + 8) * (4 * 6)) + 7)")) << std::endl;

    return 0;
}
