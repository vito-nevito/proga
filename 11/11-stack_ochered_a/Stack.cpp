#include <assert.h>
#include "Stack.h"

void Stack::push(int a)
{
    m_data.push_back(a);
};

int Stack::pop()
{
    if(m_data.empty())
    {
        std::cout << "NOOOOOO" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    int temp = m_data.back();
    m_data.pop_back();
    return temp;
};
