#include<iostream>
#include <cmath>

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
        else if(a < 0)
        {
            std::cout << "��������� ����� ������ 0" << std::endl;
            a = 0;
        }
        else if(int(a) != a)
        {
            std::cout << "��������� ����� �������" << std::endl;
            a = 0;
        }
        else if(a > 100000)
        {
            std::cout << "��������� ����� ������ 100 000" << std::endl;
            a = 0;
        }
        else
        {
            int* fact = (int*)calloc(1, sizeof(int));
            fact[0] = 1;
            int zeros_5 = 0;
            // ������� ���������� ����� � ����������
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
                // ������� �� ����� ������ ���������(5 � 2)
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
                // �������� �� ���������� ��������� ����������
                for(unsigned long int j = 0; j < n; j++)
                {
                    unsigned long int temp = (fact[j] * k + res);
                    fact[j] = temp % 10;
                    res = temp / 10;
                }
                // ������ �������
                while(res > 0)
                {
                    n += 1;
                    fact = (int*)std::realloc(fact, n*sizeof(int));
                    if (fact == NULL)
                    {
                        std::cout << "������ ��������� ������" << std::endl;
                        return 0;
                    }
                    fact[n-1] = res % 10;
                    res /= 10;
                }
            }
            unsigned long int num_count[10] {0};
            // �����
            for(long int i = n - 1; i >= 0; i--)
            {
                std::cout << fact[i];
                num_count[fact[i]] += 1;
            }
            // ��������� ��������� ����
            /*
            num_count[0] += zeros_5;
            n += zeros_5;
            */
            for(long int i = 0; i < zeros_5; i++)
                std::cout << 0;
            std::cout << std::endl << std::endl;
            // ������������� ���� � ����������
            std::cout << "������������� ���� � ����������: " << int(a) << "!" << std::endl;
            for(int i = 0; i < 10; i++)
                std::cout << i << ": "<< std::round(num_count[i] * 1000 / n) / 10. << " %" << std::endl;
            // ������� ������
            delete fact;
        }
    }
}
