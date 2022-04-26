#include <vector>
#include "menuGame.h"

menuGame::menuGame():
m_sdlSimpleLib(),
m_sdlObjTable(),
m_oldLvSelectValue(LABEL_LV1),
m_lvSelectValue(LABEL_LV1),
m_currentStage(MainMenu),
m_thelv1Path(),
m_thelv2Path(),
m_thelv3Path(),
m_playerStartPoint(0)
{

m_thelv1Path.push_back(walkPath<double>(
                point<double>(40,60),
                point<double>(0,0),
                point<double>(25,0),
                point<double>(45,60)));
m_thelv1Path.push_back(walkPath<double>(
                point<double>(45,60),
                point<double>(25,0),
                point<double>(50,0),
                point<double>(50,60)));
m_thelv1Path.push_back(walkPath<double>(
                point<double>(50,60),
                point<double>(50,0),
                point<double>(75,0),
                point<double>(55,60)));
m_thelv1Path.push_back(walkPath<double>(
                point<double>(55,60),
                point<double>(75,0),
                point<double>(100,0),
                point<double>(60,60)));

m_thelv1Path.push_back(walkPath<double>(
                point<double>(60,60),
                point<double>(100,0),
                point<double>(100,25),
                point<double>(60,65)));
m_thelv1Path.push_back(walkPath<double>(
                point<double>(60,65),
                point<double>(100,25),
                point<double>(100,50),
                point<double>(60,70)));
m_thelv1Path.push_back(walkPath<double>(
                point<double>(60,70),
                point<double>(100,50),
                point<double>(100,75),
                point<double>(60,75)));
m_thelv1Path.push_back(walkPath<double>(
                point<double>(60,75),
                point<double>(100,75),
                point<double>(100,100),
                point<double>(60,80)));

m_thelv1Path.push_back(walkPath<double>(
                point<double>(60,80),
                point<double>(100,100),
                point<double>(75,100),
                point<double>(55,80)));
m_thelv1Path.push_back(walkPath<double>(
                point<double>(55,80),
                point<double>(75,100),
                point<double>(50,100),
                point<double>(50,80)));
m_thelv1Path.push_back(walkPath<double>(
                point<double>(50,80),
                point<double>(50,100),
                point<double>(25,100),
                point<double>(45,80)));
m_thelv1Path.push_back(walkPath<double>(
                point<double>(45,80),
                point<double>(25,100),
                point<double>(0,100),
                point<double>(40,80)));


m_thelv1Path.push_back(walkPath<double>(
                point<double>(40,80),
                point<double>(0,100),
                point<double>(0,75),
                point<double>(40,75)));
m_thelv1Path.push_back(walkPath<double>(
                point<double>(40,75),
                point<double>(0,75),
                point<double>(0,50),
                point<double>(40,70)));
m_thelv1Path.push_back(walkPath<double>(
                point<double>(40,70),
                point<double>(0,50),
                point<double>(0,25),
                point<double>(40,65)));
m_thelv1Path.push_back(walkPath<double>(
                point<double>(40,65),
                point<double>(0,25),
                point<double>(0,0),
                point<double>(40,60)));


// level 2

m_thelv2Path.push_back(walkPath<double>(
                point<double>(37.5,50),
                point<double>(0,50),
                point<double>(12.5,25),
                point<double>(40.625,43.75)));
m_thelv2Path.push_back(walkPath<double>(
                point<double>(40.625,43.75),
                point<double>(12.5,25),
                point<double>(25,0),
                point<double>(43.75,37.5)));
m_thelv2Path.push_back(walkPath<double>(
                point<double>(43.75,37.5),
                point<double>(25,0),
                point<double>(50,0),
                point<double>(50,37.5)));
m_thelv2Path.push_back(walkPath<double>(
                point<double>(50,37.5),
                point<double>(50,0),
                point<double>(75,0),
                point<double>(56.25,37.5)));


m_thelv2Path.push_back(walkPath<double>(
                point<double>(56.25,37.5),
                point<double>(75,0),
                point<double>(87.5,25),
                point<double>(59.375,43.75)));
m_thelv2Path.push_back(walkPath<double>(
                point<double>(59.375,43.75),
                point<double>(87.5,25),
                point<double>(100,50),
                point<double>(62.5,50)));
m_thelv2Path.push_back(walkPath<double>(
                point<double>(62.5,50),
                point<double>(100,50),
                point<double>(87.5,75),
                point<double>(59.375,56.25)));
m_thelv2Path.push_back(walkPath<double>(
                point<double>(59.375,56.25),
                point<double>(87.5,75),
                point<double>(75,100),
                point<double>(56.25,62.5)));
m_thelv2Path.push_back(walkPath<double>(
                point<double>(56.25,62.5),
                point<double>(75,100),
                point<double>(50,100),
                point<double>(50,62.5)));
m_thelv2Path.push_back(walkPath<double>(
                point<double>(50,62.5),
                point<double>(50,100),
                point<double>(25,100),
                point<double>(43.75,62.5)));

m_thelv2Path.push_back(walkPath<double>(
                point<double>(43.75,62.5),
                point<double>(25,100),
                point<double>(12.5,75),
                point<double>(40.625,56.25)));
m_thelv2Path.push_back(walkPath<double>(
                point<double>(40.625,56.25),
                point<double>(12.5,75),
                point<double>(0,50),
                point<double>(37.5,50)));


m_thelv3Path.push_back(walkPath<double>(
                point<double>(37.5,50),
                point<double>(0,50),
                point<double>(0,25),
                point<double>(37.5,43.75)));
m_thelv3Path.push_back(walkPath<double>(
                point<double>(37.5,43.75),
                point<double>(0,25),
                point<double>(12.5,12.5),
                point<double>(40.625,40.625)));
m_thelv3Path.push_back(walkPath<double>(
                point<double>(40.625,40.625),
                point<double>(12.5,12.5),
                point<double>(25.0,0),
                point<double>(43.75,37.5)));
m_thelv3Path.push_back(walkPath<double>(
                point<double>(43.75,37.5),
                point<double>(25.0,0),
                point<double>(50,0),
                point<double>(50,37.5)));
m_thelv3Path.push_back(walkPath<double>(
                point<double>(50,37.5),
                point<double>(50,0),
                point<double>(75,0),
                point<double>(56.25,37.5)));
m_thelv3Path.push_back(walkPath<double>(
                point<double>(56.25,37.5),
                point<double>(75,0),
                point<double>(87.5,12.5),
                point<double>(59.375,40.625)));
m_thelv3Path.push_back(walkPath<double>(
                point<double>(59.375,40.625),
                point<double>(87.5,12.5),
                point<double>(100,25),
                point<double>(62.5,43.75)));
m_thelv3Path.push_back(walkPath<double>(
                point<double>(62.5,43.75),
                point<double>(100,25),
                point<double>(100,50),
                point<double>(62.5,50)));



m_thelv3Path.push_back(walkPath<double>(
                point<double>(62.5,50),
                point<double>(100,50),
                point<double>(100,75),
                point<double>(62.5,56.25)));

m_thelv3Path.push_back(walkPath<double>(
                point<double>(62.5,56.25),
                point<double>(100,75),
                point<double>(87.5,87.5),
                point<double>(59.375,59.375)));

m_thelv3Path.push_back(walkPath<double>(
                point<double>(59.375,59.375),
                point<double>(87.5,87.5),
                point<double>(75,100),
                point<double>(56.25,62.5)));

m_thelv3Path.push_back(walkPath<double>(
                point<double>(56.25,62.5),
                point<double>(75,100),
                point<double>(50,100),
                point<double>(50,62.5)));


m_thelv3Path.push_back(walkPath<double>(
                point<double>(50,62.5),
                point<double>(50,100),
                point<double>(25,100),
                point<double>(43.75,62.5)));

m_thelv3Path.push_back(walkPath<double>(
                point<double>(43.75,62.5),
                point<double>(25,100),
                point<double>(12.5,87.5),
                point<double>(40.625,59.375)));

m_thelv3Path.push_back(walkPath<double>(
                point<double>(40.625,59.375),
                point<double>(12.5,87.5),
                point<double>(0,75),
                point<double>(37.5,56.25)));

m_thelv3Path.push_back(walkPath<double>(
                point<double>(37.5,56.25),
                point<double>(0,75),
                point<double>(0,50),
                point<double>(37.5,50)));
}

