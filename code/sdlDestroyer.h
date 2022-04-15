#ifndef __SDLDESTROYER__
#define __SDLDESTROYER__
 
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

struct SDLDestroyer
{
    void operator()(SDL_Window* w) const
    {
        if (w != nullptr)
        {
            SDL_DestroyWindow(w);
        }
        else
        {
            // Do nothing
        }
    }
    void operator()(SDL_Texture* w) const
    {
        if (w != nullptr)
        {
            SDL_DestroyTexture(w);
        }
        else
        {
            // Do nothing
        }          
    }        
    void operator()(SDL_Surface* w) const
    {
        if (w != nullptr)
        {
            SDL_FreeSurface(w);
        }
        else
        {
            // Do nothing
        }          
    }    
    void operator()(TTF_Font* w) const
    {
        TTF_CloseFont(w);    
    }        
    void operator()(SDL_Renderer* w) const
    {
        if (w != nullptr)
        {
            SDL_DestroyRenderer(w);
        }
        else
        {
            // Do nothing
        }
    }
};


#endif /* define (__SDLDESTROYER__) */
