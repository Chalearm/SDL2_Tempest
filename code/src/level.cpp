#include "level.h"

level::level():
m_sdlSimpleLib(),
m_sdlObjTable(),
m_currentStage(Level1),
m_thelvPath()
{

}
level::level(const level& obj):
m_sdlSimpleLib(obj.m_sdlSimpleLib),
m_sdlObjTable(obj.m_sdlObjTable),
m_currentStage(obj.m_currentStage),
m_thelvPath(obj.m_thelvPath)
{

}

level::~level()
{

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
    }
    else
    {
        // Do nothing
    }
    return *this;
}
void level::levelsKeyboardHandle(const unsigned char &val)
{
    switch(val)
    {
        case 8: // back space
            m_currentStage = MainMenu;
        break;
        case 79:  //right arrow
            moveNextAreaOfPlayer(m_thelvPath);
        break;
        case 80:  // left arrow
            moveBackAreaOfPlayer(m_thelvPath);
        break;
        default:
        break;
    }
}
void level::createEnemies(std::shared_ptr<std::vector<walkPath<double> > >& lvPathObj,const point<double>& refPoint,std::list<std::shared_ptr<enemy> >& alist)
{
   // std::cout<<" start random \n";
    for (int i = 0; i < m_numberOfEnemy; i++)
    {
        switch (randomEnemyTp())
        {
            case TANKER:
            {
                std::shared_ptr<tanker> aPTanker(new tanker(lvPathObj,g_lvScale,g_refPoint*g_ratioScreen));
                alist.push_back(aPTanker); 
            }
            break;
            case SPIKERS:
            {
                std::shared_ptr<spikers> aPSpikers(new spikers(lvPathObj,g_lvScale,g_refPoint*g_ratioScreen));
                alist.push_back(aPSpikers); 
            }
            break;
            case FLIPPERS:
            {
                std::shared_ptr<flippers> aPTFlippers(new flippers(lvPathObj,g_lvScale,g_refPoint*g_ratioScreen));
                alist.push_back(aPTFlippers); 
            }
            break;
            default:
            {
                std::shared_ptr<tanker> aPTanker(new tanker(lvPathObj,g_lvScale,g_refPoint*g_ratioScreen));
                alist.push_back(aPTanker); 
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
    tanker aTanker(m_thelvPath,g_lvScale,g_refPoint*g_ratioScreen);
    int ranVal = static_cast<int>(aTanker.randomFn(99.0,0.0));
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
void level::renderEnemied()
{

    color col = COLORSET[NOCOLOR];
    std::list<std::shared_ptr<enemy> >::iterator it;
    for (it = m_enemyList.begin(); it != m_enemyList.end(); ++it)
    {
        if (it->get()->isAlive())
        {
            std::vector<lineWithColor> lineSet = it->get()->drawEnemy();
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
    m_sdlObjTable[BACKGROUNDLV_IMG]->render();
    m_sdlObjTable[BACK_TO_MAINMENU]->render();
    m_sdlSimpleLib->setRenderDrawColor(COLORSET[BLUE]);
    drawWalkPath(m_thelvPath,g_refPoint*g_ratioScreen,g_lvScale,true);
    renderEnemied();
}

void level::update()
{

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