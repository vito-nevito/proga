#include<iostream>
#include<string>
#include <windows.h>
#include <fstream>
#include <ctime>

class correctCin
{
public:
    std::string corMenu()
    {
        std::string ans;
        int k = 0;
        while(!k)
        {
            k = 1;
            ans.clear();
            std::getline(std::cin, ans);
            if(std::strtol(ans.c_str(), NULL, 10) == 0)
            {
                std::cout << "Введите число\n";
                k = 0;
            }
            else if(stoi(ans) < 0 || stoi(ans) > 3)
            {
                std::cout << "Что-то пошло не так...\n";
                k =  0;
            }
        }
        return ans;
    }

    std::string corEnd()
    {
        std::string ans;
        int k = 0;
        while(!k)
        {
            k = 1;
            ans.clear();
            std::getline(std::cin, ans);
            if(ans != "y" && ans != "n")
            {
                std::cout << "Что-то пошло не так...\n";
                k =  0;
            }
        }
        return ans;
    }

    std::string corLet()
    {
        std::string ans;
        int k = 0;
        while(!k)
        {
            k = 1;
            std::cout << "Введите букву: ";
            ans.clear();
            std::getline(std::cin, ans);
            if(ans.size() > 1)
                k = 0;
            else if((ans < "A" || ans > "Z") & (ans < "a" || ans > "z"))
                k = 0;
            if(ans == "exit")
                k = 1;
        }
        return ans;
    }

    ~correctCin() {}
};

class Slovo
{
private:
    std::string m_slovo;          //само слово
    std::string m_mask;           //маска слова
    int m_lenth;                  //длина слова
public:
    void setSlovo(std::string a)
    {
        std::string S (a.size(), '-');
        m_slovo = a;
        m_mask = S;
        m_lenth = a.size();
    }

    void printMask()
    {
        std::cout << m_mask << "\n";
    }

    int openLet(std::string c)  // 0-не угадали 1-угадали 2-уже была
    {
        int k = 0;
        for(int i = 0; i < m_lenth; i++)
        {
            if(m_mask.substr(i, 1) == "-" & m_slovo.substr(i, 1) == c)
            {
                m_mask[i] = c.substr(0, 2)[0];
                k = 1;
            }
            else if(m_mask.substr(i, 1) == c)
            {
                return 2;
            }
        }
        return k;
    }

    bool proveritSlovo()
    {
        return (m_slovo == m_mask);
    }

    ~Slovo() {}
};

class PoleChudes
{
private:
    std::string m_url;        //ссылка на словарь
    int m_status;                //результат игры
    Slovo m_S;                //угадываемое слово
public:
    void createSlovo()
    {
        srand(time(NULL));
        std::ifstream file(m_url);
        std::string s;
        std::getline(file, s);
        int N = rand()%(std::stoi(s)) + 1;
        for(int i = 0; i < N; i++)
            std::getline(file, s);
        file.close();
        m_S.setSlovo(s);
        m_S.printMask();
    }

    void vvodLet()
    {
        correctCin _;
        std::string let = _.corLet();
        if(let == "exit")
            m_status = -1;
        else
        {
            int k = m_S.openLet(let);
            if(k == 0)
                std::cout << "Нет такой буквы :(" << "\n";
            else if(k == 1)
                std::cout << "Угадали :)" << "\n";
            else
                std::cout << "Буква уже была :O" << "\n";
            m_S.printMask();
        }
    }

    void setGame(std::string a)
    {
        m_status = 0;
        m_url = a;
    }

    bool notEnd()
    {
        if(m_S.proveritSlovo() || m_status == -1)
            return 0;
        return 1;
    }

    int getStatus()
    {
        return m_status;
    }

    ~PoleChudes() {}
};

class Game
{
private:
    int m_reyting;
    PoleChudes m_game;
public:

    Game()
    {
        m_reyting = 0;
    }

    void start()
    {
        std::cout << "Привет! Показать рейтинг(1), или начать игру(2)?" << std::endl;
        correctCin _;
        std::string ans = _.corMenu();
        if(stoi(ans) == 1)
            std::cout << "Сегодня вы сыграли " << m_reyting << " игр.\n"<< std::endl;
        else if(stoi(ans) == 2)
            startGame();
        endGame();
    }

    void startGame()
    {
        m_game.setGame("dict.txt");
        m_game.createSlovo();
        while(m_game.notEnd())
        {
            m_game.vvodLet();
        }
        if(m_game.getStatus() != -1)
                m_reyting ++;
    }

    void endGame()
    {
        correctCin _;
        std::cout << "Хотите продолжить?(y/n)" << std::endl;
        std::string ans =_.corEnd();
        if(ans == "n")
            std::cout << "До скорой встречи!" << std::endl;
        else
            start();
    }

    ~Game() {}
};

int main()
{
    SetConsoleCP (CP_UTF8);
    SetConsoleOutputCP (CP_UTF8);

    Game S;
    S.start();
}