menuGame::menuGame(const menuGame& obj):
m_sdlSimpleLib(obj.m_sdlSimpleLib),
m_sdlObjTable(obj.m_sdlObjTable),
m_oldLvSelectValue(obj.m_oldLvSelectValue),
m_lvSelectValue(obj.m_lvSelectValue),
m_currentStage(obj.m_currentStage)
{}

menuGame::~menuGame()
{
    clean();
}

void menuGame::init()
{
    /*

enum MainMenuObj {BACKGROUND_IMG,LABEL_TEMPEST,LABEL_EXIT,LABEL_LV1,LABEL_LV2,LABEL_LV3,ANIMAL};

    */
    {
        std::shared_ptr<SDLObject> gameObj(std::make_shared<SDLObject>());
        gameObj->setSDLHandler(m_sdlSimpleLib);
        gameObj->loadParameter("./space.png");
        gameObj->setShownDimension(0,0,640,480);
        gameObj->setDrawPosition(0,0,640,480);
        m_sdlObjTable[BACKGROUND_IMG] = gameObj;
    }


    {
        std::shared_ptr<SDLObject> gameObj(std::make_shared<SDLObject>());
        gameObj->setSDLHandler(m_sdlSimpleLib);
        gameObj->loadParameter("Tempest",1);
        gameObj->setColor(COLORSET[YELLOW]);
        gameObj->setShownDimension(0,0,400,50);
        gameObj->setDrawPosition(120,60,400,50);
        m_sdlObjTable[LABEL_TEMPEST] = gameObj;
    }
    
    {
        std::shared_ptr<SDLObject> gameObj(std::make_shared<SDLObject>());
        gameObj->setSDLHandler(m_sdlSimpleLib);
        gameObj->loadParameter("Press ESC to exit",1);
        gameObj->setColor(COLORSET[ORANGE]);
        gameObj->setShownDimension(0,0,200,40);
        gameObj->setDrawPosition(20,10,200,40);
        m_sdlObjTable[LABEL_EXIT] = gameObj;
    }

    {
        std::shared_ptr<SDLObject> gameObj(std::make_shared<SDLObject>());
        gameObj->setSDLHandler(m_sdlSimpleLib);
        gameObj->loadParameter("Press BK Space to Menu",1);
        gameObj->setColor(COLORSET[ORANGE]);
        gameObj->setShownDimension(0,0,260,40);
        gameObj->setDrawPosition(20,10,260,40);
        m_sdlObjTable[BACK_TO_MAINMENU] = gameObj;
    }
    {
        std::shared_ptr<SDLObject> gameObj(std::make_shared<SDLObject>());
        gameObj->setSDLHandler(m_sdlSimpleLib);
        gameObj->loadParameter("Level 1",1);
        gameObj->setColor(COLORSET[DARK_GREEN]);
        gameObj->setShownDimension(0,0,200,40);
        gameObj->setDrawPosition(40,340,160,40);
        m_sdlObjTable[LABEL_LV1] = gameObj;
    }
    {
        std::shared_ptr<SDLObject> gameObj(std::make_shared<SDLObject>());
        gameObj->setSDLHandler(m_sdlSimpleLib);
        gameObj->loadParameter("Level 2",1);
        gameObj->setColor(COLORSET[DARK_GREEN]);
        gameObj->setShownDimension(0,0,200,40);
        gameObj->setDrawPosition(240,340,160,40);
        m_sdlObjTable[LABEL_LV2] = gameObj;   
    }
    {
        std::shared_ptr<SDLObject> gameObj(std::make_shared<SDLObject>());
        gameObj->setSDLHandler(m_sdlSimpleLib);
        gameObj->loadParameter("Level 3",1);
        gameObj->setColor(COLORSET[DARK_GREEN]);
        gameObj->setShownDimension(0,0,200,40);
        gameObj->setDrawPosition(440,340,160,40);
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
        {
            m_sdlObjTable[BACKGROUND_IMG]->render();
            m_sdlObjTable[BACK_TO_MAINMENU]->render();
            m_sdlSimpleLib->setRenderDrawColor(COLORSET[BLUE]);
            drawWalkPath(switchWalkPathByLv(m_currentStage),point<double>(100,50),4,true);
        }
        break;
    }
}

