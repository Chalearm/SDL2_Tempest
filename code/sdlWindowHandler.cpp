#include "sdlWindowHandler.h"


SDLWindowHandler::SDLWindowHandler(const std::string &windowTitle,const int &windowWidth, const int &windowHeight):
m_pWindow(nullptr),
m_pRenderer(new SDLRenderer()),
m_titleMessage(windowTitle),
m_windowWidth(windowWidth),
m_windowheight(windowHeight),
m_isAbleToRun(false),
m_gameActivist(nullptr)
{}

SDLWindowHandler::~SDLWindowHandler()
{
	clean();
}

void SDLWindowHandler::setNewWindowTitle(const std::string &windowTitle)
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
void SDLWindowHandler::init()
{
	m_isAbleToRun = false;  // sdl could not initialize
    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
         // if succeeded create our window
        m_pWindow.reset(SDL_CreateWindow(m_titleMessage.c_str(),SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,m_windowWidth,m_windowheight,SDL_WINDOW_SHOWN));
        // if the window creation succeeded create our renderer
        m_isAbleToRun = m_pRenderer->createRenderer(m_pWindow.get());
/*
		if ((m_gameActivist) && (m_isAbleToRun))
		{
			m_gameActivist->init();
		}
		else
		{
			// Do nothing
		}
		*/
    }
    else
    {
    	// Do nothing
    }
}
void SDLWindowHandler::clean()
{
	SDL_Quit();
}

void SDLWindowHandler::render()
{
	if (m_isAbleToRun)
	{
	    m_pRenderer->renderClear();
		if (m_gameActivist)
		{
			m_gameActivist->render();
		}
		else
		{
			// Do nothing
		}
	    m_pRenderer->renderPresent();
	}
	else
	{
		// Do nothing
	}
}
void SDLWindowHandler::update()
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
void SDLWindowHandler::handleEvents()
{
	if (m_isAbleToRun)
	{
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

bool SDLWindowHandler::isInitiated()
{
	return m_isAbleToRun;
}
std::shared_ptr<SDLRenderer> SDLWindowHandler::getRenderer()
{
	return m_pRenderer;
}
void SDLWindowHandler::setTheActivist(std::shared_ptr<gameObject>& anObj)
{
	m_gameActivist = anObj;
}
