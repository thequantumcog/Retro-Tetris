#ifndef OPTIONS_H
#define OPTIONS_H

#include "raylib.h"
#include "resources.h"
#include "helpers/widgets.cpp"

enum class Selected {LEVEL,MUSIC,BACK,SAVE,NONE};

class Options{
    OptionsRes * res;
    btn back_btn;
    btn save_btn;
    Toggle toggle_btn;
    Selected list;
    int * startingLevel;
    bool * music;
    bool Save=0;
    void draw();
    void handle_keyboard();
    void handle_mouse();
    void input();
    void logic();
    void Write();
    void reset_btns();
    void save_options();
public:
    Options(bool &gotoMenu, int * startingLevel, bool * music); 
    void LoadPrev();
    void di_options();
    ~Options();

};




#endif
