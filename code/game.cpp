
#include "game.h"
/*
	// createing an SDL texture
	SDL_Texture* m_pAnimalTexture; // the new sDL_Texture variable
	SDL_Rect m_sourceAnimalRectangle; // the first rectangle
	SDL_Rect m_destinationAnimalRectangle; // another rectangle
*/
game::game():
m_gameWindow(),
m_anAnimal(),
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
    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
         // if succeeded create our window
        m_pWindow = SDL_CreateWindow("Hello ",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,640,480,SDL_WINDOW_SHOWN);
        
        // if the window creation succeeded create our renderer
        if (m_pWindow != nullptr)
        {
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
        }
        else
        {
            return false; // sdl could not initialize
        }
        if (m_pRenderer != nullptr)
        {
        	SDL_Surface* pTempSurface = SDL_LoadBMP("./dragonSlayer.bmp");
        	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer,pTempSurface);
        	SDL_FreeSurface(pTempSurface);
         	// load the animal
        	pTempSurface = IMG_Load("./anAnimal1.png");
        	m_pAnimalTexture = SDL_CreateTextureFromSurface(m_pRenderer,pTempSurface);
        	SDL_FreeSurface(pTempSurface);



            // set to black // this function expects Red, Green, Blue and 
            // Alpha as color values
            SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
            // clear the window to black
            SDL_RenderClear(m_pRenderer);
            SDL_QueryTexture(m_pTexture, nullptr,nullptr, &m_sourceRectangle.w,&m_sourceRectangle.h);
            m_destinationRectangle.x = m_sourceRectangle.x = 0;
            m_destinationRectangle.y = m_sourceRectangle.y = 0;
            m_destinationRectangle.w = m_sourceRectangle.w;
            m_destinationRectangle.h = m_sourceRectangle.h;

            m_destinationAnimalRectangle.w = m_sourceAnimalRectangle.w = 128;
			m_destinationAnimalRectangle.h = m_sourceAnimalRectangle.h = 82;
			// move the animal next to the dragon slayer at the coordinate (128,0)
			m_destinationAnimalRectangle.x = m_sourceRectangle.w;

        }
        else
        {
        	return false;
        }
    }
    else
    {
        return false;  // sdl could not initialize
    }
    m_isRunning = true;
	return true;
}

void game::render()
{
	SDL_RenderClear(m_pRenderer);   // clear the renderer to the draw color

                SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                SDL_RenderClear(m_pRenderer);
    SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 255, SDL_ALPHA_OPAQUE);
                SDL_RenderDrawLine(m_pRenderer, 320, 200, 300, 240);
                SDL_RenderDrawLine(m_pRenderer, 300, 240, 340, 240);
                SDL_RenderDrawLine(m_pRenderer, 340, 240, 320, 200);

	// render a loaded texture
    SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
    if (m_animalFlipVal == 0)
    {
    	SDL_RenderCopyEx(m_pRenderer, m_pAnimalTexture, &m_sourceAnimalRectangle, &m_destinationAnimalRectangle,0,0,SDL_FLIP_NONE);
    }
    else 
    {
        SDL_RenderCopyEx(m_pRenderer, m_pAnimalTexture, &m_sourceAnimalRectangle, &m_destinationAnimalRectangle,0,0,SDL_FLIP_HORIZONTAL);
    } 



	SDL_RenderPresent(m_pRenderer); // draw to the screen
}
void game::update()
{
	int randXVal = randomFn(9000,-900)/100;
	if (randXVal > 0) // non SDL_FLIP
	{
		m_animalFlipVal = 0;
	}
	else
	{
		m_animalFlipVal = 1;
	}

	// move the coorinate to choose the next frame of an image 
	m_sourceAnimalRectangle.x = 128*int(((SDL_GetTicks()/100)%6));
	m_destinationAnimalRectangle.x = (m_destinationAnimalRectangle.x + randomFn(9,-9)*(SDL_GetTicks()%101/100) )%640;
	m_destinationAnimalRectangle.y = (m_destinationAnimalRectangle.y + randomFn(9,-9)*(SDL_GetTicks()%101/100) )%480;
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
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
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
