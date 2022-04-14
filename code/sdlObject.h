#ifndef __SDLOBJECT_
#define __SDLOBJECT_
 
#include <iostream>
#include <cstring>
#include <SDL2/SDL.h>
#include "sdlDestroyer.h"
#include "gameObject.h"


class SDLObject : public gameObject
{
private:

    std::unique_ptr<SDL_Texture, SDLDestroyer> m_pTexture; // the new SDL_Texture variable
    std::unique_ptr<SDL_Texture, SDLDestroyer> m_pMsgTexture; // the new SDL_Texture variable
 
    std::shared_ptr<gameObject> m_pChildObj;

	SDL_Rect m_sourceRectangle; // the first rectangle
	SDL_Rect m_destinationRectangle; // another rectangle
    int m_flipOption; // 0 = none, 1 horizontal, 2 vertical
    std::string m_filePath;
  //  std::unique_ptr<TTF_Font,SDLDestroyer> m_aLoadedFont;
    bool m_isFont;
    int randomVal;
public:

    SDLObject(const std::string &filePath = "", const bool isLoadedText=false);
    ~SDLObject();

    SDLObject(const SDLObject& obj);
    void init();
    void render();
    void update();
    void handleEvents();
    void clean();

    void drawFont(const std::string &msg);

    void setRandomVal(const int randVal);
    void setSourceRect(const int &x,const int &y,const int &w,const int &h);
    void setDestinationRect(const int &x,const int &y,const int &w,const int &h);
};


#endif /* define (__SDLOBJECT_) */
