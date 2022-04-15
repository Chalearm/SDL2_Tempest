#ifndef __SDLOBJECT_
#define __SDLOBJECT_
 
#include <iostream>
#include <cstring>
#include <ctime>
#include "sdlHandler.h"
#include "gameState.h"
#include "sdlDrawnObj.h"


class SDLObject : public gameState, public SDLDrawnObj
{
private:

    int m_objectId;
    std::shared_ptr<SDLHandler> m_sdlSimpleLib;
    std::shared_ptr<gameState> m_pChildObj;
    std::string m_filePath;
    int randomVal;
public:

    SDLObject(const std::string &filePath = "", const bool isLoadedText=false);
    SDLObject(const SDLObject& obj);
    ~SDLObject();

    void init();
    void render();
    void update();
    void handleEvents();
    void clean();
    void setSDLHandler(const std::shared_ptr<SDLHandler> &obj);
    void setRandValue(const int& val = 0);
};


#endif /* define (__SDLOBJECT_) */
