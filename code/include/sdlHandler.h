//  
//
//     SDLHandler
//
//     define in header SDLHandler
//     class SDLHandler
//     
//     It controls the game screen or game window and 
//     provides the screen for drawinng texture and text message by SDL library
//

#ifndef __SDLHANDLER_
#define __SDLHANDLER_
 
#include <iostream>
#include <cstring>
#include <vector>
#include <SDL2/SDL.h>
#include "sdlDestroyer.h"
#include "sdlDrawnObj.h"
#include "gameState.h"
#include "gameObj.h"
#include "color.h"
#include "gameConstance.h"
#include "gameDataType.h"
#include "aLine.h"

class SDLHandler : public gameState
{
private:

    std::shared_ptr<SDL_Window> m_pWindow;

	std::string m_titleMessage;
	int m_windowWidth;
	int m_windowheight;
	bool m_isAbleToRun;
	std::shared_ptr<gameState> m_gameActivist;

protected:
    SDLHandler(const std::string &windowTitle = "Tempest Game",const int &windowWidth = g_window_width, const int &windowHeight = g_window_height);
    static std::shared_ptr<SDLHandler> theSdlHandler;
public:

    /*
    *  It should not be cloneable.
    */
    ~SDLHandler();

    static std::shared_ptr<SDLHandler> GetInstance(const std::string &windowTitle = "Tempest Game",const int &windowWidth = g_window_width, const int &windowHeight = g_window_height);
    void setTheActivist(std::shared_ptr<gameState> anObj);
    void setNewWindowTitle(const std::string &windowTitle = "Tempest Game");
    void init();
    void render();
    void update();
    void handleEvents(const unsigned char& keyPress = 0);
    void clean();
    bool isAbleToRun(); 

    void setRenderDrawColor(const color& aColor);

    std::shared_ptr<gameObj> loadImage(const std::string &path, int &id);
    void renderClear();

    void drawLine(const int& x1, const int& y1, const int& x2, const int& y2);
    void drawLine(const aLine<double>& line );

    void drawRectangle(const int& x1, const int& y1, const int& w, const int& h);

};


#endif /* define (__SDLHANDLER_) */
