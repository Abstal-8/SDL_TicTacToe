#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>




class Tile 
{

    /* 
    
        We want:
            - Which symbol does the tile contain (X, O, or none)
            - Dimensions of tile
            - Position of tile
            - Was the tile selected or not   
    */


    public:
        void Initialize_Tile(SDL_Renderer *ren);
        void Reset_Tile();
        void Select_Tile(SDL_Renderer *ren);
        void On_Tile_Hover(SDL_Renderer *ren);
        void Generate_Circle(SDL_Renderer *ren);
        bool isSelectable;
        bool circleSelect;
        char currentSymbol;
        SDL_Texture *crossTexture;
        SDL_Texture *circleTexture;
        SDL_Rect tileRect = {0, 0, 80, 80};
        


    private:
    // TILE SIZE = 80x80












};