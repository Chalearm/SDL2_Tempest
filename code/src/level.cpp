#include "level.h"

level::level():
m_sdlSimpleLib(),
m_sdlObjTable(),
m_thelvPath(),
m_bullets(),
m_lvState(LV_init),
m_numberOfEnemy(g_numberOfEnemies_Lv1),
m_currentStage(Level1),
m_enemyList()
{
}
level::level(const level& obj):
m_sdlSimpleLib(obj.m_sdlSimpleLib),
m_sdlObjTable(obj.m_sdlObjTable),
m_thelvPath(obj.m_thelvPath),
m_bullets(obj.m_bullets),
m_lvState(obj.m_lvState),
m_numberOfEnemy(obj.m_numberOfEnemy),
m_currentStage(obj.m_currentStage),
m_enemyList(obj.m_enemyList)
{

}

level::~level()
{

}

GameScene level::getGameState() const
{
    return m_currentStage;
}
void level::setWalkPathSet(const std::shared_ptr<std::vector<walkPath<double> > >& obj)
{
    m_thelvPath = obj;
}

level& level::operator=(const level& obj)
{
    if (this != &obj)
    {
        m_sdlSimpleLib = obj.m_sdlSimpleLib;
        m_sdlObjTable = obj.m_sdlObjTable;
        m_currentStage = obj.m_currentStage;
        m_thelvPath = obj.m_thelvPath;
        m_bullets = obj.m_bullets;
        m_numberOfEnemy = obj.m_numberOfEnemy;
        m_lvState = obj.m_lvState;
        m_enemyList = obj.m_enemyList;
    }
    else
    {
        // Do nothing
    }
    return *this;
}

void level::createBullet(std::shared_ptr<std::vector<walkPath<double> > >& lvPathObj,const point<double>& refPoint,std::map<int,std::list<std::shared_ptr<ammunition > > >& aBulletTable)
{
   const int l_playerLane = m_playerStartPoint;
   std::shared_ptr<ammunition> aPBullet(new ammunition(lvPathObj,g_lvScale,refPoint,l_playerLane));
   aBulletTable[l_playerLane].push_back(aPBullet); 
}
void level::levelsKeyboardHandle(const unsigned char &val)
{
    switch(val)
    {
        case 8: // back space
            m_currentStage = MainMenu;
            m_enemyList.clear();
        break;
        case 79:  //right arrow
            moveNextAreaOfPlayer(m_thelvPath);
        break;
        case 80:  // left arrow
            moveBackAreaOfPlayer(m_thelvPath);
        break;
        case 32: // create bullet
            createBullet(m_thelvPath,g_refPoint*g_ratioScreen,m_bullets);
        break;
        default:
            // std::cout<<(int)val<<std::endl;
        break;
    }
}

void level::createEnemies(std::shared_ptr<std::vector<walkPath<double> > >& lvPathObj,const point<double>& refPoint,std::map<int,std::list<std::shared_ptr<enemy > > >& anEnemyTable)
{    
    anEnemyTable.clear();
    for (int i = 0; i < m_numberOfEnemy; i++)
    {
        
        switch (randomEnemyTp())
        {
            case TANKER:
            {
               std::shared_ptr<tanker> aPTanker(new tanker(lvPathObj,g_lvScale,refPoint));
               anEnemyTable[aPTanker->getCurrentBeingLane()].push_back(aPTanker);
            }
            break;
            case SPIKERS:
            {
                std::shared_ptr<spikers> aPSpikers(new spikers(lvPathObj,g_lvScale,refPoint));
                anEnemyTable[aPSpikers->getCurrentBeingLane()].push_back(aPSpikers);
            }
            break;
            case FLIPPERS:
            {
                std::shared_ptr<flippers> aPTFlippers(new flippers(lvPathObj,g_lvScale,refPoint));
                anEnemyTable[aPTFlippers->getCurrentBeingLane()].push_back(aPTFlippers);
            }
            break;
            default:
            {
                std::shared_ptr<tanker> aPTanker(new tanker(lvPathObj,g_lvScale,refPoint));
                anEnemyTable[aPTanker->getCurrentBeingLane()].push_back(aPTanker);
            }
            break;
        }
        
    }
}

EnemyType level::randomEnemyTp()
{
  /*
       random enemy type - criteria 
       0 - 70  --> spikers
       71 - 95 --> tanker
       96 - 99 --> flippers
    */
    EnemyType retVal = TANKER;
    std::shared_ptr<tanker> aPTanker(new tanker(m_thelvPath,g_lvScale,g_refPoint*g_ratioScreen));
    int ranVal = static_cast<int>(aPTanker->randomFn(99.0,0.0));
    if (ranVal <= 70)
    {
        // do nothing
    }
    else if (ranVal <= 95)
    {
        retVal = SPIKERS;
    }
    else
    {
        retVal = FLIPPERS;
    }
    return retVal;
}

