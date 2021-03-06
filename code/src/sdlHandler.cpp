#include <iostream>
#include "sdlHandler.h"

std::shared_ptr<SDLHandler> SDLHandler::theSdlHandler = nullptr;

SDLHandler::SDLHandler(const std::string &windowTitle,const int &windowWidth, const int &windowHeight):
m_pWindow(),
//m_sdlDrawnObjList(),
m_titleMessage(windowTitle),
m_windowWidth(windowWidth),
m_windowheight(windowHeight),
m_isAbleToRun(false),
m_gameActivist(std::make_shared<gameState>())
{}

SDLHandler::~SDLHandler()
{
	clean();
}

std::shared_ptr<SDLHandler> SDLHandler::GetInstance(const std::string &windowTitle,const int &windowWidth, const int &windowHeight)
{
	if (theSdlHandler.get() == nullptr)
	{
		//SDLHandler aSDLHandler(windowTitle,windowWidth,windowHeight);
		theSdlHandler.reset(new SDLHandler(windowTitle,windowWidth,windowHeight));
	}
	else
	{
		// Do nothing
	}
	return theSdlHandler;
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
        if (m_gameActivist)
		{
			m_gameActivist->init();
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
void SDLHandler::clean()
{
	SDLDrawnObj::SDLImgAndTffQuit();
	SDL_Quit();
}

void SDLHandler::render()
{
	if (isAbleToRun())
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
	if ((m_gameActivist) && (isAbleToRun()))
	{
		m_gameActivist->update();
	}
	else
	{
		// Do nothing
	}
}
void SDLHandler::handleEvents(const unsigned char& keyPress)
{
	if (isAbleToRun())
	{
		unsigned char keyboardValue = 0;
	    SDL_Event event;
	    if (SDL_PollEvent(&event))
	    {
	    	switch (event.type)
	    	{
	    		case SDL_QUIT:
	    		    m_isAbleToRun = false;
	    		break;
	    		case SDL_KEYDOWN:
	    		    switch(event.key.keysym.sym)
	    		    {
	    		    	case SDLK_ESCAPE:
	    		    	    m_isAbleToRun = false;
	    		    	break;
	    		    	default:
	    		    	    keyboardValue = event.key.keysym.sym;
	    		    	break;
	    		    }
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
			m_gameActivist->handleEvents(keyboardValue);
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

void SDLHandler::setTheActivist(std::shared_ptr<gameState> anObj)
{
	m_gameActivist = anObj;
}
/*
std::shared_ptr<gameObj> SDLHandler::loadImage(const std::string &path, int &id)
{
	std::shared_ptr<SDLDrawnObj> aGameobj = std::make_shared<SDLDrawnObj>();
	if (path != "")
	{
		m_sdlDrawnObjList.push_back(std::make_shared<SDLDrawnObj>());	
		id = (m_sdlDrawnObjList.size() - 1);
	}
	else
	{
		// Do nothing
	}
	if (id > -1)
	{
		m_sdlDrawnObjList[id]->loadImage(path);
		aGameobj = m_sdlDrawnObjList[id];
	}
	else
	{
		// Do nothing
	}
	return aGameobj;
}
*/
void SDLHandler::renderClear()
{
	SDLDrawnObj::renderClear();	
}

void SDLHandler::drawLine(const int& x1, const int& y1, const int& x2, const int& y2)
{
	SDL_RenderDrawLine(SDLDrawnObj::s_pRenderer.get(),x1,y1,x2,y2);
}

void SDLHandler::setRenderDrawColor(const color& aColor)
{
	SDL_Color tempColor = aColor.getSDLCol();
    SDL_SetRenderDrawColor(SDLDrawnObj::s_pRenderer.get(),tempColor.r,tempColor.g,tempColor.b,tempColor.a);
}
void SDLHandler::drawLine(const aLine<double>& line)
{
	drawLine(static_cast<int>(line[P1][X]),
             static_cast<int>(line[P1][Y]), 
             static_cast<int>(line[P2][X]),
             static_cast<int>(line[P2][Y]));

}
void SDLHandler::drawRectangle(const int& x1, const int& y1, const int& w, const int& h)
{
	int x2 = x1 + w - 1;
	int y2 = y1 + h - 1;
	SDL_RenderDrawLine(SDLDrawnObj::s_pRenderer.get(),x1,y1,x2,y1);
	SDL_RenderDrawLine(SDLDrawnObj::s_pRenderer.get(),x2,y1,x2,y2);
	SDL_RenderDrawLine(SDLDrawnObj::s_pRenderer.get(),x2,y2,x1,y2);
	SDL_RenderDrawLine(SDLDrawnObj::s_pRenderer.get(),x1,y2,x1,y1);
}
