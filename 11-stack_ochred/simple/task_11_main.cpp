#include<iostream>
#include "Stack.h"
#include "Ochered.h"

int main()
{
    Stack S{2, 3};
    S.push(3);
    std::cout << S.pop() << std::endl;
    std::cout << S.pop() << std::endl;

    Ochered O;
    O.push(4);
    O.push(9);
    std::cout << O.pop() << std::endl;
    std::cout << O.pop() << std::endl;
    std::cout << O.pop() << std::endl;
};
