#ifndef __SDLRENDERER__
#define __SDLRENDERER__
 
#include <SDL2/SDL.h>
#include <iostream>


class SDLRenderer
{
private:

    struct SDLRendererDestroyer
    {
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
    std::unique_ptr<SDL_Renderer, SDLRendererDestroyer> m_pRenderer;
public:

    SDLRenderer();
    SDLRenderer(const SDLRenderer& obj);
    ~SDLRenderer();
    void renderClear();
    void renderPresent();
    bool createRenderer(SDL_Window *pWindow);
    SDLRenderer& operator=(SDLRenderer &obj);
    SDL_Texture* createTextureFromSurface(SDL_Surface* surface);
    void renderCopyEx(SDL_Texture* texture,const SDL_Rect* srcrect, const SDL_Rect* dstrect, const double angle, const SDL_Point* center, const SDL_RendererFlip flip);
    int SDLSetRenderDrawColor(const unsigned char &r,const unsigned char &g,const unsigned char &b,const unsigned char &a);
    int SDLRenderDrawLine(const int &x1,const int &y1,const int &x2,const int &y2);

};


#endif /* define (__SDLRENDERER__) */
