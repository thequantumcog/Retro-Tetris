#include "score.h"
#include <iostream>
#include <fstream>
#include <raylib.h>

Score::Score(ResourceManager * r,bool &Menu):  res(r),enableMenu(Menu){
    background = LoadTexture("assets/score_menu.png");
    loadScores();

}
void Score::loadScores(){
    int pbIndex;
    std::string storeLine;
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
        pbIndex=0;
        while(getline(obj,storeLine)){

            int start =0;
            int containerID = 0;
            for(size_t i=0;i<storeLine.length();i++){
                if(storeLine[i] == ';'){
                    scores[pbIndex][containerID] = storeLine.substr(start,i-start);
                    start = i+1;
                    containerID++;
                }
            }
            pbIndex++;
        }
    }

    obj.close();
}
void Score::writeScores(){
    std::fstream write(scoreFile, std::ios::out);
    for(int i=0;i<3;i++){
    write << scores[i][0] << ";" << scores[i][1] << ";" << "\n";
    }
    write.close();
}
void Score::update(const std::string& name, const std::string& score){
    int newScore = std::stoi(score);
    int i=0;
    for(;i<3;i++){
        if (newScore > stoi(scores[i][1]))
            break;
    }
    if(i < 3){
        for(int j=2;j>i;j--){
            scores[j][0] = scores[j-1][0];
            scores[j][1] = scores[j-1][1];
        }
        scores[i][0] = name;
        scores[i][1] = score;
    }

}
void Score::handleInput(){
    if(IsKeyPressed(KEY_BACKSPACE) || IsKeyPressed(KEY_M))
        enableMenu=1;
}
void Score::display(){
    BeginDrawing();
    ClearBackground(WHITE);
    DrawTexture(background, 0,0, WHITE);
    int yoffset = 120;
    for(int i=0;i<3;i++){
        DrawTextEx(res->font(), scores[i][0].c_str(), {550,(float)470+yoffset*i}, 70,5,BLACK);
        DrawTextEx(res->font(), scores[i][1].c_str(), {1200,(float)470+yoffset*i}, 70,5,BLACK);
    }
    EndDrawing();
}
void Score::di_scores(){
    handleInput();
    display();
}
Score::~Score(){
    writeScores();
    UnloadTexture(background);
}
