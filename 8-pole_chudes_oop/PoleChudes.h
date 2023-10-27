#ifndef POLECHUDES_H
#define POLECHUDES_H

#include "Slovo.h"

class PoleChudes
{
private:
    std::string m_url_dict;           //ссылка на словарь
    std::string m_url_output;
    int m_status;                     //результат игры
    Slovo m_S;                        //угадываемое слово
public:
    void createSlovo();

    void vvodLet();

    void setGame(std::string a);

    bool notEnd();

    int getStatus();

    ~PoleChudes() {};
};

#endif

