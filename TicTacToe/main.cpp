#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Game_Logic/Game.h"

Game *game = nullptr;

int main(int argc, char* argv[])
{
  srand(time(0));
  game = new Game();

  game->init("Tic-Tac-Toe", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 800, false);

  while (game->Running())
  {
    game->EventHandler();
    game->Render();
    game->Update();
  }

  game->ExitHandler();

  return 0;
}