#ifndef RES_H
#define RES_H
#include "raylib.h"
class CommonRes{
private:
    Texture2D back;
    Font my_font;
    Music theme;
public:
    CommonRes();
    ~CommonRes();
    Texture2D&  Back();
    Font&  font();
    Music& sound();
};
class GameRes: public CommonRes{
    static const int SPRTIE_COUNT = 14;
    Texture2D block_textures[SPRTIE_COUNT]; 
    Texture2D hold_textures[7]; 
    Texture2D next_textures[7]; 
    Texture2D shadow_textures[7]; 
    Texture2D game_background;
public:
    GameRes();
    ~GameRes();
    Texture2D * Blocks();
    Texture2D * Hold();
    Texture2D * Next();
    Texture2D * Shadow();
    Texture2D&  Game_Background();
};
class GameOverRes: public CommonRes{
    Texture2D game_over;
    Texture2D restart;
public:
    GameOverRes();
    ~GameOverRes();
    Texture2D&  GameOver();
    Texture2D&  Restart();
};
class OptionsRes: public CommonRes{
    Texture2D background;
    Texture2D level;
    Texture2D toggle;
    Texture2D selector;
    Texture2D selection;
    Texture2D save;
public:
    OptionsRes();
    ~OptionsRes();
    Texture2D&  Background();
    Texture2D&  Level();
    Texture2D&  Toggle();
    Texture2D&  Selector();
    Texture2D&  Save();
    Texture2D&  Selection();
};
class ScoreRes: public CommonRes{
    Texture2D background;
    public:
    ScoreRes();
    ~ScoreRes();
    Texture2D&  Background();
    Texture2D&  Back();
};
class MenuRes: public CommonRes{
    Texture2D menu[2];
    public:
    MenuRes();
    ~MenuRes();
    Texture2D&  Background();
    Texture2D&  Selector();
};
#endif
