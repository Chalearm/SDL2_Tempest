#ifndef __SDLOBJECT_
#define __SDLOBJECT_
 

#include <SDL2/SDL_image.h>
#include <iostream>
#include <cstring>
#include "sdlRenderer.h"
#include "gameObject.h"


class SDLObject : public gameObject
{
private:

    std::shared_ptr<SDLRenderer> m_pRenderer;
	SDL_Texture* m_pTexture; // the new SDL_Texture variable
	SDL_Rect m_sourceRectangle; // the first rectangle
	SDL_Rect m_destinationRectangle; // another rectangle
    int m_flipOption; // 0 = none, 1 horizontal, 2 vertical
    std::string m_filePath;
public:

    SDLObject(const std::string &filePath);
    ~SDLObject();
    void init();
    void render();
    void update();
    void handleEvents();
    void clean();

    void setSourceRect(const int &x,const int &y,const int &w,const int &h);
    void setDestinationRect(const int &x,const int &y,const int &w,const int &h);
};


#endif /* define (__SDLOBJECT_) */
