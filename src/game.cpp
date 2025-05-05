#include "game.h"
#include "menu.h"
#include "shapes.h"
#include <raylib.h>

Game::Game(): grid(info){
    InitWindow(screenWidth, screenHeight, "Schrodinger's Tetris");
    SetTargetFPS(60);
    res = new ResourceManager();
    main_menu = new MENU();

}
void Game::game_loop(){
    holding_piece = nullptr;
    current_piece = create_a_random_piece();
    for(int i=0;i<NEXT_PIECES_COUNT;i++) next_pieces_array[i] = create_a_random_piece();

    while (!WindowShouldClose() && !main_menu->exit_clicked()) {
        if(main_menu->is_open()) main_menu->display_menu();
        if(main_menu->start_clicked())   run_game();
    }
}
void Game::run_game(){
        if(grid.level_updates())
            current_piece->increase_speed();
        if(!current_piece->is_being_dropped()){
            drop_next_piece();
        }
        current_piece->move_down();
        game_inputs();
        draw();
}

void Game::game_inputs(){
    if( IsKeyPressed(KEY_DOWN) ||IsKeyPressedRepeat(KEY_DOWN) || IsKeyPressed(KEY_J))
        current_piece->move(0,1);
    else if( IsKeyPressed(KEY_RIGHT) || IsKeyPressedRepeat(KEY_RIGHT) || IsKeyPressed(KEY_L))
        current_piece->move(1,0);
    else if( IsKeyPressed(KEY_LEFT) || IsKeyPressedRepeat(KEY_LEFT)  || IsKeyPressed(KEY_H))
        current_piece->move(-1,0);
    else if(IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_K))
        current_piece->rotate();
    else if(IsKeyPressed(KEY_SPACE))
        current_piece->hard_drop();
    else if(IsKeyPressed(KEY_Z)){
            hold_piece();
    }
}

Shape * Game::create_a_random_piece(){
    int random = GetRandomValue(0, 6);
    Shape * new_piece = nullptr;
    switch(random){
        case 0:{new_piece = new Tetrimon_I(grid);}
            break;
        case 1:{new_piece = new Tetrimon_L(grid);}
            break;
        case 2:{new_piece = new Tetrimon_J(grid);}
            break;
        case 3:{new_piece = new Tetrimon_Z(grid);}
            break;
        case 4:{new_piece = new Tetrimon_T(grid);}
            break;
        case 5:{new_piece = new Tetrimon_S(grid);}
            break;
        case 6:{new_piece = new Tetrimon_O(grid);}
            break;
    }
    return new_piece;
    // return new Tetrimon_I(grid);
}
void Game::drop_next_piece(){
            if(current_piece) delete current_piece;
            current_piece = next_pieces_array[0];
            current_piece->drop_piece(1);
            update_next_pieces();
}
void Game::hold_piece(){
    if(current_piece->pos().y>=2) return;
    current_piece->erase_current();
    if(!holding_piece){
        holding_piece = current_piece;
        current_piece = next_pieces_array[0];
        update_next_pieces();
    }
    else{
        next_pieces_array[0] = current_piece;
        current_piece = holding_piece;
        holding_piece = nullptr;
    }
}
void Game::update_next_pieces(){
    next_pieces_array[0] = next_pieces_array[1];
    next_pieces_array[1] = next_pieces_array[2];
    next_pieces_array[2] = create_a_random_piece();
}
void Game::draw_info(){
        Vector2 abs_pos[4];
        abs_pos[0] = {1345 + next_pieces_array[0]->offset()[0].x , 150 + next_pieces_array[0] -> offset()[0].y};
        abs_pos[1] = {1345 + next_pieces_array[1]->offset()[1].x , 305 + next_pieces_array[1] -> offset()[1].y};
        abs_pos[2] = {1345 + next_pieces_array[2]->offset()[1].x , 405 + next_pieces_array[2] -> offset()[1].y};
        DrawTextureV(res->Next()[next_pieces_array[0]->getSpriteNo()],abs_pos[0],WHITE);
        DrawTextureV(res->Hold()[next_pieces_array[1]->getSpriteNo()],abs_pos[1],WHITE);
        DrawTextureV(res->Hold()[next_pieces_array[2]->getSpriteNo()],abs_pos[2],WHITE);
    if(holding_piece) {
        abs_pos[3] = {403+holding_piece->offset()[1].x, 155 + holding_piece->offset()[1].y};
        DrawTextureV(res->Hold()[holding_piece->getSpriteNo()],abs_pos[3], WHITE);
    }
    // Draw Texts
    Color DarkWhite = {219,219,219,255};
    DrawTextEx(res->font(), to_string(info[1]).c_str(),{1480,610}, 70,0,DarkWhite);
    DrawTextEx(res->font(), to_string(info[2]).c_str(),{1480,760}, 70,0,DarkWhite);
    DrawTextEx(res->font(), to_string(info[0]).c_str(),{1480,910}, 70,0,DarkWhite);
}
void Game::draw(){
    current_piece->draw();
    BeginDrawing();
    ClearBackground(WHITE);
    DrawTexture(res->Background(), 0, 0, WHITE);
    grid.draw(res->Blocks(),res->Shadow());
    draw_info();
    EndDrawing();
}
Game::~Game(){
    for(int i=0;i<NEXT_PIECES_COUNT;i++) if(next_pieces_array[i]) delete next_pieces_array[i];
    if (current_piece) delete current_piece;
    delete res;
    delete main_menu;
    CloseWindow();
}
