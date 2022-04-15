#include "menuGame.h"

menuGame::menuGame():
m_sdlSimpleLib(),
m_sdlObjList()
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