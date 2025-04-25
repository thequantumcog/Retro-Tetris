#include "raylib.h"
#include "header.h"
class Grid{
    int BlockSize;
    int ** arr;
    public:
        Grid(int h=0,int v=0,int b=0, int **doubleptr=nullptr){
        BlockSize = b;
        arr = doubleptr;
        for(int i=0;i<HorizontalLines;i++){
            for(int j=0;j<VerticalLines;j++){
                arr[i][j] = 0;
            }
        }
    }
    void draw(){
        ClearBackground(WHITE);

        for(int i=0;i<VerticalLines;i++){
            for(int j=0;j<HorizontalLines;j++){
                if(arr[i][j] == 0)
                    DrawRectangleLines(50+(i*50),50+(j*50),BlockSize,BlockSize,BLACK);
                else
                    DrawRectangle(50+(i*50),50+(j*50),BlockSize,BlockSize,BLACK);
            }
        }

    }
};
