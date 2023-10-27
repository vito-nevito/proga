#include<iostream>
#include<string>
#include <windows.h>
#include <fstream>
#include <ctime>

std::string getNline(std::string u, int N)
{
    std::string res;
    std::ifstream file(u);
    for(int i = 0; i < N; i++)
        std::getline(file, res);
    file.close();
    return res;
}

class correctCin
{
private:
    std::string m_url;
public:
    correctCin(): m_url{"error.txt"}
    {};

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
                std::cout << getNline(m_url, 2) << std::endl;
                k = 0;
            }
            else if(stoi(ans) < 0 || stoi(ans) > 3)
            {
                std::cout << getNline(m_url, 1) << std::endl;
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
                std::cout << getNline(m_url, 1) << std::endl;
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
            std::cout << getNline(m_url, 3);
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
    std::string m_url_dict;           //ссылка на словарь
    std::string m_url_output;
    int m_status;                     //результат игры
    Slovo m_S;                        //угадываемое слово
public:
    void createSlovo()
    {
        srand(time(NULL));
        std::ifstream file(m_url_dict);
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
                std::cout << getNline(m_url_output, 1) << std::endl;
            else if(k == 1)
                std::cout << getNline(m_url_output, 2) << std::endl;
            else
                std::cout << getNline(m_url_output, 3) << std::endl;
            m_S.printMask();
        }
    }

    void setGame(std::string a)
    {
        m_status = 0;
        m_url_dict = a;
        m_url_output = "output.txt";
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
    std::string m_url_output;
public:

    Game(): m_reyting {0}, m_url_output {"output.txt"}
    {};

    void start()
    {
        std::cout << getNline(m_url_output, 4) << std::endl;
        correctCin _;
        std::string ans = _.corMenu();
        if(stoi(ans) == 1)
            std::cout << getNline(m_url_output, 5) << m_reyting << getNline(m_url_output, 6) << std::endl;
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
        std::cout << getNline(m_url_output, 7) << std::endl;
        std::string ans =_.corEnd();
        if(ans == "n")
            std::cout << getNline(m_url_output, 8) << std::endl;
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
