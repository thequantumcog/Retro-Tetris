#ifndef GAMEOVER_H
#define GAMEOVER_H
#include "resources.h"
#include <raylib.h>
#include <string>
class GameOverScreen{
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    ResourceManager * res;
    std::string name = "";
    int backspaceHoldCounter = 0;
    int framesCounter = 0;
    bool mouseOnText = false;
    Rectangle textBox = { screenWidth/2.0f - 150, screenHeight/2.0f-100, 300, 50 };
    bool gameOver=0;;
    bool isWhitespace(std::string);
public:
    GameOverScreen(ResourceManager * res);
    void getInput();
    void draw();
    bool isGameOver();
    void set_GameOver(bool);

    

};
#endif
