#include <vector>
#include <memory>
#include "menuGame.h"

menuGame::menuGame():
m_sdlSimpleLib(),
m_sdlObjTable(),
m_oldLvSelectValue(LABEL_LV1),
m_lvSelectValue(LABEL_LV1),
m_currentStage(MainMenu),
m_thelvPathTable(),
m_mmState(MM_init)
{

}

menuGame::menuGame(const menuGame& obj):
m_sdlSimpleLib(obj.m_sdlSimpleLib),
m_sdlObjTable(obj.m_sdlObjTable),
m_oldLvSelectValue(obj.m_oldLvSelectValue),
m_lvSelectValue(obj.m_lvSelectValue),
m_currentStage(obj.m_currentStage),
m_thelvPathTable(obj.m_thelvPathTable),
m_mmState(obj.m_mmState)
{}

menuGame::~menuGame()
{
    clean();
}

void menuGame::init()
{
    switch(m_mmState)
    {
        case MM_init:
        {
            initState();
            m_mmState = MM_running;
        }
        case MM_running:
        {
            m_lvSelectValue = LABEL_LV1;
        }
        break;
    }
    m_currentStage = MainMenu;

}
void menuGame::initState()
{

    {
        std::shared_ptr<SDLObject> gameObj(std::make_shared<SDLObject>());
        gameObj->setSDLHandler(m_sdlSimpleLib);
        gameObj->loadParameter("./space.png");
        gameObj->setShownDimension(0,0,640,480);
        gameObj->setDrawPosition(0,0,g_window_width,g_window_height);
        m_sdlObjTable[BACKGROUND_IMG] = gameObj;
    }


    {
        std::shared_ptr<SDLObject> gameObj(std::make_shared<SDLObject>());
        gameObj->setSDLHandler(m_sdlSimpleLib);
        gameObj->loadParameter("Tempest",1);
        gameObj->setColor(COLORSET[YELLOW]);
        gameObj->setShownDimension(0,0,400,50);
        gameObj->setDrawPosition(g_ratioScreen*120,g_ratioScreen*60,g_ratioScreen*400,g_ratioScreen*50);
        m_sdlObjTable[LABEL_TEMPEST] = gameObj;
    }
    
    {
        std::shared_ptr<SDLObject> gameObj(std::make_shared<SDLObject>());
        gameObj->setSDLHandler(m_sdlSimpleLib);
        gameObj->loadParameter("Press ESC to exit",1);
        gameObj->setColor(COLORSET[ORANGE]);
        gameObj->setShownDimension(0,0,200,40);
        gameObj->setDrawPosition(g_ratioScreen*20,g_ratioScreen*10,g_ratioScreen*200,g_ratioScreen*40);
        m_sdlObjTable[LABEL_EXIT] = gameObj;
    }
    {
        std::shared_ptr<SDLObject> gameObj(std::make_shared<SDLObject>());
        gameObj->setSDLHandler(m_sdlSimpleLib);
        gameObj->loadParameter("Level 1",1);
        gameObj->setColor(COLORSET[DARK_GREEN]);
        gameObj->setShownDimension(0,0,200,40);
        gameObj->setDrawPosition(g_ratioScreen*40,g_ratioScreen*340,g_ratioScreen*160,g_ratioScreen*40);
        m_sdlObjTable[LABEL_LV1] = gameObj;
    }
    {
        std::shared_ptr<SDLObject> gameObj(std::make_shared<SDLObject>());
        gameObj->setSDLHandler(m_sdlSimpleLib);
        gameObj->loadParameter("Level 2",1);
        gameObj->setColor(COLORSET[DARK_GREEN]);
        gameObj->setShownDimension(0,0,200,40);
        gameObj->setDrawPosition(g_ratioScreen*240,g_ratioScreen*340,g_ratioScreen*160,g_ratioScreen*40);
        m_sdlObjTable[LABEL_LV2] = gameObj;   
    }
    {
        std::shared_ptr<SDLObject> gameObj(std::make_shared<SDLObject>());
        gameObj->setSDLHandler(m_sdlSimpleLib);
        gameObj->loadParameter("Level 3",1);
        gameObj->setColor(COLORSET[DARK_GREEN]);
        gameObj->setShownDimension(0,0,200,40);
        gameObj->setDrawPosition(g_ratioScreen*440,g_ratioScreen*340,g_ratioScreen*160,g_ratioScreen*40);
        m_sdlObjTable[LABEL_LV3] = gameObj;     
    }
}
void menuGame::render()
{
    switch(m_currentStage)
    {
        case MainMenu:
            mainMenuDisplay();        
        break;
        default:
            // Do nothing
        break;
    }
}

void menuGame::drawWalkPath(std::shared_ptr<std::vector<walkPath<double> > >& pObj,const point<double>& refPoint,const double &scaleVal)
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
        m_sdlSimpleLib->drawLine(aPieceofAPath[LLEFT]);
        m_sdlSimpleLib->drawLine(aPieceofAPath[LEDGE]);
        m_sdlSimpleLib->drawLine(static_cast<int>(aPieceofAPath[LLEFT][P1][X]),
                                 static_cast<int>(aPieceofAPath[LLEFT][P1][Y]), 
                                 static_cast<int>(aPieceofAPath[LRIGHT][P2][X]),
                                 static_cast<int>(aPieceofAPath[LRIGHT][P2][Y]));
    }
}