void menuGame::drawWalkPath(const std::vector<walkPath<double> >& obj,const point<double>& refPoint,const double &scaleVal, const bool isDrawnPlayer)
{
    for(int i = 0; i < obj.size(); i++)
    {
        // scale 1.0
        walkPath<double> aPieceofAPath;
        if (scaleVal != 1.0)
        {
            aPieceofAPath = (obj[i]*scaleVal).translate(refPoint);
        }
        else
        {
            aPieceofAPath = obj[i].translate(refPoint);
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
        if (it->first != BACK_TO_MAINMENU)
        it->second->render();
    }
        
    if (m_sdlSimpleLib)
    {        
        levelSelectionDisplay();
        // Select Level
        m_sdlObjTable[m_oldLvSelectValue]->setColor(COLORSET[DARK_GREEN]);
        m_sdlObjTable[m_lvSelectValue]->setColor(COLORSET[YELLOW]);
        m_sdlSimpleLib->setRenderDrawColor(COLORSET[YELLOW]);
        m_sdlSimpleLib->drawRectangle(20 + 200*(m_lvSelectValue - LABEL_LV1),150,190,190);
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
void menuGame::moveNextAreaOfPlayer(const std::vector<walkPath<double> >& obj)
{
    m_playerStartPoint++;
    if (m_playerStartPoint >= obj.size() )
    {
        m_playerStartPoint = 0;
    }
    else
    {
        // Do nothing
    }
}
void menuGame::moveBackAreaOfPlayer(const std::vector<walkPath<double> >& obj)
{
    m_playerStartPoint--;
    if (m_playerStartPoint < 0 )
    {
        m_playerStartPoint = obj.size() - 1;
    }
    else
    {
        // Do nothing
    }
}
/*
void menuGame::drawPlayerPosition(const std::vector<walkPath<double> >& obj,const point<double>& refPoint,const double& scale)
{
    walkPath<double> aPieceofAPath;
    if (scaleVal != 1.0)
    {
        aPieceofAPath = (obj[i]*scaleVal).translate(refPoint);
    }
    else
    {
        aPieceofAPath = obj[i].translate(refPoint);
    }
    m_sdlSimpleLib->drawLine(aPieceofAPath[LLEFT]);
    m_sdlSimpleLib->drawLine(aPieceofAPath[LEDGE]);
    m_sdlSimpleLib->drawLine(aPieceofAPath[LRIGHT]);

}
*/
void menuGame::levelSelectionDisplay()
{
    const int xStart = 40;
    const int yStart = 170;
    const int yStartLv1 = yStart + 25;
    setSelectedLvColorAndCondition(LABEL_LV1,COLORSET[BLUE],COLORSET[YELLOW]);
    m_sdlSimpleLib->drawRectangle(xStart,yStart,150,150);

    setSelectedLvColorAndCondition(LABEL_LV2,COLORSET[BLUE],COLORSET[YELLOW]);
    m_sdlSimpleLib->drawRectangle(240,yStart,150,150);

    setSelectedLvColorAndCondition(LABEL_LV3,COLORSET[BLUE],COLORSET[YELLOW]);
    m_sdlSimpleLib->drawRectangle(440,yStart,150,150);

    // Lv 1.
    setSelectedLvColorAndCondition(LABEL_LV1,COLORSET[RED],COLORSET[YELLOW]);
    drawWalkPath(m_thelv1Path,point<double>(xStart + 25,yStartLv1));
    // Lv 2.
    setSelectedLvColorAndCondition(LABEL_LV2,COLORSET[RED],COLORSET[YELLOW]);
    drawWalkPath(m_thelv2Path,point<double>(xStart + 225,yStartLv1));
    // Lv 3.
    setSelectedLvColorAndCondition(LABEL_LV3,COLORSET[RED],COLORSET[YELLOW]);
    drawWalkPath(m_thelv3Path,point<double>(xStart + 425,yStartLv1));



}

void menuGame::update()
{

    std::map<MainMenuObj,std::shared_ptr<SDLObject> >::iterator it;
    for(it = m_sdlObjTable.begin(); it != m_sdlObjTable.end(); it++) 
    {
        it->second->update();
    }
}

const std::vector<walkPath<double> >& menuGame::switchWalkPathByLv(const GameScene& val)
{
    switch(val)
    {
        case Level1:
            return m_thelv1Path;
        break;
        case Level2:
            return m_thelv2Path;
        break;
        case Level3:
            return m_thelv3Path;
        break;
        default:
        break;
    }
    return m_thelv1Path;
}
void menuGame::levelsKeyboardHandle(const unsigned char &val)
{

    switch(val)
    {
        case 8: // back space
            m_currentStage = MainMenu;
        break;
        case 79:  //right arrow
            moveNextAreaOfPlayer(switchWalkPathByLv(m_currentStage));
        break;
        case 80:  // left arrow
            moveBackAreaOfPlayer(switchWalkPathByLv(m_currentStage));
        break;
        default:
        break;
    }
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
                        m_playerStartPoint = 0;
                    break;
                    case LABEL_LV2:
                        m_currentStage = Level2;
                        m_playerStartPoint = 0;
                    break;
                    case LABEL_LV3:
                        m_currentStage = Level3;
                        m_playerStartPoint = 0;
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
        levelsKeyboardHandle(keyPress);
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
void menuGame::setRandValue(const int& val)
{
    randomVal = val;
    std::map<MainMenuObj,std::shared_ptr<SDLObject> >::iterator it;
    for(it = m_sdlObjTable.begin(); it != m_sdlObjTable.end(); it++) 
    {
        it->second->setRandValue(val);
    }
}