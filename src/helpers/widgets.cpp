#ifndef WIDGETS_H
#define WIDGETS_H
#include "raylib.h"
class btn{
protected:
    int frames;
    Rectangle button[3];
    Rectangle dst;
    bool clicked=0;
    bool& controlVar;
    bool focused=0;
public:
    btn(float posx, float posy, float width, float pic_height, int frames,bool * controlVar):
        controlVar(*controlVar){
        this->frames = frames;
        for(int i=0;i<frames;i++){
            button[i] = {0,i*(pic_height/frames),width,pic_height/frames};
        }
        dst = {posx, posy, width, pic_height/frames};
    }
    bool isMouseHovering(){
        return CheckCollisionPointRec(GetMousePosition(), dst)|| focused;
    }
    void clickbtn(){
        clicked=1;
        controlVar = !controlVar;
    }
    bool getState(){
        return controlVar;
    }
    void fakeclick(){
        clicked=1;
    }
    void resetbtn(){
        clicked=0;
    }
    void togglefocus(){
        focused=!focused;
    }
    Rectangle getBtn(){
        if(clicked){
            return button[2];
        }
        else if(isMouseHovering())
            return button[1];
        return button[0];
    }
    Vector2 getPos(){
        return {dst.x, dst.y};
    }


};
class Toggle : public btn{
public:
    Toggle(float posx, float posy, float width, float pic_height, int frames, bool * controlVar): btn(posx,posy,width,pic_height,frames,controlVar){}
    void clickbtn(){
        controlVar = !controlVar;
    }
    Rectangle getBtn(){
        if(!controlVar){
            return button[1];
        }
        return button[0];
    }

};
#endif
