#include "score.h"
#include <iostream>
#include <fstream>
#include <raylib.h>

Score::Score(bool &Menu): enableMenu(Menu){
    background = LoadTexture("assets/score_menu.png");
    loadScores();

}
void Score::loadScores(){
    std::fstream obj(scoreFile,std::ios::in);
    if(!obj){
        std::cout << "NO FILE" << std::endl;
        for(int i=0;i<3;i++){
            scores[i][0] = "Anon";
            scores[i][1] = "0";
        }
    }
    //TODO: FIX
    else{
        for(int i=0;i<3;i++){
            obj >> scores[i][0];
            obj >> scores[i][1];
        }
    }

}
void Score::writeScores(){
}
void Score::handleInput(){
    if(IsKeyPressed(KEY_BACKSPACE) || IsKeyPressed(KEY_M))
        enableMenu=1;
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
