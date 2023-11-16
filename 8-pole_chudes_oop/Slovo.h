#ifndef SLOVO_H
#define SLOVO_H

#include<string>

class Slovo
{
private:
    std::string m_slovo;          //само слово
    std::string m_mask;           //маска слова
    int m_lenth;                  //длина слова
public:
    void setSlovo(std::string a);

    void printMask();

    int openLet(std::string c);

    bool proveritSlovo();

    ~Slovo() {};
};

#endif
