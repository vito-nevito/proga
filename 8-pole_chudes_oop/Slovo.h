#ifndef SLOVO_H
#define SLOVO_H

#include<string>

class Slovo
{
private:
    std::string m_slovo;          //���� �����
    std::string m_mask;           //����� �����
    int m_lenth;                  //����� �����
public:
    void setSlovo(std::string a);

    void printMask();

    int openLet(std::string c);

    bool proveritSlovo();

    ~Slovo() {};
};

#endif
