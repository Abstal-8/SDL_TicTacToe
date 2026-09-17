#include <iostream>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "Tile.h"

class Grid {


    public:
        // TODO: Continue editing Evaluate Grid function

        void Instantiate_Grid();
        void Evaluate_Grid();
        void Generate_Circle(SDL_Renderer *ren);
        void Reset_Grid(SDL_Renderer *ren);
        void Delete_Grid();
        Tile* tiles[3][3];
        bool isPatternFound = false;
        bool isGridFull;
        int count = 0;
        std::string winningPattern;
        SDL_Rect gridRect = {240, 240, 240, 240};

    private:
        // int randX = rand() % 3; 
        // int randY = rand() % 3;

        
};