#include <windows.h>
#include "Game.h"

int main()
{
    SetConsoleCP (CP_UTF8);
    SetConsoleOutputCP (CP_UTF8);

    Game S;
    S.start();
}
