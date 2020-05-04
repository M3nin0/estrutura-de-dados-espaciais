#include "infix.hpp"
#include <iostream>

int main()
{

    std::cout << infixToPostfix("A*B") << std::endl;
    std::cout << infixToPostfix("A*B+C") << std::endl;

    return 0;
}
