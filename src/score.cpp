#include "score.h"
#include <raylib.h>

Score::Score(){
    background = LoadTexture("assets/score_menu.png");

}
void Score::display(){
    BeginDrawing();
    ClearBackground(WHITE);
    DrawTexture(background, 0,0, WHITE);
    EndDrawing();
}
Score::~Score(){
    UnloadTexture(background);
}
