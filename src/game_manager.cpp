#include "game_manager.h"
#include "resources.h"
#include <raylib.h>
GameManager::GameManager(){
    InitWindow(screenWidth, screenHeight, "Schrodinger's Tetris");
    InitAudioDevice();
    SetTargetFPS(60);
    res = new CommonRes();
    main_menu = new MENU();
    options_menu = new Options(main_menu->back(),&startingLevel,&music);
    score_menu = new Score(main_menu->back());
    game = new Game(main_menu->back(),&startingLevel,score_menu);
    SeekMusicStream(res->sound(), 25.0f);

}
void GameManager::run_game(){
    bool exitWindow=0;
    PlayMusicStream(res->sound());
    while (!WindowShouldClose() && !exitWindow) {
        if(music) UpdateMusicStream(res->sound());
        switch(main_menu->get_action()){
        case MenuAction::None:
                main_menu->display_menu();
            break;
        case MenuAction::Start:{
                game->run_game();
            break;}
        case MenuAction::Score:
                score_menu->display_scores();
            break;
        case MenuAction::Options:{
                options_menu->display_options();
            break;}
        case MenuAction::Exit:
                exitWindow=1;
            break;
        }
    }
}
GameManager::~GameManager(){
    delete game;
    delete main_menu;
    delete score_menu;
    delete options_menu;
    delete res;
    CloseAudioDevice();
    CloseWindow();
}
