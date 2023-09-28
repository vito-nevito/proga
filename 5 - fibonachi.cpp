#include<iostream>
#include <cmath>

struct very_long_int
{
    int* value = (int*)malloc(sizeof(int));
    int n = 1;
};

very_long_int slogit(very_long_int a, very_long_int b)
{
    int res = 0;
    very_long_int ans;
    int n1 = a.n;
    int n2 = b.n;
    int j;
    // ���������� ���������� � ������� ������
    for(j = 0; j < n1; j++)
    {
        int temp = (a.value[j]  + b.value[j] + res);
        ans.value = (int*)realloc(ans.value, (j + 1)*sizeof(int));
        ans.n = j + 1;
        if(ans.value == NULL)
        {
            std::cout << "������ ��������� ������" << std::endl;
        }
        ans.value[j] = temp % 10;
        res = temp / 10;
    }
    // ���������� ���������� ������� ��������
    for(j; j < n2; j++)
    {
        int temp = (b.value[j] + res);
        ans.value = (int*)realloc(ans.value, (j + 1)*sizeof(int));
        if(ans.value == NULL)
        {
            std::cout << "������ ��������� ������" << std::endl;
        }
        ans.n = j + 1;
        ans.value[j] = temp % 10;
        res = temp / 10;
    }
    // ���������� ������� ���� �����
    if(res)
    {
        ans.value = (int*)realloc(ans.value, (j + 1)*sizeof(int));
        if(ans.value == NULL)
        {
            std::cout << "������ ��������� ������" << std::endl;
        }
        ans.n = j + 1;
        ans.value[j] = res;
    }
    return ans;
}

very_long_int fibonachi(int N, very_long_int* c)
{
    if(N == 0)
    {
        c[0].value[0] = 0;
        return c[0];
    }
    if(N == 1)
    {
        c[1].value[0] = 1;
        return c[1];
    }
    if(c[N - 1].n == 1)
        c[N - 1] = fibonachi(N - 1, c);
    if(c[N - 2].n == 1)
        c[N - 2] = fibonachi(N - 2, c);
    c[N] = slogit(c[N - 2], c[N - 1]);
    return c[N];
}


int main()
{
    setlocale(LC_ALL, "Russian");
    double a = 0;
    std::cout << "������� �����: ";
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
            struct very_long_int c[int(a + 1)];
            std::cout << "������ " << int(a) << " ����� ��������: ";
            struct very_long_int der = fibonachi(int(a), c);
            for(int i = 0; i < int(a) + 1; i++)
            {
                int n = c[i].n;
                for(int j = n - 1; j > -1; j--)
                    std::cout << c[i].value[j];
                std::cout << " ";
                // ������� ������
                delete c[i].value;
            }
            std::cout << std::endl;
            std::cout << std::endl;
            struct very_long_int fib[int(a + 1)];
            // ������ ������ ��� �����
            fib[0].value[0] = 0;
            fib[1].value[0] = 1;
            for(int i = 2; i < a + 1; i++)
            {
                fib[i] = slogit(fib[i - 2], fib[i - 1]);
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

