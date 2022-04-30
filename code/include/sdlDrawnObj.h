//  
//
//     SDLDrawnObj
//
//     define in header SDLDrawnObj
//     class SDLDrawnObj
//     
//     it controls fonnt and image displayed on screen by SDL library
//



#ifndef __SDLDRAWNOBJ__
#define __SDLDRAWNOBJ__
 
#include <iostream>
#include <cstring>
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "sdlDestroyer.h"
#include "gameObj.h"
#include "color.h"

class SDLDrawnObj : public gameObj
{
private:
    SDL_Rect m_sourceRect;
    SDL_Rect m_destRect;
    color m_txtColor; 
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
    SDLDrawnObj& operator=(const SDLDrawnObj& obj);
    void setShownDimension(const int& x = 0, const int& y = 0, const int& w = 0, const int& h = 0);
    void setDrawPosition(const int& x = 0, const int& y = 0, const int& w = 0, const int& h = 0);
    void loadImage(const std::string &path);
    void loadParameter(const std::string &txt = "",const int& opt = 0);
    void setText(const std::string &msg);
    void setAngel(const double& ang = 0.0);
    void setColor(const color& aColor);
    void drawImg();
    void drawImgEx();
    void rotateFromCurrentPos(const double& deltaAng = 0.0);
    void moveFromCurrentPos(const int& deltaX = 0,const int& deltaY = 0);

};
#endif /* define (__SDLDRAWNOBJ__) */
