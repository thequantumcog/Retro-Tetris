#include "tetrimons.h"
#include <raylib.h>
using namespace std;

int Shape::gravitySpeed = 30;
bool Shape::not_placeable=0;

void Shape::erase_current(){
    // erase block
    for(int i=0;i<TETROMINO_MAX_BLOCKS;i++){
        grid[tetris[i].y + yShift][(int)tetris[i].x + xShift].set_cell(0);
    }
    // erase shadow
    for(int i=0;i<TETROMINO_MAX_BLOCKS;i++){
        if(grid[tetris[i].y + yShadow + yShift][(int)tetris[i].x+xShift].value() != 2)
            grid[tetris[i].y + yShadow + yShift][(int)tetris[i].x+xShift].set_cell(0);
    }
}

// Public Functions
Shape::Shape(Grid & g): grid(g){
    correction_values[0] = {0,0};
    correction_values[1] = {0,0};
}

void Shape::place(){
    if(dropped){
        yShadow=0;
        while(!would_collide(tetris,0,yShadow+1))
            yShadow +=1;
        for(int i=0;i<TETROMINO_MAX_BLOCKS;i++){
            if(grid[(int)tetris[i].y + yShadow + yShift][(int)tetris[i].x+xShift].value() ==0 )
                grid[(int)tetris[i].y + yShadow + yShift][(int)tetris[i].x+xShift].set(3,tetrimon_color);
        }

        for(int i=0;i<TETROMINO_MAX_BLOCKS;i++){
            if(grid[tetris[i].y + yShift][(int)tetris[i].x + xShift].value() == 2)
                not_placeable=1;
            grid[tetris[i].y + yShift][(int)tetris[i].x + xShift].set(1,tetrimon_color);
        }
    }
}
bool Shape::would_collide(Piece& cur_orient,int inc_x=0, int inc_y=0){
    for (int i = 0; i < TETROMINO_MAX_BLOCKS; i++) {
        int goto_x = xShift + cur_orient[i].x + inc_x;
        int goto_y = yShift + cur_orient[i].y + inc_y;

        if (goto_x < 0 || goto_x >= grid.getBounds().x || goto_y < 0 || goto_y >= grid.getBounds().y) return true;
        if (grid[goto_y][goto_x].value() == 2) return true;
    }
    return false;
}

bool Shape::move(int inc_x, int inc_y){
    if (!dropped) return 0;
    if (!would_collide(tetris,inc_x, inc_y)) {
        erase_current();  
        xShift += inc_x;
        yShift += inc_y;
        if(inc_y) yShadow -=inc_y;
        return 1;
    }
    // agar block neeche jaane ki koshish kar raha hai
    else if (inc_y>0){
        erase_current();  
        solidify();
    }
    return 0;
}
void Shape::rotate(){
    Piece temp = getNextOrient();
    if (would_collide(temp)) return;
    erase_current();
    tetris = temp;
}
// void Shape::draw_shadow(){
//     // for(int i=0;i<TETROMINO_MAX_BLOCKS;i++){
//     //     if(grid[(int)tetris[i].y + yShadow + yShift][(int)tetris[i].x].value() == 3 )
//     //         grid[(int)tetris[i].y + yShadow + yShift][(int)tetris[i].x + xShift].set_cell(0);
//     // }
// }
void Shape::increase_speed(){
    gravitySpeed -=5;
}
void Shape::move_down(){
    if(dropped){
        gravityCounter++;
        if(gravityCounter > gravitySpeed){
            erase_current();
            if(!would_collide(tetris,0, 1)) yShift++,yShadow--;
            else solidify();
            gravityCounter=0;
        }
    }
}
void Shape::hard_drop(){
    bool possible_to_move_down=1;
    while(possible_to_move_down){
        possible_to_move_down=move(0,1);
    }
}
void Shape::solidify(){
    for(int i=0;i<TETROMINO_MAX_BLOCKS;i++){
        int abs_y = yShift + tetris[i].y, abs_x = xShift+tetris[i].x;
        grid[abs_y][abs_x].set(2,tetrimon_color+1); // +1 basically means to add borders
    }
    dropped=0;
}
void Shape::drop_piece(bool drop){
    dropped = drop;
}
bool Shape::is_being_dropped(){
    return dropped;
}
Vector2 Shape::pos(){
    return {(float)xShift,(float)yShift};
}
int Shape::getSpriteNo(){
    return tetrimon_color/2;
}
Vector2 * Shape::offset(){
    return correction_values;
}
bool Shape::notPlaceable(){
    if(not_placeable)
        return 1;
    return 0;
}
void Shape::reset_gameOver(){
    not_placeable=0;
}
Tetrimon_I::Tetrimon_I(Grid & g): Shape(g){
    tetrimon_color = 0;
//    preview_index=0;
    correction_values[0]={-30,20};
    correction_values[1] = {-15,23};
    rotation[0] = (Vector2[]){{1, 0}, {1, 1}, {1, 2},{1, 3}};
    rotation[1] = (Vector2[]){{0, 2}, {1, 2}, {2, 2},{3, 2}};
    rotation[2] = (Vector2[]){{2, 0}, {2, 1}, {2, 2},{2, 3}};
    rotation[3] = (Vector2[]){{0, 1}, {1, 1}, {2, 1},{3, 1}};
    tetris = rotation[cur_rotation];
}
Tetrimon_J::Tetrimon_J(Grid & g): Shape(g){
    tetrimon_color = 2;
  //  preview_index=1;

    rotation[0] = (Vector2[]){{0, 2}, {1, 0}, {1, 1}, {1, 2}};
    rotation[1] = (Vector2[]){{0, 1}, {1, 1}, {2, 1}, {2, 2}};
    rotation[2] = (Vector2[]){{1, 0}, {1, 1}, {1, 2}, {2, 0}};
    rotation[3] = (Vector2[]){{0, 0}, {0, 1}, {1, 1}, {2, 1}};
    tetris = rotation[cur_rotation];

} 
Tetrimon_L::Tetrimon_L(Grid & g): Shape(g){
    tetrimon_color = 4;
    //preview_index=2;

    rotation[0] = (Vector2[]){{0, 0}, {1, 0}, {1, 1},{1, 2}};
    rotation[1] = (Vector2[]){{0, 1}, {0, 2}, {1, 1},{2, 1}};
    rotation[2] = (Vector2[]){{1, 0}, {1, 1}, {1, 2},{2, 2}};
    rotation[3] = (Vector2[]){{0, 1}, {1, 1}, {2, 0},{2, 1}};
    tetris = rotation[cur_rotation];
} 

