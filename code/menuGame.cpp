#include <vector>
#include "menuGame.h"

menuGame::menuGame():
m_sdlSimpleLib(),
m_sdlObjTable(),
m_oldLvSelectValue(LABEL_LV1),
m_lvSelectValue(LABEL_LV1),
m_currentStage(MainMenu)
{

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
        gameObj->loadParameter("./anAnimal1.png");
        gameObj->setShownDimension(0,0,128,82);
        gameObj->setDrawPosition(0,0,128,82);
        m_sdlObjTable[ANIMAL] = gameObj;
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
        break;
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
        m_sdlSimpleLib->drawRectangle(20 + 200*(m_lvSelectValue - LABEL_LV1),150,190,190);
    }
}

void menuGame::levelSelectionDisplay()
{
    const int xStart = 40;
    const int yStart = 170;
    const int yStartLv1 = yStart + 25;
    if (m_lvSelectValue == LABEL_LV1)
    m_sdlSimpleLib->setRenderDrawColor(COLORSET[YELLOW]);
    else
    m_sdlSimpleLib->setRenderDrawColor(COLORSET[BLUE]);
    m_sdlSimpleLib->drawRectangle(xStart,yStart,150,150);

    if (m_lvSelectValue == LABEL_LV2)
    m_sdlSimpleLib->setRenderDrawColor(COLORSET[YELLOW]);
    else
    m_sdlSimpleLib->setRenderDrawColor(COLORSET[BLUE]);
    m_sdlSimpleLib->drawRectangle(240,yStart,150,150);

    if (m_lvSelectValue == LABEL_LV3)
    m_sdlSimpleLib->setRenderDrawColor(COLORSET[YELLOW]);
    else
    m_sdlSimpleLib->setRenderDrawColor(COLORSET[BLUE]);
    m_sdlSimpleLib->drawRectangle(440,yStart,150,150);

    // Lv 1.
std::vector<walkPath<double> > thelv1Path;
thelv1Path.push_back(walkPath<double>(
                point<double>(40,60),
                point<double>(0,0),
                point<double>(25,0),
                point<double>(45,60)));
thelv1Path.push_back(walkPath<double>(
                point<double>(45,60),
                point<double>(25,0),
                point<double>(50,0),
                point<double>(50,60)));
thelv1Path.push_back(walkPath<double>(
                point<double>(50,60),
                point<double>(50,0),
                point<double>(75,0),
                point<double>(55,60)));
thelv1Path.push_back(walkPath<double>(
                point<double>(55,60),
                point<double>(75,0),
                point<double>(100,0),
                point<double>(60,60)));

thelv1Path.push_back(walkPath<double>(
                point<double>(60,60),
                point<double>(100,0),
                point<double>(100,25),
                point<double>(60,65)));
thelv1Path.push_back(walkPath<double>(
                point<double>(60,65),
                point<double>(100,25),
                point<double>(100,50),
                point<double>(60,70)));
thelv1Path.push_back(walkPath<double>(
                point<double>(60,70),
                point<double>(100,50),
                point<double>(100,75),
                point<double>(60,75)));
thelv1Path.push_back(walkPath<double>(
                point<double>(60,75),
                point<double>(100,75),
                point<double>(100,100),
                point<double>(60,80)));

thelv1Path.push_back(walkPath<double>(
                point<double>(60,80),
                point<double>(100,100),
                point<double>(75,100),
                point<double>(55,80)));
thelv1Path.push_back(walkPath<double>(
                point<double>(55,80),
                point<double>(75,100),
                point<double>(50,100),
                point<double>(50,80)));
thelv1Path.push_back(walkPath<double>(
                point<double>(50,80),
                point<double>(50,100),
                point<double>(25,100),
                point<double>(45,80)));
thelv1Path.push_back(walkPath<double>(
                point<double>(45,80),
                point<double>(25,100),
                point<double>(0,100),
                point<double>(40,80)));


thelv1Path.push_back(walkPath<double>(
                point<double>(40,80),
                point<double>(0,100),
                point<double>(0,75),
                point<double>(40,75)));
thelv1Path.push_back(walkPath<double>(
                point<double>(40,75),
                point<double>(0,75),
                point<double>(0,50),
                point<double>(40,70)));
thelv1Path.push_back(walkPath<double>(
                point<double>(40,70),
                point<double>(0,50),
                point<double>(0,25),
                point<double>(40,65)));
thelv1Path.push_back(walkPath<double>(
                point<double>(40,65),
                point<double>(0,25),
                point<double>(0,0),
                point<double>(40,60)));
    if (m_lvSelectValue == LABEL_LV1)
    m_sdlSimpleLib->setRenderDrawColor(COLORSET[YELLOW]);
    else
    m_sdlSimpleLib->setRenderDrawColor(COLORSET[RED]);

for(int i=0; i < thelv1Path.size(); i++)
{
    // scale 1.0
    walkPath<double> aPieceofAPath = (thelv1Path[i]*1.0).translate(point<double>(xStart + 25,yStartLv1));

    m_sdlSimpleLib->drawLine(aPieceofAPath[LLEFT]);
    m_sdlSimpleLib->drawLine(aPieceofAPath[LEDGE]);


    m_sdlSimpleLib->drawLine(static_cast<int>(aPieceofAPath[LLEFT][P1][X]),
                             static_cast<int>(aPieceofAPath[LLEFT][P1][Y]), 
                             static_cast<int>(aPieceofAPath[LRIGHT][P2][X]),
                             static_cast<int>(aPieceofAPath[LRIGHT][P2][Y]));
}
    // Lv 2.

std::vector<walkPath<double> > thelv2Path;
thelv2Path.push_back(walkPath<double>(
                point<double>(37.5,50),
                point<double>(0,50),
                point<double>(12.5,25),
                point<double>(40.625,43.75)));
thelv2Path.push_back(walkPath<double>(
                point<double>(40.625,43.75),
                point<double>(12.5,25),
                point<double>(25,0),
                point<double>(43.75,37.5)));
thelv2Path.push_back(walkPath<double>(
                point<double>(43.75,37.5),
                point<double>(25,0),
                point<double>(50,0),
                point<double>(50,37.5)));
thelv2Path.push_back(walkPath<double>(
                point<double>(50,37.5),
                point<double>(50,0),
                point<double>(75,0),
                point<double>(56.25,37.5)));


thelv2Path.push_back(walkPath<double>(
                point<double>(56.25,37.5),
                point<double>(75,0),
                point<double>(87.5,25),
                point<double>(59.375,43.75)));
thelv2Path.push_back(walkPath<double>(
                point<double>(59.375,43.75),
                point<double>(87.5,25),
                point<double>(100,50),
                point<double>(62.5,50)));
thelv2Path.push_back(walkPath<double>(
                point<double>(62.5,50),
                point<double>(100,50),
                point<double>(87.5,75),
                point<double>(59.375,56.25)));
thelv2Path.push_back(walkPath<double>(
                point<double>(59.375,56.25),
                point<double>(87.5,75),
                point<double>(75,100),
                point<double>(56.25,62.5)));
thelv2Path.push_back(walkPath<double>(
                point<double>(56.25,62.5),
                point<double>(75,100),
                point<double>(50,100),
                point<double>(50,62.5)));
thelv2Path.push_back(walkPath<double>(
                point<double>(50,62.5),
                point<double>(50,100),
                point<double>(25,100),
                point<double>(43.75,62.5)));

thelv2Path.push_back(walkPath<double>(
                point<double>(43.75,62.5),
                point<double>(25,100),
                point<double>(12.5,75),
                point<double>(40.625,56.25)));
thelv2Path.push_back(walkPath<double>(
                point<double>(40.625,56.25),
                point<double>(12.5,75),
                point<double>(0,50),
                point<double>(37.5,50)));

    if (m_lvSelectValue == LABEL_LV2)
    m_sdlSimpleLib->setRenderDrawColor(COLORSET[YELLOW]);
    else
    m_sdlSimpleLib->setRenderDrawColor(COLORSET[RED]);

for(int i=0; i < thelv2Path.size(); i++)
{
    // scale 1.0
    walkPath<double> aPieceofAPath = (thelv2Path[i]*1.0).translate(point<double>(xStart + 225,yStartLv1));

    m_sdlSimpleLib->drawLine(aPieceofAPath[LLEFT]);
    m_sdlSimpleLib->drawLine(aPieceofAPath[LEDGE]);


    m_sdlSimpleLib->drawLine(static_cast<int>(aPieceofAPath[LLEFT][P1][X]),
                             static_cast<int>(aPieceofAPath[LLEFT][P1][Y]), 
                             static_cast<int>(aPieceofAPath[LRIGHT][P2][X]),
                             static_cast<int>(aPieceofAPath[LRIGHT][P2][Y]));
}

    // Lv 3.

}

void menuGame::update()
{

    std::map<MainMenuObj,std::shared_ptr<SDLObject> >::iterator it;
    for(it = m_sdlObjTable.begin(); it != m_sdlObjTable.end(); it++) 
    {
        if (it->first == ANIMAL)
        {

            std::shared_ptr<gameObj> aGameObj = m_sdlObjTable[ANIMAL];
            int newXval = 128*int(((clock()/100)%6));
            int newXVal2 = (randomVal*(clock()%101/100) )%640;
            int newYVal2 = (randomVal*(clock()%101/100) )%640;

            aGameObj->moveFromCurrentPos(newXVal2,newYVal2);
            aGameObj->setShownDimension(newXval, 0, 128, 72);
        }
        it->second->update();
    }
}
void menuGame::handleEvents(const unsigned char& keyPress)
{
   // std::cout<<((int)keyPress)<<" \n";
    switch(keyPress)
    {
        case 79:  //right arrow
            goNextLv();
        break;
        case 80:  // left arrow  
            goBackLv();
        break;
        case 13:  // enter
        break;
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