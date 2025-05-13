#ifndef TETRIS_H
#define  TETRIS_H
#include "grid.h"
#include "helpers/piece.cpp"
class Shape{
protected:
    Piece tetris;
    Grid& grid;
    int tetrimon_color;
    int xShift=5,yShift=0;
    int yShadow=0;
    static double gravitySpeed;
    bool dropped=0;
    Vector2 correction_values[2];
    static bool not_placeable;

public:
    Shape(Grid & g);
    void rotate();
    virtual Piece getNextOrient()=0;
    virtual ~Shape(){};
    bool move(int x, int y);
    void place();
    void erase_current();
    void move_down();
    void solidify();
    bool would_collide(Piece& cur_orient,int dx,int dy);
    void drop_piece(bool drop);
    void hard_drop();
    void set_speed(int level=1);
    // getters
    bool is_being_dropped();
    bool notPlaceable();
    void reset_gameOver();
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
