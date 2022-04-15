#ifndef __MENUGAME__
#define __MENUGAME__
 
#include <iostream>
#include <cstring>
#include <vector>
#include <ctime>
#include "sdlHandler.h"
#include "gameState.h"
#include "sdlObject.h"


class menuGame : public gameState
{
private:

    std::shared_ptr<SDLHandler> m_sdlSimpleLib;
    std::vector<std::shared_ptr<SDLObject> > m_sdlObjList;
    int randomVal;
public:

    menuGame();
    menuGame(const menuGame& obj);
    ~menuGame();

    void init();
    void render();
    void update();
    void handleEvents(const unsigned char& keyPress = 0);
    void clean();
    void setSDLHandler(const std::shared_ptr<SDLHandler> &obj);
    void setRandValue(const int& val = 0);
};


#endif /* define (__MENUGAME__) */
