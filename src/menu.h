#ifndef MENU_H
#define MENU_H
#include "raylib.h"
#include "resources.h"

enum class MenuAction {Start, Score, Options, Exit,None}; 
class MENU{
private:
    MenuRes* res;
    bool menu_open=1;
    MenuAction menu_selection;
    void draw_menu();
    void handle_inputs();
public:
    MENU();
    ~MENU();
    MenuAction get_action();
    void set_open();
    void display_menu();
    bool& back();

};


#endif
