//  
//
//     menuGame
//
//     define in header menuGame
//     
//     control all events/ drawn objects happening on the main mennu

#ifndef __MENUGAME__
#define __MENUGAME__
 
#include <iostream>
#include <cstring>
#include <list>
#include <map>
#include <ctime>
#include "sdlHandler.h"
#include "gameState.h"
#include "sdlObject.h"
#include "gameDataType.h"
#include "gameConstance.h"
#include "walkPath.h"
#include "lineWithColor.h"
#include "enemy.h"
#include "flippers.h"
#include "tanker.h"
#include "spikers.h"

class menuGame : public gameState
{
private:

    std::shared_ptr<SDLHandler> m_sdlSimpleLib;
    std::map<MainMenuObj,std::shared_ptr<SDLObject> > m_sdlObjTable;


    MainMenuObj m_oldLvSelectValue;
    MainMenuObj m_lvSelectValue;
    GameScene m_currentStage;
    std::map<GameScene,std::shared_ptr<std::vector<walkPath<double> > > >m_thelvPathTable;

    int m_playerStartPoint;
    MainMenuState m_mmState;


    void mainMenuDisplay();
    void levelSelectionDisplay();


    void goNextLv();
    void goBackLv();
    void setSelectedLvColorAndCondition(const MainMenuObj &aCondition,const color &deselectCol, const color &selectColr);
    void drawWalkPath(std::shared_ptr<std::vector<walkPath<double> > >& pObj,const point<double>& refPoint,const double &scaleVal);


    void initState();
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
    GameScene getGameState() const;
    void setWalkPath(const GameScene& selectedLv,const std::shared_ptr<std::vector<walkPath<double> > >&obj);


};


#endif /* define (__MENUGAME__) */
