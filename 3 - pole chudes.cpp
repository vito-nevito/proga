#include <iostream>
#include <string>
#include <windows.h>

int main()
{
    SetConsoleCP ( 1251 ) ;
    SetConsoleOutputCP ( 1251 ) ;
    std::string slovo;
    std::cout << "������� �����: ";
    std::cin >> slovo;
    std::string otvet(slovo.size(), '-');
    std::cout << otvet << std::endl;
    while(slovo != otvet)
    {
        char lit;
        std::cout << "������� �����: ";
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
            std::cout << "������� :)" << std::endl;
        else if(c == 2)
            std::cout << "����� ��� ���� :O" << std::endl;
        else
            std::cout << "��� ����� ����� :(" << std::endl;

        std::cout << std::endl << otvet << std::endl;
    }
    std::cout << "�� ������� ����� - " << slovo << "! ���������!"<< std::endl;
}
