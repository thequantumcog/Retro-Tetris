#ifndef GAMEOVER_H
#define GAMEOVER_H
#include "resources.h"
#include <raylib.h>
#include <string>
#include "options.h"
class GameOverScreen{
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    GameOverRes * res;
    std::string name = "";
    int backspaceHoldCounter = 0;
    int framesCounter = 0;
    bool mouseOnText = false;
    Rectangle textBox ;
    bool gameOver=0;;
    bool isWhitespace(std::string);
    btn back_btn;
    btn restart_btn;

public:
    GameOverScreen(bool& gotoMenu, bool& reset);
    ~GameOverScreen();
    std::string getInput();
    void draw();
    bool isGameOver();
    void set_GameOver(bool);
    void mouseinput();
    void resetbtns();

    

};
#endif
