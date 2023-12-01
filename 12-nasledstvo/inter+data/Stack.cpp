#include <assert.h>
#include<iostream>
#include "Stack.h"

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
