#ifndef GAME_H
#define GAME_H
#include "grid.h"
#include "resources.h"
#include "tetrimons.h"
#include "game_over.h"
#include "score.h"
class Game{
private:
    static const int NEXT_PIECES_COUNT = 3;
    int* startingLevel;
    int info[3] = {};
    Grid grid;
    GameRes * res;
    Shape * current_piece;
    Shape * holding_piece;
    Shape * next_pieces_array[NEXT_PIECES_COUNT];
    Score * score_list;
    GameOverScreen *gameover_screen;
    bool& backtomenu;
    bool initializationDone=0;
    bool restart=0, ret=0;
    bool nameEntered=0;

    void do_initialization();
    void game_inputs();
    void handle_inputs();
    void draw();
    void draw_info();
    Shape * create_a_random_piece();
    void drop_next_piece();
    void hold_piece();
    void update_next_pieces();
    void reset_after_gameOver();
public:
    Game(bool& Menu, int * StartingLevel, Score * score_list);
    void run_game();
    ~Game();

};
#endif
