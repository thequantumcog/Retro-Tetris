#include "header.h"
#include "raylib.h"
#include "grid.h"
#include <iostream>
using namespace std;

Grid::Grid(int r, int c, int b) : rows(r), cols(c), BlockSize(b){
        arr = new Cell*[rows];
        for(int i = 0; i < rows; i++){
            arr[i] = new Cell[cols]{};
        }
    }
    Cell ** Grid::getGrid(){
        return arr;
    }
    int  Grid::getBlockSize(){
        return BlockSize;
    }
Cell& Grid::getGridBlock(int x, int y){
    return arr[x][y];

}
Cell * Grid::operator[](int x){
    return arr[x];
}

// Clear Lines
bool Grid::IsLineComplete(int i){
    int count =0;
    for(int j=0;j<HorizontalLines;j++){
        if(arr[i][j].getState() == 3 ){
            count++;}
    }
    if(count == HorizontalLines){
        DeleteLine(i);
        return 1;
    }
    return 0;
}
void Grid::DeleteLine(int i){
  for(int k = i; k > 0; k--){
        for(int j = 0; j < HorizontalLines; j++){
            arr[k][j] = arr[k-1][j]; 
        }
    }
    // for(int j = 0; j < HorizontalLines; j++){
    //     arr[0][j].setState(0);
    // }
}
Grid::~Grid(){
        for(int i = 0; i < rows; i++)
            delete[] arr[i];
        delete[] arr;
    }

    void Grid::draw(){
        ClearBackground(WHITE);
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                Rectangle r = { float(690 + j*BlockSize),float(100 + i*BlockSize),float(BlockSize),float(BlockSize) };
                if(arr[i][j].getState() != 0)
                     DrawRectangleRec(r, arr[i][j].getColor());
                    DrawRectangleLinesEx(r, 1, BLACK);
            }
        if(IsLineComplete(i))
            cout << "WHAT IT WORKED FIRST TRY" << endl;
        }
    }
