
#include "game.h"

game::game():
m_pWindow(nullptr),
m_pRenderer(nullptr),
m_isRunning(false),
m_pTexture(nullptr),
m_sourceRectangle(),
m_destinationRectangle(),
m_pAnimalTexture(nullptr),
m_sourceAnimalRectangle(),
m_destinationAnimalRectangle(),
m_pTxtMsgTexture(nullptr),
rd(),
gen(rd()),
m_font(nullptr)
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
    bool ret = false;
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        // Do nothing
    }
    else if (IMG_Init(IMG_INIT_PNG) < 0)
    {
        // Do nothing
    }
    else if (TTF_Init() >= 0)
    {
        m_pWindow = SDL_CreateWindow("Hello ",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,640,480,SDL_WINDOW_SHOWN);
        m_font = TTF_OpenFont("Hersheys.ttf", 24);
        // if the window creation succeeded create our renderer
        if (m_pWindow != nullptr)
        {
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
        }
        else
        {
            // sdl could not initialize
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


           SDL_Color foreground = { 255, 255, 0 };
           SDL_Surface* text_surf = TTF_RenderText_Solid(m_font,"I ThInk I Jui AAA NN aaa bcdefg", foreground);
           m_pTxtMsgTexture = SDL_CreateTextureFromSurface(m_pRenderer, text_surf);
           SDL_FreeSurface(text_surf);


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
            ret = true;
            m_isRunning = true;
        }
        else
        {
        	// Do nothing
        }
    }
    else
    {
        // sdl could not initialize
    }
	return ret;
}

void game::render()
{
	SDL_RenderClear(m_pRenderer);   // clear the renderer to the draw color
	// render a loaded texture
    SDL_Rect rectText = {100,100,250,30};
    SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
    SDL_RenderCopy(m_pRenderer, m_pTxtMsgTexture, 0, &rectText);
    SDL_RenderCopy(m_pRenderer, m_pAnimalTexture, &m_sourceAnimalRectangle, &m_destinationAnimalRectangle);
	SDL_RenderPresent(m_pRenderer); // draw to the screen
}
void game::update()
{
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
    TTF_CloseFont(m_font);
    SDL_DestroyTexture(m_pTexture);
    SDL_DestroyTexture(m_pTxtMsgTexture);
    SDL_DestroyTexture(m_pTxtMsgTexture);
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
    TTF_Quit();
    IMG_Quit();
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
        update();
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
