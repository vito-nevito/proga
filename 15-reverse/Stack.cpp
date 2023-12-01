#include <assert.h>
#include<iostream>
#include "Stack.h"

void Stack::push(int a)
{
    m_data.push_back(a);
}

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
}

void Stack::print()
{

    for(int i : m_data)
        std::cout << i << " ";
    std::cout << std::endl;
}

bool Stack::isEmpty()
{
    if(m_data.size() == 0)
        return 1;
    return 0;
}

std::vector<int> Stack::data()
{
    return m_data;
}
