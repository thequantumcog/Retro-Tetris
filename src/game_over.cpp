#include "resources.h"
#include "game_over.h"
using namespace std;
#define MAX_INPUT_CHARS 30

// private helper functions
bool GameOverScreen::isWhitespace(std::string s){
    for(size_t index = 0; index < s.length(); index++){
        if(!std::isspace(s[index]))
            return false;
    }
    return true;
}

GameOverScreen::GameOverScreen(bool& ret, bool& restart): 
    back_btn(610,1000,262,255,3,&ret) ,restart_btn(950,1000,262,255,3,&restart),ret(ret), restart(restart){
    res = new GameOverRes;
    textBox = { screenWidth/2.0f - 200, screenHeight/2.0f+150, 300, 50 };
}
std::string GameOverScreen::handle_textbox(){
    mouseOnText = CheckCollisionPointRec(GetMousePosition(), textBox);
    SetMouseCursor(mouseOnText ? MOUSE_CURSOR_IBEAM : MOUSE_CURSOR_DEFAULT);
    if (mouseOnText){
        int key = GetCharPressed();
        while (key > 0){
            // NOTE: Only allow keys in range [32..125]
            if ((key >= 32) && (key <= 125) && (key != 59)&& (name.size() < MAX_INPUT_CHARS)){
                name += (char)key;
            }
            key = GetCharPressed();  
        }

        if (IsKeyDown(KEY_BACKSPACE)) {
            backspaceHoldCounter++;
            if(backspaceHoldCounter ==1 || (backspaceHoldCounter> 10 && backspaceHoldCounter % 2 == 0)){
                if(!name.empty())
                    name.pop_back(); // akhri element remove krdo
            }
        }
        else  backspaceHoldCounter=0;

    }
    if (mouseOnText) framesCounter++;
    else framesCounter = 0;
    if(IsKeyPressed(KEY_ENTER) || ret || restart){ // agar in mein se kuch bhi ho
        if(name.empty() || isWhitespace(name))
            name = "Anonymous";
        else{
            name[0] = toupper(name[0]);
            for(size_t i=1;i<name.size();i++){
                if(i-1>0 && name[i-1] == ' '){
                    name[i] = toupper(name[i]);
                }
                else
                name[i] = tolower(name[i]);
            }
        }
        return name;
    }
    return "";
}
void GameOverScreen::mouseinput(){
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
        if (back_btn.isMouseHovering())
            back_btn.fakeclick();
        else if (restart_btn.isMouseHovering())
            restart_btn.fakeclick();
    }
    else if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
        if (back_btn.isMouseHovering())
            back_btn.clickbtn();
        else if (restart_btn.isMouseHovering())
                restart_btn.clickbtn();
    }
}

void GameOverScreen::resetbtns(){
    back_btn.resetbtn();
    restart_btn.resetbtn();
}
void GameOverScreen::draw(){
    DrawRectangle(600, 0, 625, 1080, BLACK);
    DrawTexture(res->GameOver(), 720, 120, WHITE);
    Vector2 textSize = MeasureTextEx(res->font(), "Enter Your Name", 40, 2);
    DrawTextEx(res->font(),"Enter Your Name ", (Vector2){screenWidth/2.0f-textSize.x/2.0f - 50, screenHeight/2.0f + 50}, 40,2, WHITE);

    DrawTextureRec(res->Back(), back_btn.getBtn(), 
                   back_btn.getPos(), WHITE);

    DrawTextureRec(res->Restart(), restart_btn.getBtn(), 
                   restart_btn.getPos(), WHITE);

    DrawRectangleRec(textBox, LIGHTGRAY);
    if (mouseOnText) DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, BROWN);
    else DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, DARKGRAY);

    DrawText(name.c_str(), (int)textBox.x + 5, (int)textBox.y + 8, 40, DARKBROWN);

    if (mouseOnText)
    {
        if (name.size() < MAX_INPUT_CHARS)
        {
            // Draw blinking underscore char
            if (((framesCounter/20)%2) == 0) DrawText("_", (int)textBox.x + 8 + MeasureText(name.c_str(), 40), (int)textBox.y + 12, 40, DARKBROWN);
        }
        else DrawText("Press BACKSPACE to delete chars...", screenWidth/2.0f - 170, screenHeight/2.0f, 20, GRAY);
    }

}
// getter setters
bool GameOverScreen::isGameOver(){
    if(gameOver)
        return 1;
    return 0;
}
bool GameOverScreen::operator!()  {return !(isGameOver());}

void GameOverScreen::set(bool x)  {gameOver =x;}
GameOverScreen::~GameOverScreen() {delete res;}
