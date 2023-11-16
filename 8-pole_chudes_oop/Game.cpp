#include<iostream>
#include<string>
#include <windows.h>
#include <fstream>
#include <ctime>
#include "Game.h"
#include "correctCin.h"
#include "PoleChudes.h"

Game::Game(): m_reyting (0), m_url_output ("output.txt")
{};

void Game::start()
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

void Game::startGame()
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

void Game::endGame()
{
    correctCin _;
    std::cout << getNline(m_url_output, 7) << std::endl;
    std::string ans =_.corEnd();
    if(ans == "n")
        std::cout << getNline(m_url_output, 8) << std::endl;
    else
        start();
}


