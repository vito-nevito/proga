#include<iostream>
#include<string>
#include "Slovo.h"

void Slovo::setSlovo(std::string a)
{
    std::string S (a.size(), '-');
    m_slovo = a;
    m_mask = S;
    m_lenth = a.size();
}

void Slovo::printMask()
{
    std::cout << m_mask << "\n";
}

int Slovo::openLet(std::string c)  // 0-не угадали 1-угадали 2-уже была
{
    int k = 0;
    for(int i = 0; i < m_lenth; i++)
    {
        if(m_mask.substr(i, 1) == "-" & m_slovo.substr(i, 1) == c)
        {
            m_mask[i] = c.substr(0, 2)[0];
            k = 1;
        }
        else if(m_mask.substr(i, 1) == c)
        {
            return 2;
        }
    }
    return k;
}

bool Slovo::proveritSlovo()
{
    return (m_slovo == m_mask);
}