void menuGame::mainMenuDisplay()
{
    if (m_sdlSimpleLib)
    {        
        m_sdlSimpleLib->setRenderDrawColor(COLORSET[BLUE]);
        m_sdlSimpleLib->renderClear();
    }

    std::map<MainMenuObj,std::shared_ptr<SDLObject> >::iterator it;
    for(it = m_sdlObjTable.begin(); it != m_sdlObjTable.end(); it++) 
    {
        it->second->render();
    }
        
    if (m_sdlSimpleLib)
    {        
        levelSelectionDisplay();
        // Select Level
        m_sdlObjTable[m_oldLvSelectValue]->setColor(COLORSET[DARK_GREEN]);
        m_sdlObjTable[m_lvSelectValue]->setColor(COLORSET[YELLOW]);
        m_sdlSimpleLib->setRenderDrawColor(COLORSET[YELLOW]);
        m_sdlSimpleLib->drawRectangle(g_ratioScreen*(20 + 200*(m_lvSelectValue - LABEL_LV1)),g_ratioScreen*150,g_ratioScreen*190,g_ratioScreen*190);
    }
}


void menuGame::setSelectedLvColorAndCondition(const MainMenuObj &aCondition,const color &deselectCol, const color &selectColr)
{
    if (m_lvSelectValue == aCondition)
    {
        m_sdlSimpleLib->setRenderDrawColor(selectColr);
    }
    else
    {
        m_sdlSimpleLib->setRenderDrawColor(deselectCol);
    }
}
void menuGame::levelSelectionDisplay()
{
    const int xStart = g_ratioScreen*40;
    const int yStart = g_ratioScreen*170;
    const int yStartLv1 = yStart + g_ratioScreen*25;
    setSelectedLvColorAndCondition(LABEL_LV1,COLORSET[BLUE],COLORSET[YELLOW]);
    m_sdlSimpleLib->drawRectangle(xStart,yStart,g_ratioScreen*150,g_ratioScreen*150);

    setSelectedLvColorAndCondition(LABEL_LV2,COLORSET[BLUE],COLORSET[YELLOW]);
    m_sdlSimpleLib->drawRectangle(g_ratioScreen*240,yStart,g_ratioScreen*150,g_ratioScreen*150);

    setSelectedLvColorAndCondition(LABEL_LV3,COLORSET[BLUE],COLORSET[YELLOW]);
    m_sdlSimpleLib->drawRectangle(g_ratioScreen*440,yStart,g_ratioScreen*150,g_ratioScreen*150);

    // Lv 1.
    setSelectedLvColorAndCondition(LABEL_LV1,COLORSET[RED],COLORSET[YELLOW]);
    drawWalkPath(m_thelvPathTable[Level1],point<double>(xStart + g_ratioScreen*25,yStartLv1),g_ratioScreen);
    // Lv 2.
    setSelectedLvColorAndCondition(LABEL_LV2,COLORSET[RED],COLORSET[YELLOW]);
    drawWalkPath(m_thelvPathTable[Level2],point<double>(xStart + g_ratioScreen*225,yStartLv1),g_ratioScreen);
    // Lv 3.
    setSelectedLvColorAndCondition(LABEL_LV3,COLORSET[RED],COLORSET[YELLOW]);
    drawWalkPath(m_thelvPathTable[Level3],point<double>(xStart + g_ratioScreen*425,yStartLv1),g_ratioScreen);
}

void menuGame::update()
{
    std::map<MainMenuObj,std::shared_ptr<SDLObject> >::iterator it;
    for(it = m_sdlObjTable.begin(); it != m_sdlObjTable.end(); it++) 
    {
        it->second->update();
    }

}

void menuGame::setWalkPath(const GameScene& selectedLv,const std::shared_ptr<std::vector<walkPath<double> > >&obj)
{
    m_thelvPathTable[selectedLv] = obj;
}


void menuGame::handleEvents(const unsigned char& keyPress)
{
   // std::cout<<((int)keyPress)<<" \n";
    if (m_currentStage == MainMenu)
    {
        switch(keyPress)
        {
            case 79:  //right arrow
                goNextLv();
            break;
            case 80:  // left arrow  
                goBackLv();
            break;
            case 13:  // enter
                switch (m_lvSelectValue)
                {
                    case LABEL_LV1:
                        m_currentStage = Level1;
                    break;
                    case LABEL_LV2:
                        m_currentStage = Level2;
                    break;
                    case LABEL_LV3:
                        m_currentStage = Level3;
                    break;
                    default:
                        m_currentStage = MainMenu;
                    break;
                }
            break;
        }
    }
    else
    {
        // Do nothing
    }
    std::map<MainMenuObj,std::shared_ptr<SDLObject> >::iterator it;
    for(it = m_sdlObjTable.begin(); it != m_sdlObjTable.end(); it++) 
    {
        it->second->handleEvents();
    }
}

void menuGame::goNextLv()
{
    m_oldLvSelectValue = m_lvSelectValue;
    switch(m_lvSelectValue)
    {
        case LABEL_LV1:
            m_lvSelectValue = LABEL_LV2;
        break;
        case LABEL_LV2:
            m_lvSelectValue = LABEL_LV3;
        break;
        default:
            m_lvSelectValue = LABEL_LV1;
        break;
    }
}

GameScene menuGame::getGameState() const
{
    return m_currentStage;
}
void menuGame::goBackLv()
{
    m_oldLvSelectValue = m_lvSelectValue;
    switch(m_lvSelectValue)
    {
        case LABEL_LV3:
            m_lvSelectValue = LABEL_LV2;
        break;
        case LABEL_LV2:
            m_lvSelectValue = LABEL_LV1;
        break;
        default:
            m_lvSelectValue = LABEL_LV3;
        break;
    }
}
void menuGame::clean()
{
    // Do nothing
}
void menuGame::setSDLHandler(const std::shared_ptr<SDLHandler> &obj)
{
    m_sdlSimpleLib = obj;
}
