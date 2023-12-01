#include<iostream>
#include "Spisok.h"
#include "Ochered.h"
#include "Stack.h"



int main()
{
    Stack S{2, 4};
    S.push(3);
    std::cout << S.pop() << std::endl;
    std::cout << S.pop() << std::endl;

    Ochered O{1, 2};
    O.push(4);
    O.push(9);
    std::cout << O.pop() << std::endl;
    std::cout << O.pop() << std::endl;
    std::cout << O.pop() << std::endl;

    Spisok T{2, 4};
    std::cout << T.pop() << std::endl;
};
