#include "raylib.h"
#include "grid.h"
#include <iostream>
using namespace std;

Grid::Grid(int * info) : game_score(info[0]), lines_completed(info[1]), level(info[2]) {
    rows = 22;
    cols = 13;
    BlockSize = 48;
    actual_grid = new Cell*[rows];
    for(int i = 0; i < rows; i++){
        actual_grid[i] = new Cell[cols]{};
    }
    level_threshold=10;

}
int  Grid::getBlockSize(){
    return BlockSize;
}
Cell& Grid::getGridBlock(int x, int y){
    return actual_grid[x][y];

}
Cell * Grid::operator[](int x){
    return actual_grid[x];
}

// Clear Lines
bool Grid::is_line_full(int i){
    int count =0;
    for(int j=0;j<cols;j++){
        if(actual_grid[i][j].value() == 3 ) count++;
    }
    if(count == cols){
        return 1;
    }
    return 0;
}
void Grid::delete_line(int i){
    for(int k = i; k > 0; k--){
        for(int j = 0; j < cols; j++){
            actual_grid[k][j] = actual_grid[k-1][j]; 
        }
    }
    // top line ko bhi khalli karna
    for(int j = 0; j < cols; j++){
        actual_grid[0][j].set_cell(0);
    }
}


Grid::~Grid(){
    for(int i = 0; i < rows; i++)
        delete[] actual_grid[i];
    delete[] actual_grid;
}

void Grid::draw(Texture2D * block_textures){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            Vector2 pos = {float(605 + j*BlockSize),float(22 + i*BlockSize)};
            if(actual_grid[i][j].value() == 1){
                DrawTextureV(block_textures[actual_grid[i][j].getColor()],pos, WHITE);
            }
            else if(actual_grid[i][j].value() == 3)  DrawTextureV(block_textures[actual_grid[i][j].getColor()], pos,WHITE);
        }
        // TODO: SHouldnt belong here
        if(is_line_full(i)){
            delete_line(i);
            game_score +=100;
            lines_completed+=1;
        }
        if(lines_completed > level_threshold){
            level+=1;
            level_threshold += 10;
        }

    }
}
