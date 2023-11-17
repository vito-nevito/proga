#include <assert.h>
#include<iostream>
#include "Ochered.h"

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