Tetrimon_O::Tetrimon_O(Grid & g): Shape(g){
    tetrimon_color = 6;
    //preview_index=3;
    correction_values[0] = {20,10};
    correction_values[1] = {17,5};
    rotation[0] = (Vector2[]){{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    tetris = rotation[0];
} 

Tetrimon_S::Tetrimon_S(Grid & g): Shape(g){
    tetrimon_color = 8;
    //preview_index=4;
    rotation[0] = (Vector2[]){{0, 0}, {0, 1}, {1, 1}, {1, 2}};
    rotation[1] = (Vector2[]){{0, 2}, {1, 1}, {1, 2}, {2, 1}};
    rotation[2] = (Vector2[]){{1, 0}, {1, 1}, {2, 1}, {2, 2}};
    rotation[3] = (Vector2[]){{0, 1}, {1, 0}, {1, 1}, {2, 0}};
    tetris = rotation[cur_rotation];
} 
Tetrimon_T::Tetrimon_T(Grid & g): Shape(g){
    tetrimon_color =  10;
    //preview_index=5;
    rotation[0] = (Vector2[]){{0, 1}, {1, 0}, {1, 1}, {1, 2}};
    rotation[1] = (Vector2[]){{0, 1}, {1, 1}, {1, 2}, {2, 1}};
    rotation[2] = (Vector2[]){{1, 0}, {1, 1}, {1, 2}, {2, 1}};
    rotation[3] = (Vector2[]){{0, 1}, {1, 0}, {1, 1}, {2, 1}};
    tetris = rotation[cur_rotation];
} 

Tetrimon_Z::Tetrimon_Z(Grid & g): Shape(g){
    tetrimon_color = 12;
    //preview_index=6;
    rotation[0] = (Vector2[]){{0, 1}, {0, 2}, {1, 0}, {1, 1}};
    rotation[1] = (Vector2[]){{0, 1}, {1, 1}, {1, 2}, {2, 2}};
    rotation[2] = (Vector2[]){{1, 1}, {1, 2}, {2, 0}, {2, 1}};
    rotation[3] = (Vector2[]){{0, 0}, {1, 0}, {1, 1}, {2, 1}};
    tetris = rotation[cur_rotation];
} 
Piece Tetrimon_I::getNextOrient(){
    cur_rotation = (cur_rotation +1 ) % max_rotations;
    return Piece(rotation[cur_rotation]);
}
Piece Tetrimon_J::getNextOrient(){
    cur_rotation = (cur_rotation +1 ) % max_rotations;
    return Piece(rotation[cur_rotation]);
}
Piece Tetrimon_L::getNextOrient(){
    cur_rotation = (cur_rotation +1 ) % max_rotations;
    return Piece(rotation[cur_rotation]);
}
Piece Tetrimon_O::getNextOrient(){
    return Piece(rotation[0]);
}
Piece Tetrimon_S::getNextOrient(){
    cur_rotation = (cur_rotation +1 ) % max_rotations;
    return Piece(rotation[cur_rotation]);
}
Piece Tetrimon_T::getNextOrient(){
    cur_rotation = (cur_rotation +1 ) % max_rotations;
    return Piece(rotation[cur_rotation]);
}
Piece Tetrimon_Z::getNextOrient(){
    cur_rotation = (cur_rotation +1 ) % max_rotations;
    return Piece(rotation[cur_rotation]);
}
