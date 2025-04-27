#include "raylib.h"
#include "block.cpp"
#include "header.h"
#include "tetris.cpp"

const int screenWidth = 1920;
const int screenHeight = 1080;

Shape * getRandomPiece(int **g){
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
int main(void)
{
    Grid g(22,15,45);
    // Tetrimon * t = new Tetrimon_I(g.getGrid());

    InitWindow(screenWidth, screenHeight, "Schrodinger's Tetris");

    SetTargetFPS(60);

    bool dropped=1;
    Shape * t = getRandomPiece(g.getGrid());
    //Tetrimon * t = nullptr;
    while (!WindowShouldClose())
    {   
        // if(!dropped){
        // t = getRandomPiece(g.getGrid());
        //     dropped=1;
        // }
        t->drop(dropped);

        //LOGIC HERE
        if(IsKeyPressed(KEY_DOWN))
            t->move_down();
        if(IsKeyPressed(KEY_RIGHT))
            t->move_right();
        if(IsKeyPressed(KEY_LEFT))
            t->move_left();
        if(IsKeyPressed(KEY_UP))
            t->rotate();
        t->draw();
        // DRAWINGS ARE HERE
        BeginDrawing();
        g.draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
