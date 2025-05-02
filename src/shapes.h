#ifndef TETRIS_H
#define  TETRIS_H
#include <iostream>
#include <raylib.h>
#include "grid.h"
using namespace std;
const int TETROMINO_MAX_BLOCKS =4;
class Piece{
private:
    Vector2 actual_piece[4];
public:
    Vector2& operator[](int i){
        return actual_piece[i];
    }
    void operator=(Vector2 arr[4]){
        for(int i=0;i<TETROMINO_MAX_BLOCKS;i++){
            actual_piece[i] = arr[i];
        }
    }
};
class Shape{
protected:
    Piece tetris[4];
    int cur_rotation,max_rotations;
    Grid& grid;
    int tetrimon_color;
    int preview_index;
    int xShift=0,yShift=0;
    int gravityCounter=0;
    static int gravitySpeed;
    bool dropped=0;
    Vector2 correction_values[2];

public:
    Shape(Grid & g);
    void rotate();
    bool move(int x, int y);
    void draw_on_grid();
    void erase_current();
    void move_down();
    void solidify();
    bool would_collide(Piece& cur_orient,int dx,int dy);
    bool is_being_dropped();
    void drop_piece(bool drop);
    void hard_drop();
    void increase_speed();
    // getters
    Vector2 * offset();
    Vector2 pos();
    int getSpriteNo();
};
class Tetrimon_I: public Shape{
public:
    Tetrimon_I(Grid& g);
};
class Tetrimon_L: public Shape{
public:
    Tetrimon_L(Grid& g);

};
class Tetrimon_J: public Shape{
public:
    Tetrimon_J(Grid& g);

};
class Tetrimon_Z: public Shape{
public:
    Tetrimon_Z(Grid& g);
};
class Tetrimon_S: public Shape{
public:
    Tetrimon_S(Grid& g);
};
class Tetrimon_T: public Shape{
public:
    Tetrimon_T(Grid& g);
};
class Tetrimon_O: public Shape{
public:
    Tetrimon_O(Grid& g);
};

#endif
