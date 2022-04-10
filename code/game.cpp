
#include "game.h"
/*
	// createing an SDL texture
	SDL_Texture* m_pAnimalTexture; // the new sDL_Texture variable
	SDL_Rect m_sourceAnimalRectangle; // the first rectangle
	SDL_Rect m_destinationAnimalRectangle; // another rectangle
*/
game::game():
m_gameWindow(),
m_anAnimal("./anAnimal1.png"),
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
	m_anAnimal.setRenderer(m_gameWindow.getRenderer());
	m_anAnimal.init();
	m_anAnimal.setSourceRect(0,0,128,82);
	m_anAnimal.setDestinationRect(0,0,128,82);

	std::shared_ptr<gameObject> aCastTypeRef(dynamic_cast<gameObject*>(&m_anAnimal));
	m_gameWindow.setTheActivist(aCastTypeRef);
	m_isRunning = m_gameWindow.isInitiated();
	return m_isRunning;
}

void game::render()
{
	m_gameWindow.render();
}
void game::update()
{
	int randXVal = randomFn(9000,-900)/100;
	m_anAnimal.setRandomVal(randXVal);
	m_gameWindow.update();

}

void game::handleEvents()
{
    SDL_Event event;
    if (SDL_PollEvent(&event))
    {
    	switch (event.type)
    	{
    		case SDL_QUIT:
    		    m_isRunning = false;
    		break;
    		case SDL_KEYDOWN:
    		    m_isRunning = false;
    		break;
    		default:
    		break;
    	}
    }
    else
    {
    	// Do nothing
    }
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
