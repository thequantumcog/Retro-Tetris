#include "raylib.h"
const int TETROMINO_MAX_BLOCKS =4;
class Piece{
private:
    Vector2 actual_piece[4];
public:
    Piece(Vector2 arr[4]){
        for(int i=0;i<TETROMINO_MAX_BLOCKS;i++){
            actual_piece[i] = arr[i];
        }
    }
    Piece(){}
    Vector2& operator[](int i){
        return actual_piece[i];
    }
    void operator=(Vector2 arr[4]){
        for(int i=0;i<TETROMINO_MAX_BLOCKS;i++){
            actual_piece[i] = arr[i];
        }
    }
};
