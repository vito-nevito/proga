#include<iostream>
#include <cmath>
#include <windows.h>

int main()
{
    SetConsoleCP (CP_UTF8);
    SetConsoleOutputCP (CP_UTF8);
    double a = 0;
    std::cout << "Введите число: ";
    while(!a)
    {
        std::cin >> a;
        if(std::cin.fail())
        {
            std::cout << "Введена строка" << std::endl;
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            a = 0;
        }
        else if(a < 0)
        {
            std::cout << "Введенное число меньше 0" << std::endl;
            a = 0;
        }
        else if(int(a) != a)
        {
            std::cout << "Введенное число нецелое" << std::endl;
            a = 0;
        }
        else if(a > 100000)
        {
            std::cout << "Введенное число больше 100 000" << std::endl;
            a = 0;
        }
        else
        {
            int* fact = (int*)calloc(1, sizeof(int));
            fact[0] = 1;
            int zeros_5 = 0;
            // считаем количество нулей в факториале
            unsigned long int n = a;
            while(n / 5 > 0)
            {
                zeros_5 += n / 5;
                n /= 5;
            }
            long int zeros_2 = zeros_5;
            n = 1;
            for(long int i = 1; i < a + 1; i++)
            {
                long int k = i;
                // убираем из числа лишние множители(5 и 2)
                while(k % 5 == 0)
                {
                    k /= 5;
                }
                while(k % 2 == 0 && zeros_2 > 0)
                {
                    k /= 2;
                    zeros_2 -= 1;
                }
                int res = 0;
                // умножаем на полученный множитель поразрядно
                for(unsigned long int j = 0; j < n; j++)
                {
                    unsigned long int temp = (fact[j] * k + res);
                    fact[j] = temp % 10;
                    res = temp / 10;
                }
                // запись остатка
                while(res > 0)
                {
                    n += 1;
                    fact = (int*)std::realloc(fact, n*sizeof(int));
                    if (fact == NULL)
                    {
                        std::cout << "Ошибка выделения памяти" << std::endl;
                        return 0;
                    }
                    fact[n-1] = res % 10;
                    res /= 10;
                }
            }
            unsigned long int num_count[10] {0};
            // вывод
            for(long int i = n - 1; i >= 0; i--)
            {
                std::cout << fact[i];
                num_count[fact[i]] += 1;
            }
            // учитавать последние нули
            /*
            num_count[0] += zeros_5;
            n += zeros_5;
            */
            for(long int i = 0; i < zeros_5; i++)
                std::cout << 0;
            std::cout << std::endl << std::endl;
            // расперделение цифр в факториале
            std::cout << "Распределение цифр в факториале: " << int(a) << "!" << std::endl;
            for(int i = 0; i < 10; i++)
                std::cout << i << ": "<< std::round(num_count[i] * 1000 / n) / 10. << " %" << std::endl;
            // очистка памяти
            delete fact;
        }
    }
}
