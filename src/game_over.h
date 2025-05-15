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
    void mouseinput();
    void keyboardinput();
public:
    GameOverScreen(bool& gotoMenu, bool& reset);
    ~GameOverScreen();
    std::string handle_textbox();
    void draw();
    bool isGameOver();
    bool operator!();
    void set(bool);
    void input();
    void resetbtns();

};
#endif
