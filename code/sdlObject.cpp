
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
void SDLObject::update()
{

}
void SDLObject::handleEvents()
{

}
void SDLObject::clean()
{

}
void SDLObject::setSourceRect(const int &x,const int &y,const int &w,const int &h)
{

}
void SDLObject::setDestinationRect(const int &x,const int &y,const int &w,const int &h)
{

}