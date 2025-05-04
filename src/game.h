#ifndef GAME_H
#define GAME_H
#include "grid.h"
#include "shapes.h"
#include <raylib.h>
class Game{
private:
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    const int BlockSize = 48;
    static const int SPRTIE_COUNT = 14;
    static const int NEXT_PIECES_COUNT = 3;
    int info[3] = {};
    Grid grid;
    Shape * current_piece;
    Shape * holding_piece;
    Shape * next_pieces_array[NEXT_PIECES_COUNT];
    Texture2D block_textures[SPRTIE_COUNT]; 
    Texture2D hold_textures[7]; 
    Texture2D next_textures[7]; 
    Texture2D shadow_textures[7]; 
    Texture2D background;
    Font my_font;
    bool startGame;
    //MENU
    Texture2D menu[2];
    bool menu_selection=0;
    bool Exit =0;
public:
    Game();
    void run_game();
    void game_inputs();
    void draw();
    void draw_info();
    void game_loop();
    Shape * create_a_random_piece();
    void drop_next_piece();
    void load_textures();
    void unload_textures();
    void hold_piece();
    void update_next_pieces();
    ~Game();
    // Menu Stuff
    void game_menu();
    void menu_inputs();

};
#endif
