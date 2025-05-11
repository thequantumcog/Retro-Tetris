#include "resources.h"
#include <raylib.h>
CommonRes::CommonRes(){
    back = LoadTexture("assets/btns/back.png");
    my_font = LoadFont("assets/pixelated.ttf");
    theme = LoadMusicStream("assets/theme.mp3");
}
CommonRes::~CommonRes(){
    UnloadTexture(back);
    UnloadFont(my_font);
    UnloadMusicStream(theme);
}
Texture2D& CommonRes::Back(){
    return back;
}
Font& CommonRes::font(){
    return my_font;
}
Music& CommonRes::sound(){
    return theme;
}
OptionsRes::OptionsRes(){
    background = LoadTexture("assets/options/options.png");
    level = LoadTexture("assets/options/level.png");
    toggle = LoadTexture("assets/options/toggle.png");
    selector = LoadTexture("assets/options/selector.png");
    save = LoadTexture("assets/btns/save.png");
    selection = LoadTexture("assets/options/selection.png");
}
OptionsRes::~OptionsRes(){
    UnloadTexture(background);
    UnloadTexture(level);
    UnloadTexture(toggle);
    UnloadTexture(selector);
    UnloadTexture(save);
    UnloadTexture(selection);
}
Texture2D& OptionsRes::Background(){
    return background;
}
Texture2D& OptionsRes::Level(){
    return level;
}
Texture2D& OptionsRes::Toggle(){
    return toggle;
}
Texture2D& OptionsRes::Selector(){
    return selector;
}
Texture2D& OptionsRes::Selection(){
    return selection;
}
Texture2D& OptionsRes::Save(){
    return save;
}
ScoreRes::ScoreRes(){
    background = LoadTexture("assets/score_menu.png");
}
ScoreRes::~ScoreRes(){
    UnloadTexture(background);
}
Texture2D& ScoreRes::Background(){
    return background;
}
GameOverRes::GameOverRes(){
    game_over = LoadTexture("assets/game_over.png");
    restart = LoadTexture("assets/btns/restart.png");
}
GameOverRes::~GameOverRes(){
    UnloadTexture(game_over);
}
Texture2D& GameOverRes::GameOver(){
    return game_over;
}
Texture2D& GameOverRes::Restart(){
    return restart;
}
GameRes::GameRes(){
    game_background= LoadTexture("assets/background.png");
    block_textures[0] = LoadTexture("assets/blocks/i_block.png");
    block_textures[1] = LoadTexture("assets/blocks/i_block_solid.png");
    block_textures[2] = LoadTexture("assets/blocks/j_block.png");
    block_textures[3] = LoadTexture("assets/blocks/j_block_solid.png");
    block_textures[4] = LoadTexture("assets/blocks/l_block.png");
    block_textures[5] = LoadTexture("assets/blocks/l_block_solid.png");
    block_textures[6] = LoadTexture("assets/blocks/o_block.png");
    block_textures[7] = LoadTexture("assets/blocks/o_block_solid.png");
    block_textures[8] = LoadTexture("assets/blocks/s_block.png");
    block_textures[9] = LoadTexture("assets/blocks/s_block_solid.png");
    block_textures[10] = LoadTexture("assets/blocks/t_block.png");
    block_textures[11] = LoadTexture("assets/blocks/t_block_solid.png");
    block_textures[12] = LoadTexture("assets/blocks/z_block.png");
    block_textures[13] = LoadTexture("assets/blocks/z_block_solid.png");
    // next_textures
    next_textures[0] = LoadTexture("assets/next/i_next.png");
    next_textures[1] = LoadTexture("assets/next/j_next.png");
    next_textures[2] = LoadTexture("assets/next/l_next.png");
    next_textures[3] = LoadTexture("assets/next/o_next.png");
    next_textures[4] = LoadTexture("assets/next/s_next.png");
    next_textures[5] = LoadTexture("assets/next/t_next.png");
    next_textures[6] = LoadTexture("assets/next/z_next.png");

    hold_textures[0] = LoadTexture("assets/hold/i_hold.png");
    hold_textures[1] = LoadTexture("assets/hold/j_hold.png");
    hold_textures[2] = LoadTexture("assets/hold/l_hold.png");
    hold_textures[3] = LoadTexture("assets/hold/o_hold.png");
    hold_textures[4] = LoadTexture("assets/hold/s_hold.png");
    hold_textures[5] = LoadTexture("assets/hold/t_hold.png");
    hold_textures[6] = LoadTexture("assets/hold/z_hold.png");

    shadow_textures[0] = LoadTexture("assets/shadow/i.png");
    shadow_textures[1] = LoadTexture("assets/shadow/j.png");
    shadow_textures[2] = LoadTexture("assets/shadow/l.png");
    shadow_textures[3] = LoadTexture("assets/shadow/o.png");
    shadow_textures[4] = LoadTexture("assets/shadow/s.png");
    shadow_textures[5] = LoadTexture("assets/shadow/t.png");
    shadow_textures[6] = LoadTexture("assets/shadow/z.png");
}
GameRes::~GameRes(){
    for(int i=0;i<14;i++){
        UnloadTexture(block_textures[i]);
    }
    for(int i=0;i<7;i++){
        UnloadTexture(next_textures[i]);
        UnloadTexture(hold_textures[i]);
        UnloadTexture(shadow_textures[i]);
    }
    UnloadTexture(game_background);

}
Texture2D * GameRes::Blocks(){
    return block_textures;
}

Texture2D* GameRes::Shadow(){
    return shadow_textures;
}
Texture2D * GameRes::Next(){
    return next_textures;
}
Texture2D * GameRes::Hold(){
    return hold_textures;
}
Texture2D& GameRes::Game_Background(){
    return game_background;
}
MenuRes::MenuRes(){
    menu[0] = LoadTexture("assets/menu/menu.png");
    menu[1] = LoadTexture("assets/menu/selector.png");
}
MenuRes::~MenuRes(){
    UnloadTexture(menu[0]);
    UnloadTexture(menu[1]);
}
Texture2D& MenuRes::Background(){
    return menu[0];
}
Texture2D& MenuRes::Selector(){
    return menu[1];
}
