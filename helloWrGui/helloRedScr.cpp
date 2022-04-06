#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

SDL_Window *g_pWindow = nullptr;
SDL_Renderer *g_pRenderer = nullptr;

int main(int argc, char *args[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
         // if succeeded create our window
        g_pWindow = SDL_CreateWindow("Chapter 1: setting up SLD",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,640,480,SDL_WINDOW_SHOWN);
        
        // if the window creation succeeded create our renderer
        if (g_pWindow != nullptr)
        {
            g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
        }
        else
        {
            return 1; // sdl could not initialize
        }
    }
    else
    {
        return 1;  // sdl could not initialize
    }
    // everything succeeded lets draw the window

    // set to black // this function expects Red, Green, Blue and 
    // Alpha as color values
    SDL_SetRenderDrawColor(g_pRenderer, 255, 0, 0, 255);
    // clear the window to black
    SDL_RenderClear(g_pRenderer);

    // show the window
    SDL_RenderPresent(g_pRenderer);

    // set a delay before quitting
    // not work in the MAC apple platform
    // SDL_Delay(4000);

    SDL_Event e;
    bool quit = false;
    while (!quit)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
            if (e.type == SDL_KEYDOWN)
            {
                quit = true;
            }
            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                quit = true;
            }
        }
    }

    // clean up SDL
    SDL_Quit();

    return 0;
}
