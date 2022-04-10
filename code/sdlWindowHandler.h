#ifndef __SDLWINDOWHANDLER_
#define __SDLWINDOWHANDLER_
 
#include <iostream>
#include <cstring>
#include "sdlRenderer.h"
#include "gameObject.h"

class SDLWindowHandler : public gameObject
{
private:

    struct SDLWindowDestroyer
    {
        void operator()(SDL_Window* w) const
        {
            SDL_DestroyWindow(w);
        }
    };

    std::unique_ptr<SDL_Window, SDLWindowDestroyer> m_pWindow;
    SDLRenderer m_pRenderer;
	std::string m_titleMessage;
	int m_windowWidth;
	int m_windowheight;
	bool m_isAbleToRun;
	std::shared_ptr<gameObject> m_gameActivist;
public:

    SDLWindowHandler(const std::string &windowTitle = "Tempest Game",const int &windowWidth = 640, const int &windowHeight = 480);
    ~SDLWindowHandler();
    void setTheActivist(std::shared_ptr<gameObject> &anObj);
    void setNewWindowTitle(const std::string &windowTitle = "Tempest Game");
    void init();
    void render();
    void update();
    void handleEvents();
    void clean();
};


#endif /* define (__SDLWINDOWHANDLER_) */
