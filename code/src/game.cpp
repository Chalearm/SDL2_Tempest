
#include "game.h"
#include "menuGame.h"
#include "level1.h"

game::game():
theSdlHandler(SDLHandler::GetInstance("Tempest!!!")),
m_menuGame(),
rd(),
gen(rd())
{
    std::shared_ptr<menuGame> gameObj = std::make_shared<menuGame>();
	gameObj->setSDLHandler(theSdlHandler);
	m_menuGame = gameObj;
	theSdlHandler->setTheActivist(m_menuGame);
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

	m_isRunning = theSdlHandler->isAbleToRun();
	return m_isRunning;
}

void game::render()
{
	theSdlHandler->render();
}
void game::update()
{
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
