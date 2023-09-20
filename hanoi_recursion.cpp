#include<iostream>

void hanoi(int n, int kuda, int otkuda)
{
    if( n == 1)
        // ���� ������ ���������� ���� �����
        std::cout << otkuda << " -> " << kuda << std::endl;
    else
    {
        int drugoe = 6 - otkuda - kuda;
        // ���������� ����� ��� ������� ������ �� ���������
        hanoi(n - 1, drugoe, otkuda);
        // ���������� ������ ������ �� ��������� �����
        std::cout << otkuda << " -> " << kuda << std::endl;
        // ����� ���������� ������� �� ������ ������
        hanoi(n - 1, kuda, drugoe);
    }
}

int main()
{
    int N;
    std::cin >> N;
    hanoi(N, 3, 1);
}
