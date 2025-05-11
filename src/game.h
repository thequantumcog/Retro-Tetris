#ifndef GAME_H
#define GAME_H
#include "grid.h"
#include "resources.h"
#include "tetrimons.h"
#include "game_over.h"
#include <raylib.h>
class Game{
private:
    static const int NEXT_PIECES_COUNT = 3;
    int *startingLevel;
    int info[3] = {};
    Grid grid;
    Shape * current_piece;
    Shape * holding_piece;
    Shape * next_pieces_array[NEXT_PIECES_COUNT];
    GameOverScreen *gameover_screen;
    ResourceManager * res;
    bool& backtomenu;
    bool initializationDone=0;

    void game_inputs();
    void handle_inputs();
    void draw();
    void draw_info();
    Shape * create_a_random_piece();
    void drop_next_piece();
    void hold_piece();
    void update_next_pieces();
    void reset_after_gameOver();
    // void do_if_gameOver();
public:
    Game(ResourceManager * res,bool& Menu, int * StartingLevel);
    void run_game();
    ~Game();

};
#endif
