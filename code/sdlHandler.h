#ifndef __SDLHANDLER_
#define __SDLHANDLER_
 
#include <iostream>
#include <cstring>
#include <vector>
#include <SDL2/SDL.h>
#include "sdlDestroyer.h"
#include "sdlDrawnObj.h"
#include "gameObject.h"

class SDLHandler : public gameObject
{
private:

    std::shared_ptr<SDL_Window> m_pWindow;
    std::vector<SDLDrawnObj> m_sdlDrawnObjList;

	std::string m_titleMessage;
	int m_windowWidth;
	int m_windowheight;
	bool m_isAbleToRun;
	std::shared_ptr<gameObject> m_gameActivist;


public:

    SDLHandler(const std::string &windowTitle = "Tempest Game",const int &windowWidth = 640, const int &windowHeight = 480);
    ~SDLHandler();
    void setTheActivist(std::shared_ptr<gameObject> anObj);
    void setNewWindowTitle(const std::string &windowTitle = "Tempest Game");
    void init();
    void render();
    void update();
    void handleEvents();
    void clean();
    bool isAbleToRun(); 


   // std::shared_ptr<SDL_Renderer> getRenderer();

    int loadImage(const std::string &path);
    /*
    int addText(const std::string &text,const unsigned char &r,const unsigned char &g, const unsigned char &b);

    void drawText(const int &textId, const int &x, const int &y, const int& w, const int& h);
    void drawImg(const int &imgId, const int &x, const int &y, const int& w, const int& h);
    */


};


#endif /* define (__SDLHANDLER_) */
