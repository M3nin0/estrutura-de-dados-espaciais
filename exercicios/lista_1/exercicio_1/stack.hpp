#ifndef _STACK_HEADER
#define _STACK_HEADER

#include <cstddef>

class Stack
{
public:
    Stack();
    Stack(std::size_t size);
    ~Stack();

    int top();
    void pop();
    bool empty();
    void push(int v);
private:
    int *p_elements;
    std::size_t p_idx = 0;
    std::size_t p_size = 10;
};

#endif
