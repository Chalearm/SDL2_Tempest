#include <iostream>
#include "sdlDrawnObj.h"

// static variable
std::shared_ptr<SDL_Renderer> SDLDrawnObj::s_pRenderer = nullptr;
std::shared_ptr<TTF_Font> SDLDrawnObj::s_aLoadedFont = nullptr;
////m_aLoadedFont = std::unique_ptr<TTF_Font,SDLDestroyer> (TTF_OpenFont("./Hersheys.ttf", 24));
bool SDLDrawnObj::loadFont(const std::string &fontPath,const int &fontSize)
{
    bool ret = false;
    if ((fontPath != "") && (fontSize > 0))
    {
        //SDLDrawnObj::s_aLoadedFont.reset((TTF_OpenFont("./Hersheys.ttf", 24),SDLDestroyer())); 
        ret = (s_aLoadedFont.get() != nullptr);
    }
    else
    {
        // Do nothing
    }
    return ret;
}

bool SDLDrawnObj::createRenderer(std::shared_ptr<SDL_Window> &pWindow)
{
    if (pWindow)
    {
        s_pRenderer.reset((SDL_CreateRenderer(pWindow.get(), -1, 0)),SDLDestroyer()); 
    }
    else
    {
        // Do nothing
    }
    return (s_pRenderer.get() != nullptr);
}
int SDLDrawnObj::initImgAndTff()
{
    int ret = 0;
    ret = IMG_Init(IMG_INIT_PNG);
    if (ret >= 0)
    {
         ret = TTF_Init();
    }
    else
    {
        // Do nothing
    }
    return ret;
}

void SDLDrawnObj::SDLImgAndTffQuit()
{
    TTF_Quit();
    IMG_Quit();
}

void SDLDrawnObj::renderClear()
{
    if (s_pRenderer)
    {
        SDL_RenderClear(s_pRenderer.get());   // clear the renderer to the draw color
    }
    else
    {
    // Do nothing
    } 
}
void SDLDrawnObj::renderPresent()
{

}
bool SDLDrawnObj::isAbleToRender()
{
    return (s_pRenderer.get() != nullptr);
}

SDLDrawnObj::SDLDrawnObj():
m_sourceRect(),
m_destRect(),
m_flipVal(SDL_FLIP_NONE),
m_angle(0.0),
m_aTexture()
{}
SDLDrawnObj::~SDLDrawnObj()
{

}

SDLDrawnObj::SDLDrawnObj(const SDLDrawnObj& obj):
m_sourceRect(obj.m_sourceRect),
m_destRect(obj.m_destRect),
m_flipVal(obj.m_flipVal),
m_angle(obj.m_angle),
m_aTexture(obj.m_aTexture)
{}

void SDLDrawnObj::setShownDimension(const int& x, const int& y, const int& w, const int& h )
{
    m_sourceRect.x = x;
    m_sourceRect.y = y;
    m_sourceRect.w = w;
    m_sourceRect.h = h;
}
void SDLDrawnObj::setDrawPosition(const int& x, const int& y, const int& w, const int& h )
{
    m_destRect.x = x;
    m_destRect.y = y;
    m_destRect.w = w;
    m_destRect.h = h;
}
void SDLDrawnObj::loadImage(const std::string &path)
{
    if ((path != "") && isAbleToRender())
    {
        std::unique_ptr<SDL_Surface, SDLDestroyer> pTempSurface(IMG_Load(path.c_str()));
        if (pTempSurface)
        {
            // the new SDL_Texture variable
            m_aTexture.reset(SDL_CreateTextureFromSurface(s_pRenderer.get(), pTempSurface.get()),SDLDestroyer());  

        }
        else
        {
            // do nothing
        } 
    }
    else
    {
        // Do nothing
    }

}
void SDLDrawnObj::drawImg()
{
    if (isAbleToRender() && m_aTexture)
    {
        SDL_RenderCopy(s_pRenderer.get(), m_aTexture.get(), &m_sourceRect, &m_destRect);
    }
    else
    {
        // Do nothing
    }
}
