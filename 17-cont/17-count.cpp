#include<iostream>
#include<fstream>
#include <map>
#include <windows.h>
#include <string.h>

int main()
{
    SetConsoleCP (CP_UTF8);
    SetConsoleOutputCP (CP_UTF8);
    //setlocale (LC_ALL,"Russian");
    std::map<wchar_t, unsigned long int> stats;
    std::wifstream file("war_and_peace.ru.txt");
    wchar_t a;
    file >> a;
    while (!file.eof())
    {
        file >> a;
        a = tolower(a);
        stats[a] += 1;
    }
    file.close();
    for (const auto& [lit, count_] : stats)
        std::wcout << lit << "\t" << count_ << std::endl;
}
