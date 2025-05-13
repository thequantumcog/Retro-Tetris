#ifndef GRID_H
#define GRID_H
#include "raylib.h"

class Cell{
    int color;
    int state=0;
public:
    Cell(){
        state=0;
    }
    void set(int s,int col){
        color = col;
        state =s;
    }
    int value(){
        return state;
    }
    int getColor(){
        return color;
    }
    void set_cell(int s){
        state =s;
    }
};
class Grid {
    int rows, cols;
    int BlockSize;
    Cell ** actual_grid;
    int& game_score;
    int& lines_completed;
    int& level;
    int level_threshold;

    bool is_line_full(int i);
    void delete_line(int i);
public:
    Grid(int * info);
    void Reset();
    int  getBlockSize();
    Cell * operator[](int x);
    Vector2 getBounds();
    bool level_updates();
    bool is_game_over();

    ~Grid();

    void draw(Texture2D * block_textures, Texture2D * shadow_textures);
};

#endif
