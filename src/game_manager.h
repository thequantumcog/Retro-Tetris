#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "menu.h"
#include "resources.h"
#include "score.h"
#include "options.h"
#include "game.h"
class GameManager{
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    int startingLevel;
    bool music=0;
    MENU *main_menu;
    Game *game;
    Score *score_menu;
    Options* options_menu;
    CommonRes * res;
public:
    GameManager();
    void run_game();
    ~GameManager();
};
#endif
