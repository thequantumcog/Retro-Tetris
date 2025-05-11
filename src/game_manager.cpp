#include "game_manager.h"
GameManager::GameManager(){
    InitWindow(screenWidth, screenHeight, "Schrodinger's Tetris");
    SetTargetFPS(60);
    res = new ResourceManager();
    main_menu = new MENU();
    options_menu = new Options(res,main_menu->back(),&startingLevel,&music);
    game = new Game(res,main_menu->back(),&startingLevel);
    score_menu = new Score(res,main_menu->back());

}
void GameManager::game_loop(){
    bool exitWindow=0;
    while (!WindowShouldClose() && !exitWindow) {
        switch(main_menu->get_action()){
        case MenuAction::None:
                main_menu->display_menu();
            break;
        case MenuAction::Start:{
                game->run_game();
            break;}
        case MenuAction::Score:
                score_menu->di_scores();
            break;
        case MenuAction::Options:{
                options_menu->di_options();
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
    CloseWindow();
}
