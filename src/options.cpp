#include "options.h"
#include "resources.h"
#include <fstream>
#include <raylib.h>
using namespace std;



Options::Options(ResourceManager* r, bool& Menu, int * startingLevel, bool * music): res(r), 
    back_btn(600,1000,262,255,3,&Menu),save_btn(1000,1000,262,255,3,&Save),toggle_btn(1000,450,189,95,2,music){
    this->startingLevel = startingLevel;
    *startingLevel=1;
    this->music = music;
    background = LoadTexture("assets/options/options.png");
    back = LoadTexture("assets/options/back.png");
    save = LoadTexture("assets/options/save.png");
    level = LoadTexture("assets/options/level.png");
    toggle = LoadTexture("assets/options/toggle.png");
    selector = LoadTexture("assets/options/selector.png");
    list = Selected::LEVEL;
    LoadPrev();

}
void Options::di_options(){
    logic();
    input();
    draw();
}
void Options::logic(){
static Selected prevSelected = Selected::NONE;

if (prevSelected != list) {
    switch (prevSelected) {
        case Selected::LEVEL:    break;
        case Selected::MUSIC:  toggle_btn.togglefocus(); break;
        case Selected::BACK:   back_btn.togglefocus();   break;
        case Selected::SAVE:   save_btn.togglefocus();   break;
        case Selected::NONE:   /* nothing to do */      break;
    }
    switch (list) {
        case Selected::LEVEL:    break;
        case Selected::MUSIC:  toggle_btn.togglefocus(); break;
        case Selected::BACK:   back_btn.togglefocus();   break;
        case Selected::SAVE:   save_btn.togglefocus();   break;
        case Selected::NONE:   /* nothing to do */      break;
    }
}

switch (list) {
    case Selected::LEVEL:
        if (IsKeyPressed(KEY_RIGHT)) {
            *startingLevel = (*startingLevel % 8) + 1;
        }
        else if (IsKeyPressed(KEY_LEFT)) {
            *startingLevel = ((*startingLevel + 6) % 8) + 1;
        }
        break;

    case Selected::MUSIC:
        if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_RIGHT)) {
            toggle_btn.clickbtn();
        }
        break;

    case Selected::BACK:
        if (IsKeyPressed(KEY_ENTER)) {
            back_btn.clickbtn();
            back_btn.togglefocus();
            list = Selected::NONE;    
        }
        break;

    case Selected::SAVE:
        if (IsKeyPressed(KEY_ENTER)) {
            save_btn.clickbtn();      
            save_btn.togglefocus();
            list = Selected::NONE;
        }
        break;

    case Selected::NONE:
        break;
}

prevSelected = list;
}
void Options::input(){
    if(IsKeyPressed(KEY_DOWN))
        list = (Selected)((int)list + 1);
    if (IsKeyPressed(KEY_BACKSPACE))
        back_btn.clickbtn();

    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
        if (back_btn.isMouseHovering())
            back_btn.clickbtn();
        else if (save_btn.isMouseHovering())
            save_btn.clickbtn();
    }
    else{
        back_btn.resetbtn();
        save_btn.resetbtn();
    }
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
        if (back_btn.isMouseHovering())
            back_btn.clickbtn();
        else if (toggle_btn.isMouseHovering())
                toggle_btn.clickbtn();
    }
    if(Save){
        Write();
        back_btn.clickbtn();
        Save=0;
    }
}
void Options::draw(){
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawTexture(background,0,0,WHITE);
    DrawTextEx(res->font(),"Music", {700,450},60, 5,WHITE);
    DrawTexture(level, 470, 250,WHITE);
    DrawTexture(selector,560 + (*startingLevel)*105, 250, WHITE);
    DrawTextureRec(back, back_btn.getBtn(), 
                   back_btn.getPos(), WHITE);
    DrawTextureRec(save, save_btn.getBtn(), 
                   save_btn.getPos(), WHITE);
    DrawTextureRec(toggle,toggle_btn.getBtn(), 
                   toggle_btn.getPos(), WHITE);
    EndDrawing();
}
void Options::LoadPrev(){
    fstream write("options.txt",ios::in);
    write >> *startingLevel;
    write >> *music;
    write.close();
}
void Options::Write(){
    fstream write("options.txt",ios::out);
    write << *startingLevel << "\n";
    write << *music << "\n";
    write.close();
}
Options::~Options(){
    UnloadTexture(background);
    UnloadTexture(back);
    UnloadTexture(save);
    UnloadTexture(level);
    UnloadTexture(toggle);
    UnloadTexture(selector);
}
