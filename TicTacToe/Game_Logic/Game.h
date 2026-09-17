#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "Grid.h"
#define SDL_BUTTON(X)       (1 << ((X)-1))
using namespace std;

class Game {

public:
    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

    void EventHandler();
    void Update();
    void Render();
    void ExitHandler();

    bool Running() { return isRunning; }



private:
    bool isRunning;
    SDL_Window *window;
    SDL_Surface *windowSurface;
    SDL_Surface *imageSurface;
    SDL_Texture *texture;
    SDL_Renderer *renderer;
    SDL_Surface *iconSurface;

    TTF_Font *font;
    SDL_Surface *player_text_surf;
    SDL_Surface *cpu_text_surf;
    SDL_Surface *tie_text_surf;
    SDL_Rect player_text_rect = {0, 0, 0, 0}; 
    SDL_Rect cpu_text_rect = {0, 0, 0, 0}; 
    SDL_Rect tie_text_rect = {0, 0, 0, 0}; 
    SDL_Texture *player_text;
    SDL_Texture *cpu_text;
    SDL_Texture *tie_text;
    SDL_Color defColor = {0, 0, 0, 255};
    
};