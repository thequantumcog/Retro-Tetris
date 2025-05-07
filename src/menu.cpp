#include "menu.h"
#include <raylib.h>

MENU::MENU(){
    menu[0] = LoadTexture("assets/menu.png"); 
    menu[1] = LoadTexture("assets/selector.png"); 
}
void MENU::display_menu(){
    handle_inputs();
    draw_menu();
}
void MENU::draw_menu(){
    int offset = 120*menu_selection;
    BeginDrawing();
    ClearBackground(BLACK);
    DrawTexture(menu[0], 0, 0, WHITE);
    DrawTexture(menu[1], 780, 835+offset, WHITE);
    EndDrawing();
}
void MENU::handle_inputs(){
    if(IsKeyPressed(KEY_ENTER)){
        switch(menu_selection){
            case 0:
                startGame=1;
            break;
            case 1:
                scoreMenu=1;
            break;
            case 2:
                options=1;
            break;
            case 3:
                Exit=1;
            break;
        }
        menu_open=0;
    }
    else if(IsKeyPressed(KEY_DOWN)){
        menu_selection = (menu_selection +1) % 4;
    }
    else if(IsKeyPressed(KEY_UP)){
        menu_selection = (menu_selection -1 + 4) % 4;
    }
}
bool MENU::start_clicked(){
    if(startGame)
        return 1;
    return 0;
}
bool MENU::score_clicked(){
    if(scoreMenu)
        return 1;
    return 0;
}
bool MENU::options_clicked(){
    if(options)
        return 1;
    return 0;
}
bool MENU::is_open(){
    if(menu_open)
        return 1;
    return 0;
}
void MENU::set_open(){
    menu_open=1;
    startGame=0,options=0,scoreMenu=0;
}
bool MENU::exit_clicked(){
    if(Exit)
        return 1;
    return 0;
}
MENU::~MENU(){
    for(int i=0;i<2;i++){
        UnloadTexture(menu[i]);
    }
}
