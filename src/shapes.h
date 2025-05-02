#ifndef TETRIS_H
#define  TETRIS_H
#include <iostream>
#include <raylib.h>
#include "grid.h"
using namespace std;
const int TETROMINO_MAX_BLOCKS =4;
class Shape{
protected:
    Vector2 tetris[4];
    Grid& grid;
    int tetrimon_color;
    int preview_index;
    int xShift=0,yShift=0;
    int gravityCounter=0;
    int gravitySpeed=30;
    bool dropped=0;
    Vector2 correction_values[2];

public:
    //TODO: FIX THIS MESS
    Shape(Grid & g);
    void rotate();
    bool move(int x, int y);
    void draw();
    void erase_current();
    void move_down();
    void solidify();
    bool would_collide(Vector2 * tetris,int dx,int dy);
    bool is_being_dropped();
    void drop_piece(bool drop);
    void hard_drop();
    void increase_speed();
    Vector2 * offset();
    // gets current position
    Vector2 pos();
    // gets index of texture
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
