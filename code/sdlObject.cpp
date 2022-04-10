
#include "sdlObject.h"

SDLObject::SDLObject(const std::string &filePath):
m_pRenderer(),
m_pTexture(nullptr),
m_sourceRectangle(),
m_destinationRectangle(),
m_flipOption(0),
m_filePath(filePath)
{}

SDLObject::~SDLObject()
{
	if (m_pTexture != nullptr)
	{
        SDL_DestroyTexture(m_pTexture);
        m_pTexture = nullptr;
	}
	else
	{
		// Do nothing
	}
}
void SDLObject::init()
{
	SDL_Surface* pTempSurface = IMG_Load(m_filePath.c_str());
	if ((pTempSurface != nullptr) && (m_pRenderer.get() != nullptr))
	{	
		m_pTexture = m_pRenderer->createTextureFromSurface(pTempSurface);
     	SDL_FreeSurface(pTempSurface);
	}
	else
	{
		// Do nothing
	}
}

void SDLObject::render()
{
	SDL_RendererFlip flipVal = SDL_FLIP_NONE;
	switch (m_flipOption )
	{
		case 1:
		    flipVal = SDL_FLIP_HORIZONTAL;
		break;
		case 2:
		    flipVal = SDL_FLIP_VERTICAL;
		break;
		default:
		    flipVal = SDL_FLIP_NONE;
		break;
	}
	m_pRenderer->renderCopyEx(m_pTexture,&m_sourceRectangle,&m_destinationRectangle,0,0, flipVal);
}
void SDLObject::setRenderer(const std::shared_ptr<SDLRenderer> &aRenderer)
{
	m_pRenderer = aRenderer;
}
void SDLObject::update()
{

	m_sourceRectangle.x = 128*int(((SDL_GetTicks()/100)%6));
		if (randomVal > 0) // non SDL_FLIP
	{
		m_flipOption = 0;
	}
	else
	{
		m_flipOption = 1;
	}

	// move the coorinate to choose the next frame of an image 
	m_sourceRectangle.x = 128*int(((SDL_GetTicks()/100)%6));
	m_destinationRectangle.x = (m_destinationRectangle.x + randomVal*(SDL_GetTicks()%101/100) )%640;
	m_destinationRectangle.y = (m_destinationRectangle.y + randomVal*(SDL_GetTicks()%101/100) )%480;
}
void SDLObject::handleEvents()
{

}
void SDLObject::clean()
{

}

void SDLObject::setRandomVal(const int randVal)
{
	randomVal = randVal;
}
void SDLObject::setSourceRect(const int &x,const int &y,const int &w,const int &h)
{
	m_sourceRectangle.x = x;
	m_sourceRectangle.y = y;
	m_sourceRectangle.w = w;
	m_sourceRectangle.h = h;
}
void SDLObject::setDestinationRect(const int &x,const int &y,const int &w,const int &h)
{
	m_destinationRectangle.x = x;
	m_destinationRectangle.y = y;
	m_destinationRectangle.w = w;
	m_destinationRectangle.h = h;
}