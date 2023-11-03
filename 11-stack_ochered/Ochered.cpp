#include <assert.h>
#include "Ochered.h"

Ochered::Ochered(): m_data({}) {};

void Ochered::push(int a)
{
    m_data.push_back(a);
};

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
};

