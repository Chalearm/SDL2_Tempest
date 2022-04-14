#ifndef __SDLDRAWNOBJ__
#define __SDLDRAWNOBJ__
 
#include <iostream>
#include <cstring>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "sdlDestroyer.h"
class SDLDrawnObj
{
private:
    SDL_Rect m_sourceRect;
    SDL_Rect m_destRect;
    SDL_RendererFlip m_flipVal;
    double m_angle;
    std::shared_ptr<SDL_Texture> m_aTexture;
public:

    // static variable
    static std::shared_ptr<SDL_Renderer> s_pRenderer;
    static std::shared_ptr<TTF_Font> s_aLoadedFont;
    static bool loadFont(const std::string &fontPath,const int &fontSize=20);
    static bool createRenderer(std::shared_ptr<SDL_Window> &pWindow);
    static int initImgAndTff();
    static void SDLImgAndTffQuit();
    static void renderClear();
    static void renderPresent();
    static bool isAbleToRender();



    SDLDrawnObj();
    SDLDrawnObj(const SDLDrawnObj& obj);
    ~SDLDrawnObj();
    void setShownDimension(const int& x = 0, const int& y = 0, const int& w = 0, const int& h = 0);
    void setDrawPosition(const int& x = 0, const int& y = 0, const int& w = 0, const int& h = 0);
    void loadImage(const std::string &path);
    void drawImg();
};
#endif /* define (__SDLDRAWNOBJ__) */