void level::renderBullets()
{
    // bullet
    color col = COLORSET[NOCOLOR];
    for (std::map<int,std::list<std::shared_ptr<ammunition > > >::iterator it = m_bullets.begin(); it != m_bullets.end(); ++it)
    { 
        std::list<std::shared_ptr<ammunition> >::iterator it3;
        for (it3 = it->second.begin(); it3 != it->second.end(); ++it3 )
        {
            std::vector<lineWithColor> lineSet = it3->get()->draw();
            for (int j = 0; j < lineSet.size(); j++)
            {

                if (col != lineSet[j].getColor())
                {
                    col = lineSet[j].getColor();
                    m_sdlSimpleLib->setRenderDrawColor(col);
                }
                else
                {
                    // Do nothing
                }
                m_sdlSimpleLib->drawLine(lineSet[j].getLine());
            }
        }
    }
}

void level::renderEnemied()
{
    color col = COLORSET[NOCOLOR];
    for (std::map<int,std::list<std::shared_ptr<enemy > > >::iterator it = m_enemyList.begin(); it != m_enemyList.end(); ++it)
    {
        std::list<std::shared_ptr<enemy> >::iterator it2;
        for (it2 = it->second.begin(); it2 != it->second.end(); ++it2 )
            if (it2->get()->isAlive())
            {
                std::vector<lineWithColor> lineSet = it2->get()->drawEnemy();
                for (int j = 0; j < lineSet.size(); j++)
                {
                    if (col != lineSet[j].getColor())
                    {
                        col = lineSet[j].getColor();
                        m_sdlSimpleLib->setRenderDrawColor(col);
                    }
                    else
                    {
                        // Do nothing
                    }
                    m_sdlSimpleLib->drawLine(lineSet[j].getLine());
                }
            }
            else
            {
                // Do nothing
            }
    }
}

void level::drawWalkPath(std::shared_ptr<std::vector<walkPath<double> > >& pObj,const point<double>& refPoint,const double &scaleVal, const bool& isDrawnPlayer)
{ 
    for(int i = 0; i < pObj->size(); i++)
    {
        // scale 1.0
       
        walkPath<double> aPieceofAPath;
        if (scaleVal != 1.0)
        {
            aPieceofAPath = (pObj->at(i)*scaleVal).translate(refPoint);
        } 
        else
        {
            aPieceofAPath = pObj->at(i).translate(refPoint);
        }

        if (((i-1) != m_playerStartPoint) || (isDrawnPlayer == false))
        {
            m_sdlSimpleLib->drawLine(aPieceofAPath[LLEFT]);
        }

        m_sdlSimpleLib->drawLine(aPieceofAPath[LEDGE]);


        m_sdlSimpleLib->drawLine(static_cast<int>(aPieceofAPath[LLEFT][P1][X]),
                                 static_cast<int>(aPieceofAPath[LLEFT][P1][Y]), 
                                 static_cast<int>(aPieceofAPath[LRIGHT][P2][X]),
                                 static_cast<int>(aPieceofAPath[LRIGHT][P2][Y]));

        if ((i == m_playerStartPoint) && (isDrawnPlayer == true) )
        {
        
            m_sdlSimpleLib->setRenderDrawColor(COLORSET[YELLOW]);
            m_sdlSimpleLib->drawLine(aPieceofAPath[LLEFT]);
            m_sdlSimpleLib->drawLine(aPieceofAPath[LEDGE]);
            m_sdlSimpleLib->drawLine(aPieceofAPath[LRIGHT]);
            m_sdlSimpleLib->setRenderDrawColor(COLORSET[BLUE]);

        }
    }
}

void level::moveNextAreaOfPlayer(std::shared_ptr<std::vector<walkPath<double> > >& obj)
{
    m_playerStartPoint++;
    if (m_playerStartPoint >= obj->size() )
    {
        m_playerStartPoint = 0;
    }
    else
    {
        // Do nothing
    }
}
void level::moveBackAreaOfPlayer(std::shared_ptr<std::vector<walkPath<double> > >& obj)
{
    m_playerStartPoint--;
    if (m_playerStartPoint < 0 )
    {
        m_playerStartPoint = obj->size() - 1;
    }
    else
    {
        // Do nothing
    }
}

void level::init()
{//GAME_OVER
    switch (m_lvState)
    {
        case LV_init:
        {
            initState();
            m_lvState =  LV_running;
        }
        break;
        case LV_running:
        {
            m_playerStartPoint = 0;
            m_bullets.clear();
            createEnemies(m_thelvPath,g_refPoint*g_ratioScreen,m_enemyList);      
        }
        break;
        default:

        break;
    }
}

