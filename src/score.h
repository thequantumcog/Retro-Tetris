#ifndef SCORE_H
#define SCORE_H
#include "raylib.h"
#include <string>
#include "resources.h"
class Score{
    Texture2D background;
    ResourceManager * res;
    bool& enableMenu;
    std::string scoreFile = "score.txt";
    std::string  scores[3][2];
    // Private
    void display();
    void loadScores();
    void handleInput();
    void writeScores();
public:
    Score(ResourceManager* r, bool &Menu);
    void di_scores();
    void update(const std::string& name, const std::string& score);
    ~Score();
};
#endif
