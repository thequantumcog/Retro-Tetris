#include "shapes.h"
//#include "header.h"
#include <raylib.h>

void Shape::erase_current(){
    for(int i=0;i<TETROMINO_MAX_BLOCKS;i++){
        grid[tetris[i].y + yShift][(int)tetris[i].x + xShift].set_cell(0);
    }
}
// Private Functions
bool Shape::would_collide(Vector2 * tetris,int inc_x=0, int inc_y=0){
    for (int i = 0; i < TETROMINO_MAX_BLOCKS; i++) {
        int goto_x = xShift + tetris[i].x + inc_x;
        int goto_y = yShift + tetris[i].y + inc_y;

        if (goto_x < 0 || goto_x >= HorizontalLines || goto_y < 0 || goto_y >= VerticalLines) return true;
        if (grid[goto_y][goto_x].value() == 3) return true;
    }
    return false;
}
// Public Functions
Shape::Shape(Grid & g): grid(g){
    correction_values[0] = {0,0};
    correction_values[1] = {0,0};
}

void Shape::draw(){
    if(dropped)
        for(int i=0;i<TETROMINO_MAX_BLOCKS;i++){
            grid[tetris[i].y + yShift][(int)tetris[i].x + xShift].set(1,tetrimon_color);
        }
}
bool Shape::move(int inc_x, int inc_y){
    if (!dropped) return 0;
    erase_current();  
    if (!would_collide(tetris,inc_x, inc_y)) {
        xShift += inc_x;
        yShift += inc_y;
        return 1;
    }
    // agar block neeche jaane ki koshish kar raha hai
    else if (inc_y>0){
        solidify();
    }
    return 0;
}

void Shape::increase_speed(){
    gravitySpeed -=5;
}
// TODO: REVAMP
void Shape::rotate(){
    erase_current();
    Vector2* new_orientation = new Vector2[TETROMINO_MAX_BLOCKS]{};
    for(int i=0;i<TETROMINO_MAX_BLOCKS;i++){
        new_orientation[i].x = tetris[i].y;
        new_orientation[i].y = 3-tetris[i].x;
    }
    if(would_collide(new_orientation)){
        delete[] new_orientation;
        return;
    }
    // Warna ye kro
    for(int i=0;i<TETROMINO_MAX_BLOCKS;i++){
        tetris[i] = new_orientation[i];
    }
    delete[] new_orientation;

}
void Shape::move_down(){
    if(dropped){
        gravityCounter++;
        if(gravityCounter > gravitySpeed){
            erase_current();
            if(!would_collide(tetris,0, 1)) yShift++;
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
        grid[abs_y][abs_x].set(3,tetrimon_color+1); // +1 basically means to add borders
    }
    dropped=0;
}
// GETTER SETTERS
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
    return preview_index;
}
Vector2 * Shape::offset(){
    return correction_values;
}
Tetrimon_I::Tetrimon_I(Grid & g): Shape(g){
    tetrimon_color = 0;
    preview_index=0;
    correction_values[0]={-30,20};
    correction_values[1] = {-15,23};
    tetris[0] = {0,1};
    tetris[1] = {1,1};
    tetris[2] = {2,1};
    tetris[3] = {3,1};
}
Tetrimon_J::Tetrimon_J(Grid & g): Shape(g){
    tetrimon_color = 2;
    preview_index=1;
    tetris[0] = {1,2};
    tetris[1] = {2,0};
    tetris[2] = {2,1};
    tetris[3] = {2,2};
} 
Tetrimon_L::Tetrimon_L(Grid & g): Shape(g){
    tetrimon_color = 4;
    preview_index=2;
    tetris[0] = {1,0};
    tetris[1] = {1,1};
    tetris[2] = {1,2};
    tetris[3] = {2,2};
} 

Tetrimon_O::Tetrimon_O(Grid & g): Shape(g){
    tetrimon_color = 6;
    preview_index=3;
    correction_values[0] = {20,10};
    correction_values[1] = {17,5};
    tetris[0] = {1,1};
    tetris[1] = {2,1};
    tetris[2] = {1,2};
    tetris[3] = {2,2};
} 

Tetrimon_S::Tetrimon_S(Grid & g): Shape(g){
    tetrimon_color = 8;
    preview_index=4;
    tetris[0] = {1,1};
    tetris[1] = {2,1};
    tetris[2] = {2,2};
    tetris[3] = {3,2};
} 
Tetrimon_T::Tetrimon_T(Grid & g): Shape(g){
    tetrimon_color =  10;
    preview_index=5;
    tetris[0] = {1,0};
    tetris[1] = {1,1};
    tetris[2] = {1,2};
    tetris[3] = {2,1};
} 

Tetrimon_Z::Tetrimon_Z(Grid & g): Shape(g){
    tetrimon_color = 12;
    preview_index=6;
    tetris[0] = {1,2};
    tetris[1] = {2,2};
    tetris[2] = {2,1};
    tetris[3] = {3,1};
} 
