#include "sdlRenderer.h"

SDLRenderer::SDLRenderer():
m_pRenderer(nullptr)
{

}

SDLRenderer::SDLRenderer(const SDLRenderer& obj):
m_pRenderer(obj.m_pRenderer.get())
{
}
SDLRenderer::~SDLRenderer()
{}

SDLRenderer& SDLRenderer::operator=(SDLRenderer &obj)
{
    if (this != &obj)
    {
        m_pRenderer.reset(obj.m_pRenderer.get());
    }
    else
    {
        // Do nothing
    }
    return *this;
}
bool SDLRenderer::createRenderer(SDL_Window *pWindow)
{
    bool ret = false;
    if (pWindow != nullptr)
    {
        m_pRenderer = std::unique_ptr<SDL_Renderer, SDLRendererDestroyer>(SDL_CreateRenderer(pWindow, -1, 0));        
        if (m_pRenderer)
        {
            ret = true;
        }
        else
        {
            // Do nothing
        }
    }
    else
    {
            // Do nothing
    }
    return ret;
}

void SDLRenderer::renderClear()
{
    if (m_pRenderer)
    {
        SDL_RenderClear(m_pRenderer.get());   // clear the renderer to the draw color
    }
    else
    {
        // Do nothing
    }
}
void SDLRenderer::renderPresent()
{
    if (m_pRenderer)
    {
        SDL_RenderPresent(m_pRenderer.get()); // draw to the screen
    }
    else
    {
        // Do nothing
    }
}

SDL_Texture* SDLRenderer::createTextureFromSurface(SDL_Surface* surface)
{
    return SDL_CreateTextureFromSurface(m_pRenderer.get(), surface);
}

void SDLRenderer::renderCopyEx(SDL_Texture* texture,const SDL_Rect* srcrect, const SDL_Rect* dstrect, const double angle, const SDL_Point* center, const SDL_RendererFlip flip)
{
    if (m_pRenderer)
    {
        SDL_RenderCopyEx(m_pRenderer.get(), texture, srcrect, dstrect, angle, center, flip);
    }
    else
    {
        // Do nothing
    }
}