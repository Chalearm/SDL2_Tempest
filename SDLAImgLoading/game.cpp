#include "game.h"

game::game():
m_pWindow(nullptr),
m_pRenderer(nullptr),
m_isRunning(false),
m_pTexture(nullptr),
m_sourceRectangle(),
m_destinationRectangle()
{

}

game::~game()
{

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
	// render a loaded texture
    SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
	SDL_RenderPresent(m_pRenderer); // draw to the screen
}
void game::update()
{

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
