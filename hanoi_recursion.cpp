#include<iostream>

void hanoi(int n, int kuda, int otkuda)
{
    if( n == 1)
        // одно кольцо перемещаем куда нужно
        std::cout << otkuda << " -> " << kuda << std::endl;
    else
    {
        int drugoe = 6 - otkuda - kuda;
        // перемещаем башню без нижнего кольца на свободную
        hanoi(n - 1, drugoe, otkuda);
        // перемещаем нижнее кольцо на свободное место
        std::cout << otkuda << " -> " << kuda << std::endl;
        // снова перемещаем остаток на нижнее кольцо
        hanoi(n - 1, kuda, drugoe);
    }
}

int main()
{
    int N;
    std::cin >> N;
    hanoi(N, 3, 1);
}
