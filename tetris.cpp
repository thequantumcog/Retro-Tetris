#include "header.h"
#include <iostream>
using namespace std;
class Shape{
protected:
    int **tetris;
    int **grid;
    int x=1,y=1;

    int gravityCounter=0;
    int gravitySpeed=30;
public:
    Shape(int **g): grid(g){}
    virtual void rotate(){
        for(int i=y;i<4+y;i++){
            for(int j=x;j<4+x;j++){
                if(tetris[i-y][j-x])
                    grid[i][j] = 0;
            }
        }
        int ** arr = new int*[4];
        for(int i=0;i<4;i++){
            arr[i] = new int[4]{};
            for(int j=0;j<4;j++){
                arr[i][j] = tetris[j][3-i];

            }
        }
        delete[] tetris;
        tetris = arr;
    }
    void clear_previous(){
        for(int i = y; i < y + 4; ++i)
            for(int j = x; j < x + 4; ++j)
                if(grid[i][j])
                    grid[i][j] = 0;
    }
    void move_down(){
        if(y <19){
        clear_previous();
        y++;}
    }
    void move_right(){
        clear_previous();
        x++;
    }
    void move_left(){
        if(x>0){
        clear_previous();
        x--;}
    }
    void draw(){
        cout << x << " " << y << endl;
        for(int i=y;i<y+4;i++){
            for(int j=x;j<4+x;j++){
                if(tetris[i-y][j-x])
                    grid[i][j] = tetris[i-y][j-x];
            }
        }
    }
    void drop(bool &dropped){
        if(!dropped){
        gravityCounter++;
        if(gravityCounter > gravitySpeed){
            clear_previous();

            grid[y][x] = 0;
            y++;
            gravityCounter=0;
        }
        if(y>=19){
            make_solid(dropped);
        }

    }
    }

    void make_solid(bool &dropped){
        for(int i=y;i<4+y;i++){
            for(int j=x;j<4+x;j++){
                if(tetris[i-y][j-x])
                    grid[i][j] = 3;
            }
            dropped=0;
    }
    }
};
class Tetrimon_I: public Shape{
    int rotated=0,maxRotations=1;
    int length=4;
public:
    Tetrimon_I(int **g): Shape(g){
        y=1;
        tetris = new int*[4];
        for(int i=0;i<4;i++){
            tetris[i] = new int[4]{};
            tetris[i][x] = 1;
        }
    }
};
class Tetrimon_L: public Shape{
public:
    Tetrimon_L(int **g): Shape(g){
        tetris = new int*[4];
        for(int i=0;i<4;i++){
            tetris[i] = new int[4]{};
        }
        tetris[0][0] = 1;
        tetris[0][1] = 1;
        tetris[0][2] = 1;
        tetris[1][2] = 1;
    } 

};
class Tetrimon_J: public Shape{
public:
    Tetrimon_J(int **g): Shape(g){
        tetris = new int*[4];
        for(int i=0;i<4;i++){
            tetris[i] = new int[4]{};
        }
        tetris[0][2] = 1;
        tetris[1][0] = 1;
        tetris[1][1] = 1;
        tetris[1][2] = 1;
    } 

};
class Tetrimon_Z: public Shape{
public:
    Tetrimon_Z(int **g): Shape(g){
        tetris = new int*[4];
        for(int i=0;i<4;i++){
            tetris[i] = new int[4]{};
        }
        tetris[0][1] =1;
        tetris[1][1] = 1;
        tetris[1][0] = 1;
        tetris[2][0] = 1;
    } 
};
class Tetrimon_S: public Shape{
public:
    Tetrimon_S(int **g): Shape(g){
        tetris = new int*[4];
        for(int i=0;i<4;i++){
            tetris[i] = new int[4]{};
        }
        tetris[0][0] =1;
        tetris[1][0] = 1;
        tetris[1][1] = 1;
        tetris[2][1] = 1;
    } 
};
class Tetrimon_T: public Shape{
public:
    Tetrimon_T(int **g): Shape(g){
        tetris = new int*[4];
        for(int i=0;i<4;i++){
            tetris[i] = new int[4]{};
        }
        tetris[0][0] =1;
        tetris[0][1] = 1;
        tetris[0][2] = 1;
        tetris[1][1] = 1;
    } 
};
class Tetrimon_O: public Shape{
public:
    Tetrimon_O(int **g): Shape(g){
        tetris = new int*[4];
        for(int i=0;i<4;i++){
            tetris[i] = new int[4]{};
        }
        tetris[0][0] =1;
        tetris[1][0] = 1;
        tetris[0][1] = 1;
        tetris[1][1] = 1;
    } 
};

