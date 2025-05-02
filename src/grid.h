#ifndef GRID_H
#define GRID_H
#include <iostream>
#include "raylib.h"
using namespace std;
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

public:
    Grid(int * info);
    Cell ** getGrid();
    Cell& getGridBlock(int x, int y);
    int  getBlockSize();
    Cell * operator[](int x);
    bool is_line_full(int i);
    void delete_line(int i);
    Vector2 getBounds();

    ~Grid();

    void draw(Texture2D * block_textures);
};

#endif
