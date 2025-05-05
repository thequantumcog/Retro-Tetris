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
    int offset=0;
    if(menu_selection) offset = 120;
    else offset =0;
    BeginDrawing();
    ClearBackground(BLACK);
    DrawTexture(menu[0], 0, 0, WHITE);
    DrawTexture(menu[1], 780, 835+offset, WHITE);
    EndDrawing();
}
void MENU::handle_inputs(){
    if(IsKeyPressed(KEY_ENTER) && !menu_selection){
        startGame=1;
        menu_open=0;
    }
    else if(IsKeyPressed(KEY_ENTER)){
        Exit=1;
        menu_open=0;
        }
    else if(IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_UP)){
        menu_selection = !menu_selection;
    }
}
bool MENU::start_clicked(){
    if(startGame)
        return 1;
    return 0;
}
bool MENU::is_open(){
    if(menu_open)
        return 1;
    return 0;
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
