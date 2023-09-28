#include <iostream>
#include <windows.h>
#include <ctime>
#include <iomanip>

int simple_2(int a)
{
    return a%2;
}

int binary_2(int a)
{
    return (a&1);
}

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    long int N;
    //std::cout << "Введите число тестов: ";
    //std::cin >> N;
    N = 10000000;
    std::clock_t start = std::clock();
    for(long int i = 0; i < N; i++)
        simple_2(i);
    std::cout << "Время %: " << std::fixed << std::setprecision(2) << 1000.0 * (double)(std::clock() - start) / CLOCKS_PER_SEC << std::endl;
    start = std::clock();
    for(long int i = 0; i < N; i++)
        binary_2(i);
    std::cout << "Время &: " << std::fixed << std::setprecision(2) << 1000.0 * (double)(std::clock() - start) / CLOCKS_PER_SEC << std::endl;
}

