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

class SDLHandler : public gameState
{
private:

    std::shared_ptr<SDL_Window> m_pWindow;
   // std::vector<std::shared_ptr<SDLDrawnObj> > m_sdlDrawnObjList;

	std::string m_titleMessage;
	int m_windowWidth;
	int m_windowheight;
	bool m_isAbleToRun;
	std::shared_ptr<gameState> m_gameActivist;

protected:
    SDLHandler(const std::string &windowTitle = "Tempest Game",const int &windowWidth = 640, const int &windowHeight = 480);
    static std::shared_ptr<SDLHandler> theSdlHandler;
public:

    /*
    *  It should not be cloneable.
    */
    //SDLHandler(const SDLHandler &obj) = delete;
    ~SDLHandler();

  //  void operator=(const SDLHandler &) = delete;
    static std::shared_ptr<SDLHandler> GetInstance(const std::string &windowTitle = "Tempest Game",const int &windowWidth = 640, const int &windowHeight = 480);
    void setTheActivist(std::shared_ptr<gameState> anObj);
    void setNewWindowTitle(const std::string &windowTitle = "Tempest Game");
    void init();
    void render();
    void update();
    void handleEvents(const unsigned char& keyPress = 0);
    void clean();
    bool isAbleToRun(); 


   // std::shared_ptr<SDL_Renderer> getRenderer();
    void setRenderDrawColor(const color& aColor);

    std::shared_ptr<gameObj> loadImage(const std::string &path, int &id);
    void renderClear();
    /*
    int addText(const std::string &text,const unsigned char &r,const unsigned char &g, const unsigned char &b);

    void drawText(const int &textId, const int &x, const int &y, const int& w, const int& h);
    void drawImg(const int &imgId, const int &x, const int &y, const int& w, const int& h);
    */
    //void setPenColor(const unsigned char& r, const unsigned char& g, const unsigned char& b, const unsigned char& a);
    void drawLine(const int& x1, const int& y1, const int& x2, const int& y2);

    void drawRectangle(const int& x1, const int& y1, const int& w, const int& h);

};


#endif /* define (__SDLHANDLER_) */
