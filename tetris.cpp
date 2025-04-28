#include "tetris.h"
#include "header.h"
#include <raylib.h>

// Private Functions
void Shape::clear_previous(){
    for(int i=0;i<TETRIMON_MAX_BLOCKS;i++){
        grid->getGrid()[(int)tetris[i].y + yShift][(int)tetris[i].x + xShift].setState(0);
    }
}
bool Shape::would_collide(Vector2 * tetris,int inc_x, int inc_y){
for (int i = 0; i < TETRIMON_MAX_BLOCKS; i++) {
        int goto_x = xShift + tetris[i].x + inc_x;
        int goto_y = yShift + tetris[i].y + inc_y;

        if (goto_x < 0 || goto_x >= HorizontalLines || goto_y < 0 || goto_y >= VerticalLines) return true;
        if ((*grid)[goto_y][goto_x].getState() == 3) return true;
    }
    return false;
}
bool Shape::check_collision_X(){
    for (int i = 0; i < TETRIMON_MAX_BLOCKS; i++) {
        if(xShift + tetris[i].x + 1 >= HorizontalLines) return 1;
        if ((*grid)[yShift + tetris[i].y][xShift + (int)tetris[i].x + 1].getState() != 0) return 1;
    }
    return 0;
}
Shape::Shape(Grid * g): grid(g){}

void Shape::draw(){
    if(dropped)
    for(int i=0;i<TETRIMON_MAX_BLOCKS;i++){
        // cout << tetris[i].x << " " << tetris[i].y << endl;
        (*grid)[tetris[i].y + yShift][(int)tetris[i].x + xShift].set(1,tetrimon_color);
    }
    //cout << (*grid)[19][0].getState() << endl;
}
void Shape::move(int inc_x, int inc_y){
   if (!dropped) return;
        clear_previous();  
    if (!would_collide(tetris,inc_x, inc_y)) {
        xShift += inc_x;
        yShift += inc_y;
    }
    else if (inc_y>0){
        make_solid();
    }
}

void Shape::rotate(){
    bool collision=0;
    clear_previous();
    Vector2* v = new Vector2[4]{};
    for(int i=0;i<TETRIMON_MAX_BLOCKS;i++){
        v[i].x = tetris[i].y;
        v[i].y = 3-tetris[i].x;
    }
    if(would_collide(v,0, 0)){
        collision=1;
        delete[] v;
        return;
    }
    for(int i=0;i<TETRIMON_MAX_BLOCKS;i++){
        tetris[i] = v[i];
    }
    if(!collision) delete[] v;

}
void Shape::drop(){
    if(dropped){
        gravityCounter++;
        if(gravityCounter > gravitySpeed){
            clear_previous();
            if(!would_collide(tetris,0, 1)) yShift++;
            else make_solid();
            gravityCounter=0;
        }
    }
}

void Shape::make_solid(){
    for(int i=0;i<TETRIMON_MAX_BLOCKS;i++){
        (*grid)[yShift+(int)tetris[i].y][xShift+(int)tetris[i].x].set(3,tetrimon_color);
    }

    dropped=0;
}
Tetrimon_I::Tetrimon_I(Grid * g): Shape(g){
    tetrimon_color = SKYBLUE;
    tetris[0] = {0,0};
    tetris[1] = {0,1};
    tetris[2] = {0,2};
    tetris[3] = {0,3};
    //y=1;
}
Tetrimon_L::Tetrimon_L(Grid * g): Shape(g){
    tetrimon_color = ORANGE;
    tetris[0] = {0,0};
    tetris[1] = {0,1};
    tetris[2] = {0,2};
    tetris[3] = {1,2};
} 

Tetrimon_J::Tetrimon_J(Grid * g): Shape(g){
    tetrimon_color = BLUE;
    tetris[0] = {1,0};
    tetris[1] = {1,1};
    tetris[2] = {1,2};
    tetris[3] = {0,2};
} 

Tetrimon_Z::Tetrimon_Z(Grid * g): Shape(g){
    tetrimon_color = RED;
    tetris[0] = {0,0};
    tetris[1] = {1,0};
    tetris[2] = {1,1};
    tetris[3] = {2,1};
} 
Tetrimon_S::Tetrimon_S(Grid * g): Shape(g){
    tetrimon_color = GREEN;
    tetris[0] = {1,0};
    tetris[1] = {2,0};
    tetris[2] = {0,1};
    tetris[3] = {1,1};
} 
Tetrimon_T::Tetrimon_T(Grid * g): Shape(g){
    tetrimon_color =  PURPLE;
    tetris[0] = {0,0};
    tetris[1] = {1,0};
    tetris[2] = {2,0};
    tetris[3] = {1,1};
} 
Tetrimon_O::Tetrimon_O(Grid * g): Shape(g){
    tetrimon_color = YELLOW;
    tetris[0] = {0,0};
    tetris[1] = {0,1};
    tetris[2] = {1,0};
    tetris[3] = {1,1};
} 

