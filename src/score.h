#include "raylib.h"
#include <string>
#include <vector>
class Score{
    Texture2D background;
    bool& enableMenu;
    std::string scoreFile = "score.txt";
    std::string  scores[3][2];
public:
    Score(bool &Menu);
    ~Score();
    void display();
    void loadScores();
    void handleInput();
    void writeScores();
};
