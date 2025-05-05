#ifndef GAME_H
#define GAME_H
#include "grid.h"
#include "shapes.h"
#include "menu.h"
#include "resources.h"
#include <raylib.h>
class Game{
private:
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    const int BlockSize = 48;
    static const int NEXT_PIECES_COUNT = 3;
    int info[3] = {};
    Grid grid;
    Shape * current_piece;
    Shape * holding_piece;
    Shape * next_pieces_array[NEXT_PIECES_COUNT];
    MENU *main_menu;
    ResourceManager * res;
public:
    Game();
    void run_game();
    void game_inputs();
    void draw();
    void draw_info();
    void game_loop();
    Shape * create_a_random_piece();
    void drop_next_piece();
    void hold_piece();
    void update_next_pieces();
    ~Game();

};
#endif
