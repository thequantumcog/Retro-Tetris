#include "score.h"
#include <fstream>

Score::Score(bool &Menu):enableMenu(Menu){
    res = new ScoreRes();
    loadScores();

}
void Score::loadScores(){
    int curEntry;
    std::string buffer;
    std::fstream obj(scoreFile,std::ios::in);
        curEntry=0;
        while(getline(obj,buffer)){
            int start =0;
            int goto_next = 0;
            for(size_t i=0;i<buffer.length();i++){
                if(buffer[i] == ';'){
                    scores[curEntry][goto_next] = buffer.substr(start,i-start);
                    start = i+1;
                    goto_next++;
                }
            }
            curEntry++;
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
void Score::update(const std::string& name, int score){
    int toComapre=0;
    int i=0;
    for(;i<3;i++){
        if(scores[i][1].empty()) toComapre =0;
        else toComapre = stoi(scores[i][1]);
        if (score > toComapre)
            break;
    }
    if(i < 3){
        for(int j=2;j>i;j--){
            scores[j][0] = scores[j-1][0];
            scores[j][1] = scores[j-1][1];
        }
        scores[i][0] = name;
        scores[i][1] = std::to_string(score);
    }

}
void Score::handleInput(){
    if(IsKeyPressed(KEY_BACKSPACE) || IsKeyPressed(KEY_M))
        enableMenu=1;
}
void Score::display(){
    BeginDrawing();
    ClearBackground(WHITE);
    DrawTexture(res->Background(), 0,0, WHITE);
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
    delete res;
}
