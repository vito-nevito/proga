#include<iostream>
#include<string>
#include <fstream>
#include "Pramoug.cpp"

main(void)
{
    Pramoug p(1, 2, 3, 4);
    std::string res;
    std::ifstream file("data.txt");
    double a[8];
    for(int i = 0; i < 8; i++)
    {
        std::string s;
        file >> s;
        a[i] = stof(s);
    }
    Pramoug p1(a[0], a[1], a[2], a[3]), p2(a[4], a[5], a[6], a[7]);
    std::cout << p1.compare(p2) << std::endl;
    file.close();
}
