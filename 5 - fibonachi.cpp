#include<iostream>
#include <cmath>

struct very_long_int
{
    int* value = (int*)calloc(1, sizeof(int));
    int n = 1;
};

int main()
{
    setlocale(LC_ALL, "Russian");
    double a = 0;
    while(!a)
    {
        std::cin >> a;
        if(std::cin.fail())
        {
            std::cout << "������� ������" << std::endl;
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            a = 0;
        }
        else if(a < 1)
        {
            std::cout << "��������� ����� ������ 0" << std::endl;
            a = 0;
        }
        else if(int(a) != a)
        {
            std::cout << "��������� ����� �������" << std::endl;
            a = 0;
        }
        else if(a > 100)
        {
            std::cout << "��������� ����� ������ 100" << std::endl;
            a = 0;
        }
        else
        {
            struct very_long_int fib[int(a + 1)];
            // ������ ������ ��� �����
            fib[0].value[0] = 0;
            fib[1].value[0] = 1;
            for(int i = 2; i < a + 1; i++)
            {
                int res = 0;
                int n1 = fib[i - 2].n;
                int n2 = fib[i - 1].n;
                int j;
                // ���������� ���������� � ������� ������
                for(j = 0; j < n1; j++)
                {
                    int temp = (fib[i - 1].value[j]  + fib[i - 2].value[j] + res);
                    fib[i].value = (int*)realloc(fib[i].value, (j + 1)*sizeof(int));
                    fib[i].n = j + 1;
                    if(fib[i].value == NULL)
                    {
                        std::cout << "������ ��������� ������" << std::endl;
                        return 0;
                    }
                    fib[i].value[j] = temp % 10;
                    res = temp / 10;
                }
                // ���������� ���������� ������� ��������
                for(j; j < n2; j++)
                {
                    int temp = (fib[i - 1].value[j] + res);
                    fib[i].value = (int*)realloc(fib[i].value, (j + 1)*sizeof(int));
                    if(fib[i].value == NULL)
                    {
                        std::cout << "������ ��������� ������" << std::endl;
                        return 0;
                    }
                    fib[i].n = j + 1;
                    fib[i].value[j] = temp % 10;
                    res = temp / 10;
                }
                // ���������� ������� ���� �����
                if(res)
                {
                    fib[i].value = (int*)realloc(fib[i].value, (j + 1)*sizeof(int));
                    if(fib[i].value == NULL)
                    {
                        std::cout << "������ ��������� ������" << std::endl;
                        return 0;
                    }
                    fib[i].n = j + 1;
                    fib[i].value[j] = res;
                }
            }
            // �����
            std::cout << "������ " << int(a) << " ����� ��������: ";
            for(int i = 0; i < a + 1; i++)
            {
                int n = fib[i].n;
                for(int j = n - 1; j > -1; j--)
                    std::cout << fib[i].value[j];
                std::cout << " ";
                // ������� ������
                delete fib[i].value;
            }
        }
    }
}

