#include <iostream>
#include <stdlib.h>
#include "Game.h"


using namespace std;
Grid *grid = nullptr;

// Necessary game variables
SDL_Point mousePoint = {0, 0};
bool Lmousepressed = false;
int randX = rand()%3; 
int randY = rand()%3;



Game::Game() 
{}

Game::~Game() 
{
    renderer = nullptr;
    texture = nullptr;
    player_text = nullptr;
    cpu_text = nullptr;
    tie_text = nullptr;
    imageSurface = nullptr;
    windowSurface = nullptr;
    iconSurface = nullptr;
    window = nullptr;
    TTF_Quit();
    IMG_Quit();
    SDL_DestroyTexture(player_text);
    SDL_DestroyTexture(cpu_text);
    SDL_DestroyTexture(tie_text);
    TTF_CloseFont(font);
    SDL_DestroyWindow(window);
    SDL_FreeSurface(windowSurface);
    SDL_FreeSurface(imageSurface);
    SDL_FreeSurface(player_text_surf);
    SDL_FreeSurface(cpu_text_surf);
    SDL_FreeSurface(tie_text_surf);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    grid = new Grid();
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        cout << "Game Initialization... Successful!" << endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

        if (window)
        {
            cout << "Window Created!" << endl;
        }


        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 0,0,0,0);
            cout << "Renderer Created!" << endl;
        }

        int image_flag = IMG_INIT_JPG;
        if ((IMG_Init(image_flag) & image_flag))
        {
            cout << "IMG Initialized!" << endl;
            texture = IMG_LoadTexture(renderer, "art/Blue_background1.jpg");
        }

        if (TTF_Init() == 0)
        {
            cout << "Text Initialized!" << endl;
            font = TTF_OpenFont("src/ion-font/IonCannonItalic-j9J20.ttf", 25);
            player_text_surf = TTF_RenderText_Blended(font, "Player Wins! Press R to restart.", defColor);
            player_text_rect.h = player_text_surf->h;
            player_text_rect.w = player_text_surf->w;
            player_text_rect.x = 200;
            player_text_rect.y = 500;


            cpu_text_surf = TTF_RenderText_Blended(font, "CPU Wins! Press R to restart.", defColor);
            cpu_text_rect.h = cpu_text_surf->h;
            cpu_text_rect.w = cpu_text_surf->w;
            cpu_text_rect.x = 200;
            cpu_text_rect.y = 500;


            tie_text_surf = TTF_RenderText_Blended(font, "Tie! Press R to restart.", defColor);
            tie_text_rect.h = tie_text_surf->h;
            tie_text_rect.w = tie_text_surf->w;
            tie_text_rect.x = 200;
            tie_text_rect.y = 500;

            

            player_text = SDL_CreateTextureFromSurface(renderer, player_text_surf);
            cpu_text = SDL_CreateTextureFromSurface(renderer, cpu_text_surf);
            tie_text = SDL_CreateTextureFromSurface(renderer, tie_text_surf);
        }

        // WINDOW ICON 
        iconSurface = IMG_Load("art/ttt_icon.png");
        SDL_SetWindowIcon(window, iconSurface);
        
        grid->Instantiate_Grid();
        for (int y = 0; y < 3; y++)
        {
            for (int x = 0; x < 3; x++)
            {
                grid->tiles[y][x]->Initialize_Tile(renderer);
            }
        }


        isRunning = true;
    } 
    else 
    {
        isRunning = false;
    }
}

void Game::EventHandler()
{
    SDL_Event e;

    SDL_PollEvent(&e);
    switch (e.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    case SDL_MOUSEBUTTONDOWN:
        for (int y = 0; y < 3; y++)
        {
            for (int x = 0; x < 3; x++)
            {
                if (SDL_PointInRect(&mousePoint, &grid->tiles[y][x]->tileRect) && e.button.button == SDL_BUTTON_LEFT && grid->tiles[y][x]->isSelectable && !Lmousepressed) 
                {
                    grid->tiles[y][x]->isSelectable = false;
                    grid->tiles[y][x]->currentSymbol = 'X';
                    grid->count++;
                    Lmousepressed = true;
                    while(grid->tiles[randY][randX]->isSelectable == false && grid->isPatternFound == false && (grid->count < 9))
                    {
                        randX = rand()%3;
                        randY = rand()%3;
                    }
                    grid->tiles[randY][randX]->circleSelect = true;
                    grid->tiles[randY][randX]->currentSymbol = 'O';
                    SDL_DestroyTexture(grid->tiles[randY][randX]->crossTexture);
                    grid->tiles[randY][randX]->isSelectable = false;
                    if (grid->count < 9)
                    {
                        grid->count++;
                    }
                    
                    Lmousepressed = false;
                }

            }
        }

        


    case SDL_KEYDOWN:
        if (e.key.keysym.sym == SDLK_r && (grid->isGridFull == true || grid->isPatternFound == true))
        {
            grid->Reset_Grid(renderer);
            Lmousepressed = false;
        }
        if (e.key.keysym.sym == SDLK_e)
        {
            printf("%s\n", grid->winningPattern.c_str());
        }

    case SDL_MOUSEMOTION:
        mousePoint.x = e.motion.x;
        mousePoint.y = e.motion.y;
        
    default:
        break;
    }
}

void Game::Update()
{
    grid->Evaluate_Grid(); // Checking to see who won
}


void Game::Render()
{
    
    SDL_RenderClear(renderer);

    // Add stuff you want to render here
    SDL_RenderCopy(renderer, texture, nullptr, nullptr);

    if (grid->isPatternFound && grid->winningPattern == "XXX")
    {
        SDL_RenderCopy(renderer, player_text, nullptr, &player_text_rect);
    }
    else if (grid->isPatternFound && grid->winningPattern == "OOO")
    {
        SDL_RenderCopy(renderer, cpu_text, nullptr, &cpu_text_rect);
    }
    else if (grid->isGridFull)
    {
        SDL_RenderCopy(renderer, tie_text, nullptr, &tie_text_rect);
    } else {

    }
    

    SDL_RenderDrawRect(renderer, &grid->gridRect);



    
    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            SDL_RenderDrawRect(renderer, &grid->tiles[y][x]->tileRect);

            if (grid->tiles[y][x]->circleSelect && !grid->tiles[y][x]->isSelectable)
            {
                grid->tiles[y][x]->Generate_Circle(renderer);
            }

           

            if(SDL_PointInRect(&mousePoint, &grid->tiles[y][x]->tileRect))
            {
                if (grid->tiles[y][x]->isSelectable)
                {
                    grid->tiles[y][x]->On_Tile_Hover(renderer);
                }
                else {
                    grid->tiles[y][x]->Select_Tile(renderer);
                }                
            }
            else if (!SDL_PointInRect(&mousePoint, &grid->tiles[y][x]->tileRect))
            {
                if (!grid->tiles[y][x]->isSelectable)
                {
                    grid->tiles[y][x]->Select_Tile(renderer);
                }
            }
        }
            
    }
    SDL_RenderPresent(renderer);
}

void Game::ExitHandler()
{
    grid->Delete_Grid();
    SDL_Quit();
    cout << "Game exited!" << endl;
}