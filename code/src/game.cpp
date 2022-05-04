
#include "game.h"
#include "menuGame.h"
#include "level1.h"

game::game():
theSdlHandler(SDLHandler::GetInstance("Tempest!!!")),
m_currentGameState(),
m_oldGameState(),
m_gameScene(),
rd(),
gen(rd())
{
	// create main menu
	{
		std::shared_ptr<menuGame> gameObj = std::make_shared<menuGame>();
		gameObj->setSDLHandler(theSdlHandler);	
		m_gameScene[MainMenu] = gameObj;
		m_currentGameState = gameObj;
	}
	// create level 1
	{
		std::shared_ptr<level1> gameObj = std::make_shared<level1>();
		m_gameScene[Level1] = gameObj;
		gameObj->setSDLHandler(theSdlHandler);
	}
	theSdlHandler->setTheActivist(m_gameScene[MainMenu]);
}

game::~game()
{

}
int game::randomFn(int max,int min)
{
	std::uniform_int_distribution<> distrib(min,max);
	return distrib(gen);
}

bool game::init()
{
	theSdlHandler->init();		
    m_gameScene[Level1]->init();
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
