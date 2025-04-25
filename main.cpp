#include "raylib.h"
#include "block.cpp"
#include "header.h"
#include "tetris.cpp"
// divide the background into grid
    const int screenWidth = 1920;
    const int screenHeight = 1080;
int main(void)
{
    int** arr = new int*[HorizontalLines];
    for(int i=0;i<HorizontalLines;i++){
        arr[i] = new int[VerticalLines];
    }
    Grid g(20,20,50,arr);
    Tetrimon * t = new Tetrimon_I(arr);
    // Initialization

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();
        t->move();
        g.draw();
        t->draw();
        EndDrawing();
    }

    CloseWindow();        // Close window and OpenGL context

    return 0;
}
