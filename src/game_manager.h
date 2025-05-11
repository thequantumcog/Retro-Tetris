#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "menu.h"
#include "resources.h"
#include "score.h"
#include "options.h"
#include <raylib.h>
#include "game.h"
class GameManager{
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    int startingLevel;
    bool music;
    MENU *main_menu;
    Game *game;
    Score *score_menu;
    Options* options_menu;
    ResourceManager * res;
public:
    GameManager();
    void game_loop();
    ~GameManager();
};
#endif
