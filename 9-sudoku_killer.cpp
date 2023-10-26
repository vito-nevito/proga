#include<iostream>
#include<vector>
#include <windows.h>
#include<string>

void printV(std::vector<int> a)
{
    int N = a.size();
    for(int i = 0; i < N; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
}

int sumV(std::vector<int> a)
{
    int S = 0;
    int N = a.size();
    for(int i = 0; i < N; i++)
        S += a[i];
    return S;
}

void sudoku(std::vector<int> ans, std::vector<int> res, int S, int n)
{
    if(res.size())
    {
        std::vector<int> temp_1 = ans;
        ans.push_back(res.back());
        res.pop_back();
        if(n - 1)                           //если удаленный элемент не последний
            sudoku(ans, res, S, n - 1);
        else if(sumV(ans) == S)             //если элемент последний и сумма подходит
            printV(ans);
        sudoku(temp_1, res, S, n);
    }
}

void deleteV(std::vector<int>& a, int b) //удалить все элементы b из вектора a
{
    std::vector<int> ans{};
    int N = a.size();
    for(int i = 0; i < N; i++)
        if(a[i] != b)
            ans.push_back(a[i]);
    a = ans;
}

int main()
{
    SetConsoleCP (CP_UTF8) ;
    SetConsoleOutputCP (CP_UTF8) ;

    std::string e;

    int S;
    std::cout << "Введите сумму чисел в группе: ";
    std::getline(std::cin, e);
    S = stoi(e);
    e.clear();


    int n;
    std::cout << "Введите количество ячеек: ";
    std::getline(std::cin, e);
    n = stoi(e);
    e.clear();

    std::cout << "Введите запрещенные числа(если таких нет, то 0): ";
    std::getline(std::cin, e);

    std::vector<int> a {1, 2, 3, 4, 5, 6, 7, 8, 9}; // выделяем возможные числа
    std::vector<int> b{};
    int N = e.size();
    for(int i = 0; i < N; i++)
    {
        if(e[i] != ' ')
            deleteV(a, int(e[i]-'0'));
    }

    sudoku(b, a, S, n);
}