void level::initState()
{
    {
        std::shared_ptr<SDLObject> gameObj(std::make_shared<SDLObject>());
        gameObj->setSDLHandler(m_sdlSimpleLib);
        gameObj->loadParameter("./space.png");
        gameObj->setShownDimension(0,0,640,480);
        gameObj->setDrawPosition(0,0,g_window_width,g_window_height);
        m_sdlObjTable[BACKGROUNDLV_IMG] = gameObj;
    }
    {
        std::shared_ptr<SDLObject> gameObj(std::make_shared<SDLObject>());
        gameObj->setSDLHandler(m_sdlSimpleLib);
        gameObj->loadParameter("Press BK Space to Menu",1);
        gameObj->setColor(COLORSET[ORANGE]);
        gameObj->setShownDimension(0,0,260,40);
        gameObj->setDrawPosition(g_ratioScreen*20,g_ratioScreen*10,g_ratioScreen*260,g_ratioScreen*40);
        m_sdlObjTable[BACK_TO_MAINMENU] = gameObj;
    }
    {
        std::shared_ptr<SDLObject> gameObj(std::make_shared<SDLObject>());
        gameObj->setSDLHandler(m_sdlSimpleLib);
        gameObj->loadParameter("GAME OVER",1);
        gameObj->setColor(COLORSET[MAGENTA]);
        gameObj->setShownDimension(0,0,260,40);
        gameObj->setDrawPosition(g_ratioScreen*20,g_ratioScreen*20,g_ratioScreen*260,g_ratioScreen*40);
        m_sdlObjTable[GAME_OVER] = gameObj;
    }
}
void level::render()
{
    if (m_sdlSimpleLib)
    {
        m_sdlObjTable[BACKGROUNDLV_IMG]->render();
        m_sdlObjTable[BACK_TO_MAINMENU]->render();
        m_sdlSimpleLib->setRenderDrawColor(COLORSET[BLUE]);
        drawWalkPath(m_thelvPath,g_refPoint*g_ratioScreen,g_lvScale,true);
        renderEnemied();
        renderBullets();
    }
    else
    {
        // Do nothing
    }

}

void level::update()
{
    for(std::map<LevelObj,std::shared_ptr<SDLObject> >::iterator it = m_sdlObjTable.begin(); it != m_sdlObjTable.end(); it++) 
    {
        it->second->update();
    }

    bool isEnemyKilled = false;
    for (std::map<int,std::list<std::shared_ptr<enemy > > >::iterator it = m_enemyList.begin(); it != m_enemyList.end(); ++it)
    {

        std::list<std::shared_ptr<enemy> >::iterator it2;
        for (it2 = it->second.begin(); it2 != it->second.end(); ++it2 )
        {
            std::map<int,std::list<std::shared_ptr<ammunition > > >::iterator it4 = m_bullets.find(it->first);
            // check bullet - there are some bullet in the same lane
            if (it4 != m_bullets.end())
            {
                if (m_bullets[it->first].size() > 0)
                {
                   const double bulletDist = m_bullets[it->first].front()->getCurrentPos();
                   const double enemyDist = it2->get()->getCurrentPos();
                   if (enemyDist >= bulletDist) // killed enemy
                   {
                    // score update

                     it2 = m_enemyList[it->first].erase(it2);
                     m_bullets[it->first].pop_front();
                     isEnemyKilled = true;
                   }
                }
            }
           
            if (isEnemyKilled)
            {
                isEnemyKilled = false;
            }
            else if (it2->get()->transform() && (it2->get()->getMyType() == TANKER))
            {
                const double curPos = it2->get()->getCurrentPos();

                std::shared_ptr<flippers> aPTFlippers(new flippers(m_thelvPath,g_lvScale,g_refPoint*g_ratioScreen));
                std::shared_ptr<flippers> aPTFlippers2(new flippers(m_thelvPath,g_lvScale,g_refPoint*g_ratioScreen));
                aPTFlippers->setCurrentPos(curPos+aPTFlippers->randomFn(-0.3,-0.6));
                aPTFlippers2->setCurrentPos(curPos+aPTFlippers->randomFn(-0.3,-0.6));
                m_enemyList[aPTFlippers->getCurrentBeingLane()].push_back(aPTFlippers);
                m_enemyList[aPTFlippers2->getCurrentBeingLane()].push_back(aPTFlippers2);
                it2 = m_enemyList[it->first].erase(it2);
             
            }
            else
            {
                it2->get()->move();
            }    
        }

    }

    // bullet
    for (std::map<int,std::list<std::shared_ptr<ammunition > > >::iterator it = m_bullets.begin(); it != m_bullets.end(); ++it)
    { 
        std::list<std::shared_ptr<ammunition> >::iterator it3;
        for (it3 = it->second.begin(); it3 != it->second.end(); ++it3 )
        {
            if (it3->get()->getCurrentPos() < 0.02)
            {
                it3 = m_bullets[it->first].erase(it3);
            }
            else
            {
                it3->get()->move();
            }

        }
    }
}

std::shared_ptr<std::vector<walkPath<double> > > level::getWalkPaht()const
{
    return m_thelvPath;
}

void level::handleEvents(const unsigned char& keyPress)
{
    levelsKeyboardHandle(keyPress);
}
void level::clean()
{

}
void level::setSDLHandler(const std::shared_ptr<SDLHandler> &obj)
{
    m_sdlSimpleLib = obj;
}
