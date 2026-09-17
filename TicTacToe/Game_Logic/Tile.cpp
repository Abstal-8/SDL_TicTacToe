#include <iostream>
#include <stdlib.h>
#include "Tile.h"

using namespace std;




void Tile::Initialize_Tile(SDL_Renderer* ren)
{
        int image_flag = IMG_INIT_PNG;
        if ((IMG_Init(image_flag) & image_flag))
        {
            cout << "Tile init... Success!" << endl;
            crossTexture = IMG_LoadTexture(ren, "art/cross.png");
            circleTexture = IMG_LoadTexture(ren, "art/circle.png");
        }
}

void Tile::On_Tile_Hover(SDL_Renderer *ren)
{
    SDL_RenderCopy(ren, crossTexture, nullptr, &tileRect);
}

void Tile::Select_Tile(SDL_Renderer *ren)
{
    SDL_RenderCopy(ren, crossTexture, nullptr, &tileRect);
}

void Tile::Generate_Circle(SDL_Renderer *ren)
{   
    SDL_RenderCopy(ren, circleTexture, nullptr, &tileRect);
}

void Tile::Reset_Tile()
{
    isSelectable = false;
    circleSelect = false;
    crossTexture = nullptr;
    circleTexture = nullptr;
    SDL_DestroyTexture(crossTexture);
    SDL_DestroyTexture(circleTexture);

}