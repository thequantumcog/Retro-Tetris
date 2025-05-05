#include "game.h"
#include <raylib.h>
void Game::load_textures(){
    my_font = LoadFont("assets/pixelated.ttf");
    background= LoadTexture("assets/background.png");
    block_textures[0] = LoadTexture("assets/i_block.png");
    block_textures[1] = LoadTexture("assets/i_block_solid.png");
    block_textures[2] = LoadTexture("assets/j_block.png");
    block_textures[3] = LoadTexture("assets/j_block_solid.png");
    block_textures[4] = LoadTexture("assets/l_block.png");
    block_textures[5] = LoadTexture("assets/l_block_solid.png");
    block_textures[6] = LoadTexture("assets/o_block.png");
    block_textures[7] = LoadTexture("assets/o_block_solid.png");
    block_textures[8] = LoadTexture("assets/s_block.png");
    block_textures[9] = LoadTexture("assets/s_block_solid.png");
    block_textures[10] = LoadTexture("assets/t_block.png");
    block_textures[11] = LoadTexture("assets/t_block_solid.png");
    block_textures[12] = LoadTexture("assets/z_block.png");
    block_textures[13] = LoadTexture("assets/z_block_solid.png");
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
void Game::unload_textures(){
    for(int i=0;i<14;i++){
        UnloadTexture(block_textures[i]);
    }
    for(int i=0;i<7;i++){
        UnloadTexture(next_textures[i]);
        UnloadTexture(hold_textures[i]);
        UnloadTexture(shadow_textures[i]);
    }
    UnloadTexture(background);
    UnloadFont(my_font);

}
