#ifndef GAMEOVER_H
#define GAMEOVER_H
#include "resources.h"
#include <raylib.h>
#include <string>
#include "helpers/widgets.cpp"
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
    btn back_btn;
    btn restart_btn;
    bool& ret, restart;

    bool isWhitespace(std::string);
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
