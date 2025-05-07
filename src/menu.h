#ifndef MENU_H
#define MENU_H
#include "raylib.h"

class MENU{
private:
    Texture2D menu[2];
    int menu_selection=0;
    bool Exit =0;
    bool startGame=0;
    bool scoreMenu=0;
    bool options=0;
    bool menu_open=1;
    void draw_menu();
    void handle_inputs();
public:
    MENU();
    ~MENU();
    bool start_clicked();
    bool score_clicked();
    bool options_clicked();
    bool exit_clicked();
    bool is_open();
    void set_open();
    void display_menu();

};


#endif
