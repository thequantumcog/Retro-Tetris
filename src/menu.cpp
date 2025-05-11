#include "menu.h"
#include "resources.h"
#include <raylib.h>

MENU::MENU(){
    res = new MenuRes();
    menu_selection = MenuAction::Start;
}
void MENU::display_menu(){
    handle_inputs();
    draw_menu();
}
void MENU::draw_menu(){
    int offset = 63*(int)menu_selection;
    BeginDrawing();
    ClearBackground(BLACK);
    DrawTexture(res->Background(), 0, 0, WHITE);
    DrawTexture(res->Selector(), 790, 800+offset, WHITE);
    EndDrawing();
}
void MENU::handle_inputs(){
    if(IsKeyPressed(KEY_ENTER)){
        menu_open=0;
    }
    else if(IsKeyPressed(KEY_DOWN)){
        menu_selection = (MenuAction)(((int)menu_selection +1) % 4); //Convert to int and convert back
    }
    else if(IsKeyPressed(KEY_UP)){
        menu_selection = (MenuAction)(((int)menu_selection -1 + 4) % 4);
    }
}
void MENU::set_open(){
    menu_open=1;
}
MenuAction MENU::get_action() {
    if(menu_open)
        return MenuAction::None;
    return menu_selection;
}
bool& MENU::back(){
    return menu_open;
}
MENU::~MENU(){
    delete res;
}
