
#include "game.h"
/*
	// createing an SDL texture
	SDL_Texture* m_pAnimalTexture; // the new sDL_Texture variable
	SDL_Rect m_sourceAnimalRectangle; // the first rectangle
	SDL_Rect m_destinationAnimalRectangle; // another rectangle
*/
game::game():
theSdlHandler(SDLHandler::GetInstance("Tempest!!!")),
m_pAnimal(std::make_shared<gameState>()),
rd(),
gen(rd()),
m_animalFlipVal(0)
{

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
	std::shared_ptr<SDLObject> gameObj = std::make_shared<SDLObject>("./anAnimal1.png");
	gameObj->setSDLHandler(theSdlHandler);
	gameObj->loadParameter("./anAnimal1.png");
    gameObj->setShownDimension(0,0,128,82);
    gameObj->setDrawPosition(0,0,128,82);
	gameObj->init();
	m_pAnimal = gameObj;
	theSdlHandler->setTheActivist(m_pAnimal);
	m_isRunning = theSdlHandler->isAbleToRun();
	return m_isRunning;
}

void game::render()
{
	theSdlHandler->render();
}
void game::update()
{
	int randXVal = randomFn(900,-900)/100;
    std::shared_ptr<SDLObject> gameObj(dynamic_pointer_cast<SDLObject>(m_pAnimal));
    gameObj->setRandValue(randXVal);
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
