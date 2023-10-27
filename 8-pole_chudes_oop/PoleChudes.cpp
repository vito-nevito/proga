#include<iostream>
#include<string>
#include <windows.h>
#include <fstream>
#include <ctime>
#include "PoleChudes.h"
#include "correctCin.cpp"
#include "Slovo.cpp"

void PoleChudes::createSlovo()
{
    srand(time(NULL));
    std::ifstream file(m_url_dict);
    std::string s;
    std::getline(file, s);
    int N = rand()%(std::stoi(s)) + 1;
    for(int i = 0; i < N; i++)
        std::getline(file, s);
    file.close();
    m_S.setSlovo(s);
    m_S.printMask();
}

void PoleChudes::vvodLet()
{
    correctCin _;
    std::string let = _.corLet();
    if(let == "exit")
        m_status = -1;
    else
    {
        int k = m_S.openLet(let);
        if(k == 0)
            std::cout << getNline(m_url_output, 1) << std::endl;
        else if(k == 1)
            std::cout << getNline(m_url_output, 2) << std::endl;
        else
            std::cout << getNline(m_url_output, 3) << std::endl;
        m_S.printMask();
    }
}

void PoleChudes::setGame(std::string a)
{
    m_status = 0;
    m_url_dict = a;
    m_url_output = "output.txt";
}

bool PoleChudes::notEnd()
{
    if(m_S.proveritSlovo() || m_status == -1)
        return 0;
    return 1;
}

int PoleChudes::getStatus()
{
    return m_status;
}

