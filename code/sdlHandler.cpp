#include "sdlHandler.h"


SDLHandler::SDLHandler(const std::string &windowTitle,const int &windowWidth, const int &windowHeight):
m_pWindow(),
m_sdlDrawnObjList(),
m_titleMessage(windowTitle),
m_windowWidth(windowWidth),
m_windowheight(windowHeight),
m_isAbleToRun(false),
m_gameActivist(std::make_shared<gameObject>())
{}

SDLHandler::~SDLHandler()
{
	clean();
}

void SDLHandler::setNewWindowTitle(const std::string &windowTitle)
{
	if (m_isAbleToRun)
	{
		m_titleMessage = windowTitle;
		SDL_SetWindowTitle(m_pWindow.get(),windowTitle.c_str());
	}
	else
	{
		// Do nothing
	}
}
void SDLHandler::init()
{
	m_isAbleToRun = false;  // sdl could not initialize
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
    		// Do nothing
    }
    else if (SDLDrawnObj::initImgAndTff() >= 0)
    {

         // if succeeded create our window
        m_pWindow.reset(SDL_CreateWindow(m_titleMessage.c_str(),SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,m_windowWidth,m_windowheight,SDL_WINDOW_SHOWN),SDLDestroyer());
		SDLDrawnObj::loadFont("./Hersheys.ttf",24);
/*
		if ((m_gameActivist) && (m_isAbleToRun))
		{
			m_gameActivist->init();
		}
		*/
    }
    else
    {
    		// Do nothing
    }
    if (m_pWindow)
    {
        // if the window creation succeeded create our renderer
        SDLDrawnObj::createRenderer(m_pWindow);
        m_isAbleToRun = SDLDrawnObj::isAbleToRender();
    }
    else
    {
    	 // Do nothing
    }
}
void SDLHandler::clean()
{
	SDLDrawnObj::SDLImgAndTffQuit();
	SDL_Quit();
}

void SDLHandler::render()
{
	if (m_isAbleToRun)
	{    
		SDLDrawnObj::renderClear();		
		if (m_gameActivist)
		{
			m_gameActivist->render();
		}
		else
		{
			// Do nothing
		}
        SDLDrawnObj::renderPresent();

	}
	else
	{
		// Do nothing
	}
}
void SDLHandler::update()
{
	if ((m_gameActivist) && (m_isAbleToRun))
	{
		m_gameActivist->update();
	}
	else
	{
		// Do nothing
	}
}
void SDLHandler::handleEvents()
{
	if (m_isAbleToRun)
	{
	    SDL_Event event;
	    if (SDL_PollEvent(&event))
	    {
	    	switch (event.type)
	    	{
	    		case SDL_QUIT:
	    		    m_isAbleToRun = false;
	    		break;
	    		case SDL_KEYDOWN:
	    		    m_isAbleToRun = false;
	    		break;
	    		default:
	    		break;
	    	}
	    }
	    else
	    {
	    	// Do nothing
	    }

		if (m_gameActivist)
		{
			m_gameActivist->handleEvents();
		}
		else
		{
			// Do nothing
		}
	}
	else
	{
		// Do nothing
	}
}
 
bool SDLHandler::isAbleToRun()
{
	return m_isAbleToRun;
}

void SDLHandler::setTheActivist(std::shared_ptr<gameObject> anObj)
{
	m_gameActivist = anObj;
}

int SDLHandler::loadImage(const std::string &path)
{
	if (path != "")
	{
		m_sdlDrawnObjList.push_back(SDLDrawnObj());
		m_sdlDrawnObjList[m_sdlDrawnObjList.size() - 1].loadImage(path);
			
	}
	else
	{
		// Do nothing
	}
	return (m_sdlDrawnObjList.size() - 1);
}

/*

void SDLHandler::drawImg(const int &imgId, const int &x, const int &y, const int& w, const int& h)
{
	
	if ((imgId < m_textureList.size()) && (imgId > -1)) 
	{
		std::shared_ptr<SDL_Texture> aTexture = m_textureList[imgId];
		SDL_Rect destRect = {x,y,w,h};
        SDL_RenderCopy(m_pRenderer.get(), aTexture.get(), nullptr, &destRect);
	}
	else
	{
		// Do nothing
	}
	
}
    int addText(const std::string &text,const unsigned char &r,const unsigned char &g, const unsigned char &b);

    void drawText(const int &textId, const int &x, const int &y, const int& w, const int& h);
    */
