#include<iostream>
#include "CRational.h"

int main()
{
    CRational a = CRational(3, 1);
    CRational b = CRational(5, 4);
    CRational c = a+b;
    CRational d = CRational(0.4);
    c.print();
    std::cout << std::endl;
    a.print();
    std::cout << std::endl;
    d.print();
    return 0;
}
