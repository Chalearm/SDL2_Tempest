
#include "game.h"
/*
	// createing an SDL texture
	SDL_Texture* m_pAnimalTexture; // the new sDL_Texture variable
	SDL_Rect m_sourceAnimalRectangle; // the first rectangle
	SDL_Rect m_destinationAnimalRectangle; // another rectangle
*/
game::game():
m_gameWindow("Tempest !!!"),
m_pAnimal(std::make_shared<gameObject>()),
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
	m_gameWindow.init();
/*
	{
		std::shared_ptr<SDLObject> gameObj = std::make_shared<SDLObject>("./anAnimal1.png");
		//gameObj->setRenderer(m_gameWindow.getRenderer());
		gameObj->init();
		gameObj->setSourceRect(0,0,128,82);
		gameObj->setDestinationRect(0,0,128,82);
		m_pAnimal = gameObj;
    }
	m_gameWindow.setTheActivist(m_pAnimal);
	*/
	m_isRunning = m_gameWindow.isAbleToRun();
	return m_isRunning;
}

void game::render()
{
	m_gameWindow.render();
}
void game::update()
{
	int randXVal = randomFn(9000,-900)/100;
//	std::shared_ptr<SDLObject> gameObj(dynamic_pointer_cast<SDLObject>(m_pAnimal));
//	gameObj->setRandomVal(randXVal);
	m_gameWindow.update();

}

void game::handleEvents()
{
	m_gameWindow.handleEvents();
	m_isRunning = m_gameWindow.isAbleToRun();
	
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
