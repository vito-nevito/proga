#include<iostream>
#include<fstream>
#include <map>
#include <windows.h>
#include <string.h>

int main()
{
    setlocale (LC_ALL,"Russian");
    std::map<char, unsigned long int> stats;
    std::ifstream file("war_and_peace.ru.txt");
    std::string lit;
    while (std::getline(file, lit))
    {
        for (int k = 0; k < lit.size(); k++)
        {

            lit[k] = toupper(lit[k]);
            if ((lit[k] >= 'А') && (lit[k] <= 'Я'))
            {
                if (stats.count(lit[k]))
                {
                    stats[lit[k]] += 1;
                }
                else
                {
                    stats[lit[k]] = 1;
                }
            }
        }
    }
    file.close();
    for (const auto& [lit, count_] : stats)
        std::wcout << lit << "\t" << count_ << std::endl;
}


