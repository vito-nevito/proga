#include<iostream>
#include <stack>

// ���� � ������� ���
int pow_2(int n)
{
    int res = 1;
    for(int i = 0; i < n; i++)
    {
        res *= 2;
    }
    return res;
}

int main()
{
    int N;
    std::cin >> N;
    // ���������� �����
    int n = pow_2(N) - 1;
    int c = N % 2;
    // ���������� �����
    std::stack<int> t[3];
    t[0].push(N + 1);
    for(int i = N; i > 0; i--)
        t[0].push(i);
    t[1].push(N + 1);
    t[2].push(N + 1);
    // ������ ������ ��� ����� ���������� ������ �� ���� �����
    // ���� ������� �� �������� N
    for(int i = 0; i < n; i++)
    {
        // ������   1-2
        // �������� 1-3
        if(i % 3 == 0)
        {
            if(t[0].top() > t[1 + c].top())
            {
                t[0].push(t[1 + c].top());
                t[1 + c].pop();
                std::cout << "1 -> " << 2 + c << std::endl;
            }
            else
            {
                t[1 + c].push(t[0].top());
                t[0].pop();
                std::cout << "1 -> " << 2 + c << std::endl;
            }
        }
        else if(i % 3 == 1)
        {
            // ������   1-3
            // �������� 1-2
            if(t[0].top() > t[2 - c].top())
            {
                t[0].push(t[2 - c].top());
                t[2 - c].pop();
                std::cout << 3 - c << " -> 1" << std::endl;
            }
            else
            {
                t[2 - c].push(t[0].top());
                t[0].pop();
                std::cout << "1 -> " << 3 - c << std::endl;
            }
        }
        else
        {
            // ������ � �������� 2-3
            if(t[1].top() > t[2].top())
            {
                t[1].push(t[2].top());
                t[2].pop();
                std::cout << "3 -> 2" << std::endl;
            }
            else
            {
                t[2].push(t[1].top());
                t[1].pop();
                std::cout << "2 -> 3" << std::endl;
            }
        }
    }
}
