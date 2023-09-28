#include <iostream>
#include <string>
#include <windows.h>

int main()
{
    SetConsoleCP ( 1251 ) ;
    SetConsoleOutputCP ( 1251 ) ;
    std::string slovo;
    std::cout << "Введите слово: ";
    std::cin >> slovo;
    std::string otvet(slovo.size(), '-');
    std::cout << otvet << std::endl;
    while(slovo != otvet)
    {
        char lit;
        std::cout << "Введите букву: ";
        std::cin >> lit;
        std::cout << std::endl;
        int c = 0;
        for(int i = 0; i < slovo.size(); i++)
        {
            if(slovo[i] == lit)
            {
                if(otvet[i] == lit)
                    c = 2;
                else
                {
                    otvet[i] = lit;
                    c = 1;
                }
            }
        }
        if(c == 1)
            std::cout << "Угадали :)" << std::endl;
        else if(c == 2)
            std::cout << "Буква уже была :O" << std::endl;
        else
            std::cout << "Нет такой буквы :(" << std::endl;

        std::cout << std::endl << otvet << std::endl;
    }
    std::cout << "Вы угадали слово - " << slovo << "! Поздравяю!"<< std::endl;
}
