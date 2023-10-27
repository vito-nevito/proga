#include<iostream>
#include<string>
#include <windows.h>
#include "correctCin.h"

std::string getNline(std::string u, int N)
{
    std::string res;
    std::ifstream file(u);
    for(int i = 0; i < N; i++)
        std::getline(file, res);
    file.close();
    return res;
}

correctCin::correctCin() : m_url("error.txt")
{}

std::string correctCin::corMenu()
{
    std::string ans;
    int k = 0;
    while(!k)
    {
        k = 1;
        ans.clear();
        std::getline(std::cin, ans);
        if(std::strtol(ans.c_str(), NULL, 10) == 0)
        {
            std::cout << getNline(m_url, 2) << std::endl;
            k = 0;
        }
        else if(stoi(ans) < 0 || stoi(ans) > 3)
        {
            std::cout << getNline(m_url, 1) << std::endl;
            k =  0;
        }
    }
    return ans;
}

std::string correctCin::corEnd()
{
    std::string ans;
    int k = 0;
    while(!k)
    {
        k = 1;
        ans.clear();
        std::getline(std::cin, ans);
        if(ans != "y" && ans != "n")
        {
            std::cout << getNline(m_url, 1) << std::endl;
            k =  0;
        }
    }
    return ans;
}

std::string correctCin::corLet()
{
    std::string ans;
    int k = 0;
    while(!k)
    {
        k = 1;
        std::cout << getNline(m_url, 3);
        ans.clear();
        std::getline(std::cin, ans);
        if(ans.size() > 1)
            k = 0;
        else if((ans < "A" || ans > "Z") & (ans < "a" || ans > "z"))
            k = 0;
        if(ans == "exit")
            k = 1;
    }
    return ans;
}
