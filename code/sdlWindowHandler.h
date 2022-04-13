#ifndef __SDLWINDOWHANDLER_
#define __SDLWINDOWHANDLER_
 
#include <iostream>
#include <cstring>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "sdlRenderer.h"
#include "gameObject.h"

class SDLWindowHandler : public gameObject
{
private:

    struct SDLWindowDestroyer
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
    };

    std::unique_ptr<SDL_Window, SDLWindowDestroyer> m_pWindow;
    std::shared_ptr<SDLRenderer>  m_pRenderer;
	std::string m_titleMessage;
	int m_windowWidth;
	int m_windowheight;
	bool m_isAbleToRun;
	std::shared_ptr<gameObject> m_gameActivist;
public:

    SDLWindowHandler(const std::string &windowTitle = "Tempest Game",const int &windowWidth = 640, const int &windowHeight = 480);
    ~SDLWindowHandler();
    void setTheActivist(std::shared_ptr<gameObject> anObj);
    void setNewWindowTitle(const std::string &windowTitle = "Tempest Game");
    void init();
    void render();
    void update();
    void handleEvents();
    void clean();
    bool isInitiated();
    std::shared_ptr<SDLRenderer> getRenderer();
};


#endif /* define (__SDLWINDOWHANDLER_) */
