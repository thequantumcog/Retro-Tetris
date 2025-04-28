#ifndef TETRIS_H
#define  TETRIS_H
#include <iostream>
#include <raylib.h>
#include "grid.h"
using namespace std;
const int TETRIMON_MAX_BLOCKS =4;
class Shape{
protected:
    Vector2 tetris[4];
    Grid * grid;
    Color tetrimon_color;
    int xShift=0,yShift=0;
    int gravityCounter=0;
    int gravitySpeed=30;
    bool dropped=0;

    void clear_previous();
    int getMax(bool);
    int getMinX();
public:
    //TODO: FIX THIS MESS
    Shape(Grid * g);
    void rotate();
    void move(int x, int y);
    void draw();
    void drop();
    void make_solid();
//    bool check_collision_Y();
    bool check_collision_X();
    bool would_collide(Vector2 * tetris,int dx,int dy);
    void setDrop(bool drop){
        dropped = drop;
    }
    bool getDrop(){
        return dropped;
    }
};
class Tetrimon_I: public Shape{
public:
    Tetrimon_I(Grid * g);
};
class Tetrimon_L: public Shape{
public:
    Tetrimon_L(Grid * g);

};
class Tetrimon_J: public Shape{
public:
    Tetrimon_J(Grid * g);

};
class Tetrimon_Z: public Shape{
public:
    Tetrimon_Z(Grid * g);
};
class Tetrimon_S: public Shape{
public:
    Tetrimon_S(Grid * g);
};
class Tetrimon_T: public Shape{
public:
    Tetrimon_T(Grid * g);
};
class Tetrimon_O: public Shape{
public:
    Tetrimon_O(Grid * g);
};

#endif
