#ifndef __MENUGAME__
#define __MENUGAME__
 
#include <iostream>
#include <cstring>
#include <list>
#include <map>
#include <ctime>
#include "gameMessage.h"
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

class menuGame : public gameState, public gameMessage
{
private:

    std::shared_ptr<SDLHandler> m_sdlSimpleLib;
    std::map<MainMenuObj,std::shared_ptr<SDLObject> > m_sdlObjTable;


    MainMenuObj m_oldLvSelectValue;
    MainMenuObj m_lvSelectValue;
    GameScene m_currentStage;
    std::shared_ptr<std::vector<walkPath<double> > > m_thelv1Path;
    std::shared_ptr<std::vector<walkPath<double> > > m_thelv2Path;
    std::shared_ptr<std::vector<walkPath<double> > > m_thelv3Path;

    /*
       random enemy type - criteria 
       0 - 70  --> spikers
       71 - 96 --> tanker
       97 - 99 --> flippers
    */
    std::list<std::shared_ptr<enemy> > m_enemyList;


    int m_playerStartPoint;


    void mainMenuDisplay();
    void levelSelectionDisplay();

    //void drawLvSelection(constexpr int& xStart = 0, constexpr int& yStart = 0,);

    void goNextLv();
    void goBackLv();

    void levelsKeyboardHandle(const unsigned char &val = 0);
    void createEnemies(std::shared_ptr<std::vector<walkPath<double> > >& lvPathObj,const point<double>& refPoint,std::list<std::shared_ptr<enemy> >& alist);
    EnemyType randomEnemyTp();
    void renderEnemied();
    void setSelectedLvColorAndCondition(const MainMenuObj &aCondition,const color &deselectCol, const color &selectColr);
    void drawWalkPath(std::shared_ptr<std::vector<walkPath<double> > >& pObj,const point<double>& refPoint,const double &scaleVal = 1.0, const bool isDrawnPlayer = false);
    void drawPlayerPosition(const std::vector<walkPath<double> >& obj,const point<double>& refPoint,const double& scale);
    void moveNextAreaOfPlayer(std::shared_ptr<std::vector<walkPath<double> > >& obj);
    void moveBackAreaOfPlayer(std::shared_ptr<std::vector<walkPath<double> > >& obj);
    std::shared_ptr<std::vector<walkPath<double> > >& switchWalkPathByLv(const GameScene& val = Level1);
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
  //  void setRandValue(const int& val = 0);


};


#endif /* define (__MENUGAME__) */
