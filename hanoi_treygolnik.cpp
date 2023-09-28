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
    int c = -2 * (N % 2) + 1;
    // ��������� ������� � ������
    int i1 = 0;
    // ���������� �����
    std::stack<int> t[3];
    t[0].push(N + 1);
    for(int i = N; i > 0; i--)
        t[0].push(i);
    t[1].push(N + 1);
    t[2].push(N + 1);
    // � ����������� �� �������� N ���������� 1 �� ������������
    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 0)
        {
            // ������ ������ ��� ���������� 1 � ������ �����������
            t[(i1 + c + 3) % 3].push(1);
            t[i1].pop();
            std::cout << i1 + 1 << " -> " << (i1 + c + 3) % 3 + 1 << std::endl;
            i1 = (i1 + c + 3) % 3;
        }
        // �� �������� ���� �������� ��� ��� 1
        // � ������ ������������ ��������� ���
        else if(t[(i1 + 1) % 3].top() > t[(i1 + 2) % 3].top())
        {
            t[(i1 + 1) % 3].push(t[(i1 + 2) % 3].top());
            t[(i1 + 2) % 3].pop();
            std::cout << (i1 + 2) % 3 + 1 << " -> " << (i1 + 1) % 3 + 1<< std::endl;
        }
        else
        {
            t[(i1 + 2) % 3].push(t[(i1 + 1) % 3].top());
            t[(i1 + 1) % 3].pop();
            std::cout << (i1 + 1) % 3 + 1 << " -> " << (i1 + 2) % 3 + 1 << std::endl;
        }
    }
}

