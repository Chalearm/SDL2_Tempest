//  
//
//     SDLObject
//
//     define in header SDLObject
//     class SDLObject
//     
//     It controls not only drawing of SDL objects on the game screen but also 
//     controls the state machine (game state) of them in the game cycle or SDL cycle
//


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

    std::shared_ptr<SDLHandler> m_sdlSimpleLib;
    std::shared_ptr<gameState> m_pChildObj;
    std::string m_filePath;
    int m_loadedOpt;
    int randomVal;
public:

    SDLObject(const std::string &filePath = "", const bool isLoadedText=false);
    SDLObject(const SDLObject& obj);
    ~SDLObject();

    void loadParameter(const std::string &txt = "",const int& opt = 0);
    void init();
    void render();
    void update();
    void handleEvents(const unsigned char& keyPress = 0);
    void clean();
    void setSDLHandler(const std::shared_ptr<SDLHandler> &obj);
    void setRandValue(const int& val = 0);
};


#endif /* define (__SDLOBJECT_) */
