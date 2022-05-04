//  
//
//     Level
//
//     define in header Level
//     
//     control all events/ drawn objects happening on the Level

#ifndef __LEVEL__
#define __LEVEL__
 
#include <iostream>
#include <cstring>
#include <list>
#include <map>
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

class level : public gameState, public gameMessage
{
private:

    std::shared_ptr<SDLHandler> m_sdlSimpleLib;
    std::map<LevelObj,std::shared_ptr<SDLObject> > m_sdlObjTable;

    std::shared_ptr<std::vector<walkPath<double> > > m_thelvPath;

    /*
       random enemy type - criteria 
       0 - 70  --> spikers
       71 - 96 --> tanker
       97 - 99 --> flippers
    */
    std::list<std::shared_ptr<enemy> > m_enemyList;


    int m_playerStartPoint;
    LevelState m_lvState;

    void initState();

protected:
    int m_numberOfEnemy;
    GameScene m_currentStage;
    void setWalkPathSet(const std::shared_ptr<std::vector<walkPath<double> > >& obj);
    void levelsKeyboardHandle(const unsigned char &val = 0);
    void createEnemies(std::shared_ptr<std::vector<walkPath<double> > >& lvPathObj,const point<double>& refPoint,std::list<std::shared_ptr<enemy> >& alist);
    EnemyType randomEnemyTp();
    void renderEnemied();
    void drawWalkPath(std::shared_ptr<std::vector<walkPath<double> > >& pObj,const point<double>& refPoint,const double &scaleVal = 1.0, const bool& isDrawnPlayer = false);
    void drawPlayerPosition(const std::vector<walkPath<double> >& obj,const point<double>& refPoint,const double& scale);
    void moveNextAreaOfPlayer(std::shared_ptr<std::vector<walkPath<double> > >& obj);
    void moveBackAreaOfPlayer(std::shared_ptr<std::vector<walkPath<double> > >& obj);
public:

    level();
    level(const level& obj);
    ~level();
    level& operator=(const level& obj);

    void init();
    void render();
    void update();
    void handleEvents(const unsigned char& keyPress = 0);
    void clean();
    void setSDLHandler(const std::shared_ptr<SDLHandler> &obj);
    GameScene getGameState() const;
};


#endif /* define (__LEVEL__) */
