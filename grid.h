#ifndef GRID_H
#define GRID_H
#include "header.h"
#include <iostream>
using namespace std;
class Cell{
    Color color;
    int state=0;
public:
    Cell(){
        state=0;
    }
    void set(int s,Color col){
        color = col;
        state =s;
    }
    int getState(){
        return state;
    }
    Color getColor(){
        return color;
    }
    void setState(int s){
        state =s;
    }
};
class Grid {
    int rows, cols;
    int BlockSize;
    Cell ** arr;

public:
    Grid(int r, int c, int b);
    Cell ** getGrid();
    Cell& getGridBlock(int x, int y);
    int  getBlockSize();
    Cell * operator[](int x);
    bool IsLineComplete(int i);
    void DeleteLine(int i);

    ~Grid();

    void draw();
};

#endif
