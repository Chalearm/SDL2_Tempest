#ifndef __MENUGAME__
#define __MENUGAME__
 
#include <iostream>
#include <cstring>
#include <map>
#include <ctime>
#include "gameMessage.h"
#include "sdlHandler.h"
#include "gameState.h"
#include "sdlObject.h"
#include "gameDataType.h"
#include "gameConstance.h"

class menuGame : public gameState, public gameMessage
{
private:

    std::shared_ptr<SDLHandler> m_sdlSimpleLib;
    std::map<MainMenuObj,std::shared_ptr<SDLObject> > m_sdlObjTable;
    int randomVal;


    MainMenuObj m_oldLvSelectValue;
    MainMenuObj m_lvSelectValue;
    GameScene m_currentStage;

    void mainMenuDisplay();
    void levelSelectionDisplay();

    void goNextLv();
    void goBackLv();
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
