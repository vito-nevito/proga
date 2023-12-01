#include <assert.h>
#include<iostream>
#include "Ochered.h"

void Ochered::push(int a)
{
    m_data.push_back(a);
}

int Ochered::pop()
{
    if(m_data.empty())
    {
        std::cout << "NOOOOOO" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    int temp = m_data.front();
    m_data.erase(m_data.begin());;
    return temp;
}

void Ochered::print()
{
    for(int i : m_data)
        std::cout << i << " ";
    std::cout << std::endl;
}

bool Ochered::isEmpty()
{
    if(m_data.size() == 0)
        return 1;
    return 0;
}

std::vector<int> Ochered::data()
{
    return m_data;
}
