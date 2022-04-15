#include "menuGame.h"

menuGame::menuGame():
m_sdlSimpleLib(),
m_sdlObjList(),
m_lvSelectValue(0)
{

}

menuGame::menuGame(const menuGame& obj):
m_sdlSimpleLib(obj.m_sdlSimpleLib),
m_sdlObjList(obj.m_sdlObjList)
{

}

menuGame::~menuGame()
{
    clean();
}

void menuGame::init()
{
    {
        std::shared_ptr<SDLObject> gameObj(std::make_shared<SDLObject>());
        gameObj->setSDLHandler(m_sdlSimpleLib);
        gameObj->loadParameter("./space.png");
        gameObj->setShownDimension(0,0,640,480);
        gameObj->setDrawPosition(0,0,640,480);
        m_sdlObjList.push_back(gameObj); 
    }

    {
        std::shared_ptr<SDLObject> gameObj(std::make_shared<SDLObject>());
        gameObj->setSDLHandler(m_sdlSimpleLib);
        gameObj->loadParameter("./anAnimal1.png");
        gameObj->setShownDimension(0,0,128,82);
        gameObj->setDrawPosition(0,0,128,82);
        m_sdlObjList.push_back(gameObj); 
    }

    {
        std::shared_ptr<SDLObject> gameObj(std::make_shared<SDLObject>());
        gameObj->setSDLHandler(m_sdlSimpleLib);
        gameObj->setColor(255,255,0);
        gameObj->loadParameter("Tempest",1);
        gameObj->setShownDimension(0,0,400,50);
        gameObj->setDrawPosition(120,60,400,50);
        m_sdlObjList.push_back(gameObj);   
    }
    
    {
        std::shared_ptr<SDLObject> gameObj(std::make_shared<SDLObject>());
        gameObj->setSDLHandler(m_sdlSimpleLib);
        gameObj->setColor(255,100,0);
        gameObj->loadParameter("Press ESC to exit",1);
        gameObj->setShownDimension(0,0,200,40);
        gameObj->setDrawPosition(20,10,200,40);
        m_sdlObjList.push_back(gameObj);   
    }
    {
        std::shared_ptr<SDLObject> gameObj(std::make_shared<SDLObject>());
        gameObj->setSDLHandler(m_sdlSimpleLib);
        gameObj->setColor(0,120,0);
        gameObj->loadParameter("Level 1",1);
        gameObj->setShownDimension(0,0,200,40);
        gameObj->setDrawPosition(40,340,160,40);
        m_sdlObjList.push_back(gameObj);
    }
    {
        std::shared_ptr<SDLObject> gameObj(std::make_shared<SDLObject>());
        gameObj->setSDLHandler(m_sdlSimpleLib);
        gameObj->setColor(0,120,0);
        gameObj->loadParameter("Level 2",1);
        gameObj->setShownDimension(0,0,200,40);
        gameObj->setDrawPosition(240,340,160,40);
        m_sdlObjList.push_back(gameObj);      
    }
    {
        std::shared_ptr<SDLObject> gameObj(std::make_shared<SDLObject>());
        gameObj->setSDLHandler(m_sdlSimpleLib);
        gameObj->setColor(0,120,0);
        gameObj->loadParameter("Level 3",1);
        gameObj->setShownDimension(0,0,200,40);
        gameObj->setDrawPosition(440,340,160,40);
        m_sdlObjList.push_back(gameObj);      
    }

}

void menuGame::render()
{
    if (m_sdlSimpleLib)
    {        
        m_sdlSimpleLib->setRenderDrawColor(0,0,255,255);
        m_sdlSimpleLib->renderClear();
    }
    for(int i = 0; i < m_sdlObjList.size(); i++) 
    {
        m_sdlObjList[i]->render();
    }
        
    if (m_sdlSimpleLib)
    {        
        levelSelectionDisplay();
        // Select Level
        m_sdlSimpleLib->setRenderDrawColor(255,255,0,255);
        m_sdlSimpleLib->drawRectangle(20 + 200*m_lvSelectValue,150,190,190);
    }
}

void menuGame::levelSelectionDisplay()
{
    const int yStart = 170;
    const int yStartLv1 = yStart + 25;
    m_sdlSimpleLib->setRenderDrawColor(0,0,255,255);
    m_sdlSimpleLib->drawRectangle(40,yStart,150,150);
    m_sdlSimpleLib->drawRectangle(240,yStart,150,150);
    m_sdlSimpleLib->drawRectangle(440,yStart,150,150);

    // Lv 1.
    m_sdlSimpleLib->setRenderDrawColor(30,200,30,255);
    // rectangle outside
    m_sdlSimpleLib->drawRectangle(65, yStartLv1,100,100);
    // rectangle inside
    m_sdlSimpleLib->drawRectangle(105,yStartLv1 + 50,20,20);
    m_sdlSimpleLib->drawLine(65, yStartLv1, 105, yStartLv1 + 50);
    m_sdlSimpleLib->drawLine(65, yStartLv1+ 100, 105, yStartLv1 + 70);
    m_sdlSimpleLib->drawLine(165, yStartLv1+ 100, 125, yStartLv1 + 70);
    m_sdlSimpleLib->drawLine(165, yStartLv1, 125, yStartLv1 + 50);

    m_sdlSimpleLib->drawLine(111, yStartLv1 + 50, 95, yStartLv1);
    m_sdlSimpleLib->drawLine(118, yStartLv1 + 50, 125, yStartLv1);

    m_sdlSimpleLib->drawLine(111, yStartLv1 + 70, 95, yStartLv1 + 100);
    m_sdlSimpleLib->drawLine(118, yStartLv1 + 70, 125, yStartLv1 + 100);

    m_sdlSimpleLib->drawLine(65, yStartLv1 + 35, 105, yStartLv1 + 56);
    m_sdlSimpleLib->drawLine(65, yStartLv1 + 70, 105, yStartLv1 + 63);



    m_sdlSimpleLib->drawLine(165, yStartLv1 + 35, 125, yStartLv1 + 56);
    m_sdlSimpleLib->drawLine(165, yStartLv1 + 70, 125, yStartLv1 + 63);
    // Lv 2.

    // Lv 3.

}

void menuGame::update()
{
    for(int i = 0; i < m_sdlObjList.size(); i++) 
    {
        if (i == 1)
        {

            std::shared_ptr<gameObj> aGameObj = m_sdlObjList[i];
            int newXval = 128*int(((clock()/100)%6));
            int newXVal2 = (randomVal*(clock()%101/100) )%640;
            int newYVal2 = (randomVal*(clock()%101/100) )%640;

            aGameObj->moveFromCurrentPos(newXVal2,newYVal2);
            aGameObj->setShownDimension(newXval, 0, 128, 72);
        }
        m_sdlObjList[i]->update();
    }
}
void menuGame::handleEvents(const unsigned char& keyPress)
{
   // std::cout<<((int)keyPress)<<" \n";
    switch(keyPress)
    {
        case 79:  //right arrow
            m_lvSelectValue = (++m_lvSelectValue);
        break;
        case 80:  // left arrow  
           m_lvSelectValue = (--m_lvSelectValue);
        break;
        case 13:  // enter
        break;
    }
    if (m_lvSelectValue > 2) m_lvSelectValue = 0;
    else if (m_lvSelectValue < 0) m_lvSelectValue = 2;


    for(int i = 0; i < m_sdlObjList.size(); i++) 
    {
        m_sdlObjList[i]->handleEvents(keyPress);
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
    for(int i = 0; i < m_sdlObjList.size(); i++) 
    {
        m_sdlObjList[i]->setRandValue(val);
    }
}