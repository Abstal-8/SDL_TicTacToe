#include <iostream>
#include <SDL2/SDL.h>
#include "Grid.h"





void Grid::Instantiate_Grid()
{
    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            tiles[y][x] = nullptr;
            tiles[y][x] = new Tile();
            tiles[y][x]->isSelectable = true;
            tiles[y][x]->tileRect.x = gridRect.x + (x * 80);
            tiles[y][x]->tileRect.y = gridRect.y + (y * 80);
        }
    }

}

void Grid::Evaluate_Grid()
{
    if (count == 9)
    {
        isGridFull = true;
    } else {
        isGridFull = false;
    }

    

    if (tiles[0][0]->currentSymbol == 'X' && tiles[1][1]->currentSymbol == 'X' && tiles[2][2]->currentSymbol == 'X')
    {
        winningPattern = "XXX";
        isPatternFound = true;
    } 
    else if (tiles[0][0]->currentSymbol == 'O' && tiles[1][1]->currentSymbol == 'O' && tiles[2][2]->currentSymbol == 'O') 
    {
        winningPattern = "OOO";
        isPatternFound = true;
    }
        
    
    if (tiles[0][0]->currentSymbol == 'X' && tiles[1][0]->currentSymbol == 'X' && tiles[2][0]->currentSymbol == 'X')
    {
        winningPattern = "XXX";
        isPatternFound = true;
    } 
    else if (tiles[0][0]->currentSymbol == 'O' && tiles[1][0]->currentSymbol == 'O' && tiles[2][0]->currentSymbol == 'O') 
    {
        winningPattern = "OOO";
        isPatternFound = true;
    }
        
    
    if (tiles[0][0]->currentSymbol == 'X' && tiles[0][1]->currentSymbol == 'X' && tiles[0][2]->currentSymbol == 'X')
    {
        winningPattern = "XXX";
        isPatternFound = true;
    } 
    else if (tiles[0][0]->currentSymbol == 'O' && tiles[0][1]->currentSymbol == 'O' && tiles[0][2]->currentSymbol == 'O') 
    {
        winningPattern = "OOO";
        isPatternFound = true;
    }
        
    
    if (tiles[2][0]->currentSymbol == 'X' && tiles[1][1]->currentSymbol == 'X' && tiles[0][2]->currentSymbol == 'X')
    {
        winningPattern = "XXX";
        isPatternFound = true;
    } 
    else if (tiles[2][0]->currentSymbol == 'O' && tiles[1][1]->currentSymbol == 'O' && tiles[0][2]->currentSymbol == 'O') 
    {
        winningPattern = "OOO";
        isPatternFound = true;
    }
        
    
    
    if (tiles[2][0]->currentSymbol == 'X' && tiles[2][1]->currentSymbol == 'X' && tiles[2][2]->currentSymbol == 'X')
    {
        winningPattern = "XXX";
        isPatternFound = true;
    } 
    else if (tiles[2][0]->currentSymbol == 'O' && tiles[2][1]->currentSymbol == 'O' && tiles[2][2]->currentSymbol == 'O') 
    {
        winningPattern = "OOO";
        isPatternFound = true;
    }
        
    
    
    if (tiles[2][2]->currentSymbol == 'X' && tiles[1][2]->currentSymbol == 'X' && tiles[0][2]->currentSymbol == 'X')
    {
        winningPattern = "XXX";
        isPatternFound = true;
    } 
    else if (tiles[2][2]->currentSymbol == 'O' && tiles[1][2]->currentSymbol == 'O' && tiles[0][2]->currentSymbol == 'O') 
    {
        winningPattern = "OOO";
        isPatternFound = true;
    }
        
    
   
    if (tiles[1][1]->currentSymbol == 'X' && tiles[0][1]->currentSymbol == 'X' && tiles[2][1]->currentSymbol == 'X')
    {
        winningPattern = "XXX";
        isPatternFound = true;
    } 
    else if (tiles[1][1]->currentSymbol == 'O' && tiles[0][1]->currentSymbol == 'O' && tiles[2][1]->currentSymbol == 'O') 
    {
        winningPattern = "OOO";
        isPatternFound = true;
    }
    
    if (tiles[1][0]->currentSymbol == 'X' && tiles[1][1]->currentSymbol == 'X' && tiles[1][2]->currentSymbol == 'X')
    {
        winningPattern = "XXX";
        isPatternFound = true;
    } 
    else if (tiles[1][0]->currentSymbol == 'O' && tiles[1][1]->currentSymbol == 'O' && tiles[1][2]->currentSymbol == 'O') 
    {
        winningPattern = "OOO";
        isPatternFound = true;
    }   
    
}

void Grid::Delete_Grid()
{
    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            tiles[y][x]->Reset_Tile();
            tiles[y][x] = nullptr;
        }
    }
    std::cout << "Grid deleted...!" << std::endl;

}

void Grid::Reset_Grid(SDL_Renderer *ren)
{

    isPatternFound = false;
    isGridFull = false;
    winningPattern = "";
    count = 0;

    Delete_Grid();
    Instantiate_Grid();
    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            tiles[y][x]->Initialize_Tile(ren);
        }
    }

    printf("Game Restart!\n");
}