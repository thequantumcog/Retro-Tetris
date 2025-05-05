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
    Piece(Vector2 arr[4]){
        for(int i=0;i<TETROMINO_MAX_BLOCKS;i++){
            actual_piece[i] = arr[i];
        }
    }
    Piece(){}
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
    Piece tetris;
    Grid& grid;
    int tetrimon_color;
    //int preview_index;
    int xShift=0,yShift=0;
    int yShadow=0;
    int gravityCounter=0;
    static int gravitySpeed;
    bool dropped=0;
    Vector2 correction_values[2];

public:
    Shape(Grid & g);
    void rotate();
    virtual Piece getNextOrient()=0;
    virtual ~Shape(){};
    bool move(int x, int y);
    void draw();
    // void draw_shadow();
    void erase_current();
    void move_down();
    void solidify();
    bool would_collide(Piece& cur_orient,int dx,int dy);
    void drop_piece(bool drop);
    void hard_drop();
    void increase_speed();
    // getters
    bool is_being_dropped();
    Vector2 * offset();
    Vector2 pos();
    int getSpriteNo();
};
class Tetrimon_I: public Shape{
    int cur_rotation=0,max_rotations=4;
    Piece rotation[4];
public:
    Tetrimon_I(Grid& g);
    Piece getNextOrient() override;
};
class Tetrimon_L: public Shape{
    int cur_rotation=0,max_rotations=4;
    Piece rotation[4];
public:
    Tetrimon_L(Grid& g);
    Piece getNextOrient() override;

};
class Tetrimon_J: public Shape{
    int cur_rotation=0,max_rotations=4;
    Piece rotation[4];
public:
    Tetrimon_J(Grid& g);

    Piece getNextOrient() override;

};
class Tetrimon_Z: public Shape{
    int cur_rotation=0,max_rotations=4;
    Piece rotation[4];
public:
    Tetrimon_Z(Grid& g);
    Piece getNextOrient() override;
};
class Tetrimon_S: public Shape{
    int cur_rotation=0,max_rotations=4;
    Piece rotation[4];
public:
    Tetrimon_S(Grid& g);
    Piece getNextOrient() override;
};
class Tetrimon_T: public Shape{
    int cur_rotation=0,max_rotations=4;
    Piece rotation[4];
public:
    Tetrimon_T(Grid& g);
    Piece getNextOrient() override;
};
class Tetrimon_O: public Shape{
    Piece rotation[1];
public:
    Tetrimon_O(Grid& g);
    Piece getNextOrient() override;
};

#endif
