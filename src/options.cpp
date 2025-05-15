#include <fstream>
#include "options.h"
using namespace std;

Options::Options(bool& Menu, int * startingLevel, bool * music):  
    back_btn(600,1000,262,255,3,&Menu),save_btn(1000,1000,262,255,3,&Save),toggle_btn(1200,650,189,95,2,music){
    res = new OptionsRes();
    this->startingLevel = startingLevel;
    *startingLevel=1;
    this->music = music;
    list = Selected::LEVEL;
    LoadPrev();

}
void Options::reset_btns(){
    back_btn.resetbtn();
    save_btn.resetbtn();
}
void Options::display_options(){
    input();
    logic();
    draw();
    reset_btns();

}
void Options::save_options(){
        Write();
        back_btn.clickbtn();
        Save=0;
}
void Options::logic(){
static Selected prevSelected = Selected::NONE;

if (prevSelected != list) {
    switch (prevSelected) {
        case Selected::LEVEL:   /* kuch na kro */ break;
        case Selected::MUSIC:  toggle_btn.togglefocus(); break;
        case Selected::BACK:   back_btn.togglefocus();   break;
        case Selected::SAVE:   save_btn.togglefocus();   break;
        case Selected::NONE:   /* kuch na kro */      break;
    }
    switch (list) {
        case Selected::LEVEL:    break;
        case Selected::MUSIC:  toggle_btn.togglefocus(); break;
        case Selected::BACK:   back_btn.togglefocus();   break;
        case Selected::SAVE:   save_btn.togglefocus();   break;
        case Selected::NONE:   /* kuch na kro */      break;
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
        if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_ENTER)) {
            toggle_btn.clickbtn();
        }
        break;

    case Selected::BACK:
            if(IsKeyDown(KEY_ENTER)){
                back_btn.fakeclick();
            }
            else if (IsKeyReleased(KEY_ENTER)) {
                back_btn.clickbtn();
                back_btn.togglefocus();
                list = Selected::NONE;    
            }
            break;

    case Selected::SAVE:
            if(IsKeyDown(KEY_ENTER)){
                save_btn.fakeclick();
            }
            if (IsKeyReleased(KEY_ENTER)) {
                save_btn.clickbtn();      
                save_btn.togglefocus();
                list = Selected::NONE;
                save_options();
            }
        break;

    case Selected::NONE:
        break;
}

prevSelected = list;
}
void Options::handle_keyboard(){
    if(IsKeyPressed(KEY_DOWN))
        list = (Selected)(((int)list + 1) % 3);
    else if(IsKeyPressed(KEY_UP))
        list = (Selected)(((int)list - 1 + 3) % 3);
    else if(list == Selected::BACK && IsKeyPressed(KEY_RIGHT)){
        list = Selected::SAVE;
    }
    else if(list == Selected::SAVE && IsKeyPressed(KEY_LEFT)){
        list = Selected::BACK;
    }
    else if (IsKeyPressed(KEY_BACKSPACE))
        back_btn.clickbtn();
}

void Options::handle_mouse(){
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
        if (back_btn.isMouseHovering())
            back_btn.fakeclick();
        else if (save_btn.isMouseHovering())
            save_btn.fakeclick();
    }
    else if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
        if (back_btn.isMouseHovering())
            back_btn.clickbtn();
        else if (toggle_btn.isMouseHovering())
                toggle_btn.clickbtn();
    }
}
void Options::input(){
    handle_keyboard();
    handle_mouse();

}
void Options::draw(){
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawTexture(res->Background(),0,0,WHITE);
    DrawTexture(res->Selection(), 415, 490+(list == Selected::LEVEL ? 0 : 170), WHITE);

    DrawTexture(res->Selector(),560 + (*startingLevel)*105, 450, WHITE);
    DrawTexture(res->Level(), 470, 450,WHITE);

    DrawTextureRec(res->Back(), back_btn.getBtn(), 
                   back_btn.getPos(), WHITE);

    DrawTextureRec(res->Save(), save_btn.getBtn(), 
                   save_btn.getPos(), WHITE);

    DrawTextEx(res->font(),"Music", {480,650},60, 5,WHITE);
    DrawTextureRec(res->Toggle(),toggle_btn.getBtn(), 
                   toggle_btn.getPos(), WHITE);

    EndDrawing();
}
void Options::LoadPrev(){
    fstream read("options.txt",ios::in);
    read >> *startingLevel;
    read >> *music;
    read.close();
}
void Options::Write(){
    fstream write("options.txt",ios::out);
    write << *startingLevel << "\n";
    write << *music << "\n";
    write.close();
}
Options::~Options(){
    delete res;
}
