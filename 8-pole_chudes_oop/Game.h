#ifndef GAME_H
#define GAME_H
#include "PoleChudes.h"

class Game
{
private:
    int m_reyting;
    PoleChudes m_game;
    std::string m_url_output;
public:

    Game();

    void start();

    void startGame();

    void endGame();

    ~Game() {};
};

#endif


