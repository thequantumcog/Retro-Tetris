#include "game.h"
#include <raylib.h>
void Game::game_menu(){
    int offset=0;
    menu_inputs();
    if(menu_selection) offset = 120;
    else offset =0;
    BeginDrawing();
    ClearBackground(BLACK);
    DrawTexture(menu[0], 0, 0, WHITE);
    DrawTexture(menu[1], 780, 835+offset, WHITE);
    EndDrawing();
}
void Game::menu_inputs(){
    if(IsKeyPressed(KEY_ENTER) && !menu_selection)
        startGame=1;
    else if(IsKeyPressed(KEY_ENTER)){
        Exit=1;
        }
    else if(IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_UP)){
        menu_selection = !menu_selection;
    }

}
