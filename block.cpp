#include "raylib.h"
#include "header.h"

class Grid {
    int rows, cols;
    int BlockSize;
    int** arr;

public:
    Grid(int r, int c, int b) : rows(r), cols(c), BlockSize(b){
        arr = new int*[rows];
        for(int i = 0; i < rows; i++){
            arr[i] = new int[cols];
            for(int j = 0; j < cols; j++)
                arr[i][j] = 0;
        }
    }
    int ** getGrid(){
        return arr;
    }

    ~Grid(){
        for(int i = 0; i < rows; i++)
            delete[] arr[i];
        delete[] arr;
    }

    void draw(){
        ClearBackground(WHITE);
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                Rectangle r = { float(545 + j*BlockSize),float(45 + i*BlockSize),float(BlockSize),float(BlockSize) };
                if(arr[i][j] == 0)
                    DrawRectangleLinesEx(r, 1, GRAY);
                else if(arr[i][j] == 1)
                    DrawRectangleRec(r, BLACK);
                else
                    DrawRectangleRec(r, GRAY);
            }
        }
    }
};
