#include "raylib.h"
class ResourceManager{
    static const int SPRTIE_COUNT = 14;
    Texture2D block_textures[SPRTIE_COUNT]; 
    Texture2D hold_textures[7]; 
    Texture2D next_textures[7]; 
    Texture2D shadow_textures[7]; 
    Texture2D background;
    Texture2D game_over;
    Font my_font;
public:
    ResourceManager();
    ~ResourceManager();
    Texture2D * Blocks();
    Texture2D * Hold();
    Texture2D * Next();
    Texture2D * Shadow();
    Texture2D&  Background();
    Texture2D&  GameOver();
    Font&  font();
};
