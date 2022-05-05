
#include "game.h"
#include "menuGame.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"

game::game():
theSdlHandler(SDLHandler::GetInstance("Tempest!!!")),
m_currentGameState(),
m_oldGameState(),
m_gameScene()
{
	
	std::shared_ptr<level1> lv1Obj = std::make_shared<level1>();  // create level 1
	std::shared_ptr<level2> lv2Obj = std::make_shared<level2>();  // create level 2
	std::shared_ptr<level3> lv3Obj = std::make_shared<level3>();  // create level 3
	std::shared_ptr<menuGame> gameObj = std::make_shared<menuGame>(); // create main menu
	m_gameScene[Level1] = lv1Obj;
	m_gameScene[Level2] = lv2Obj;
	m_gameScene[Level3] = lv3Obj;
	lv1Obj->setSDLHandler(theSdlHandler);
	lv2Obj->setSDLHandler(theSdlHandler);
	lv3Obj->setSDLHandler(theSdlHandler);
	gameObj->setWalkPath(Level1,lv1Obj->getWalkPaht());
	gameObj->setWalkPath(Level2,lv2Obj->getWalkPaht());
	gameObj->setWalkPath(Level3,lv3Obj->getWalkPaht());
	gameObj->setSDLHandler(theSdlHandler);	
	m_gameScene[MainMenu] = gameObj;
	m_currentGameState = gameObj;

	theSdlHandler->setTheActivist(m_gameScene[MainMenu]);
}

game::~game()
{

}

bool game::init()
{
	theSdlHandler->init();		
    m_gameScene[Level1]->init();
    m_gameScene[Level2]->init();
    m_gameScene[Level3]->init();
	m_isRunning = theSdlHandler->isAbleToRun();
	return m_isRunning;
}

void game::render()
{
	theSdlHandler->render();
}
void game::update()
{

	m_currentGameState = m_gameScene[m_currentGameState->getGameState()];

	if (m_currentGameState != m_oldGameState)
	{
	    theSdlHandler->setTheActivist(m_currentGameState);
		m_currentGameState->init();
		m_oldGameState = m_currentGameState;
	}
	else
	{
		// Do nothing
	}
	
	theSdlHandler->update();
}

void game::handleEvents()
{
	theSdlHandler->handleEvents();
	m_isRunning = theSdlHandler->isAbleToRun();

}

void game::clean()
{
}

bool game::isRunning() const
{
	return m_isRunning;
}

void game::runGame()
{
	bool isAbleToInit = init();
	bool isAbleToRun = (isRunning() && isAbleToInit);
	while (isRunning())
    {
        handleEvents();
        update();
        render();

	}
	// clear
	if (isAbleToRun)
	{
        clean();
	}
	else
	{
		// Do nothing
	}
}
