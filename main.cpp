#include "raylib.h"
#include "header.h"
#include "tetris.h"

const int screenWidth = 1920;
const int screenHeight = 1080;

Shape * getRandomPiece(Grid * g){

    int random = GetRandomValue(0, 6);
    Shape * piece = nullptr;
    switch(random){
        case 0:{piece = new Tetrimon_I(g);}
            break;
        case 1:{piece = new Tetrimon_L(g);}
            break;
        case 2:{piece = new Tetrimon_J(g);}
            break;
        case 3:{piece = new Tetrimon_Z(g);}
            break;
        case 4:{piece = new Tetrimon_T(g);}
            break;
        case 5:{piece = new Tetrimon_S(g);}
            break;
        case 6:{piece = new Tetrimon_O(g);}
            break;
    }
    return piece;
}
int main(){    
        

    InitWindow(screenWidth, screenHeight, "Schrodinger's Tetris");
    SetTargetFPS(60);
    Grid g(VerticalLines,HorizontalLines,45);
    Shape * t = getRandomPiece(&g);
    // Shape * t = new Tetrimon_I(&g);
    t->setDrop(1);
    while (!WindowShouldClose())
    {   
        if(!t->getDrop()){
            t = getRandomPiece(&g);
            // t = new Tetrimon_I(&g);
            t->setDrop(1);
        }
        t->drop();

        //LOGIC HERE
        if( IsKeyPressed(KEY_DOWN) ||IsKeyPressedRepeat(KEY_DOWN) || IsKeyPressed(KEY_J))
            t->move(0,1);
        if( IsKeyPressed(KEY_RIGHT) || IsKeyPressedRepeat(KEY_RIGHT) || IsKeyPressed(KEY_L))
            t->move(1,0);
        if( IsKeyPressed(KEY_LEFT) || IsKeyPressedRepeat(KEY_LEFT)  || IsKeyPressed(KEY_H))
            t->move(-1,0);
        if(IsKeyPressed(KEY_UP) || IsKeyPressedRepeat(KEY_UP)  || IsKeyPressed(KEY_K))
            t->rotate();
        // DRAWINGS ARE HERE
        BeginDrawing();
        t->draw();
        g.draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
