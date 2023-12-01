#include<iostream>
#include "Stack.h"
#include "Ochered.h"

int main()
{
    Stack S;
    S.push(3);
    std::cout << S.pop() << std::endl;
    // std::cout << S.pop() << std::endl;

    Ochered O{4, 9};
    std::cout << O.pop() << std::endl;
    std::cout << O.pop() << std::endl;
    std::cout << O.pop() << std::endl;
};
