
#include "sdlObject.h"

SDLObject::SDLObject(const std::string &filePath, const bool isLoadedText):
m_pTexture(nullptr),
m_pMsgTexture(nullptr),
m_pChildObj(),
m_sourceRectangle(),
m_destinationRectangle(),
m_flipOption(0),
m_filePath(filePath),
//m_aLoadedFont(nullptr),
m_isFont(isLoadedText),
randomVal(0)
{}

SDLObject::SDLObject(const SDLObject& obj):
m_pTexture(nullptr),
m_sourceRectangle(obj.m_sourceRectangle),
m_destinationRectangle(obj.m_destinationRectangle),
m_flipOption(obj.m_flipOption),
m_filePath(obj.m_filePath),
//m_aLoadedFont(nullptr),
m_isFont(obj.m_isFont),
randomVal(obj.randomVal)
{
	//setRenderer(obj.m_pRenderer);
	if (m_filePath != "")
	{
		init();
	}
	else
	{
		// Do nothing
	}
}
SDLObject::~SDLObject()
{
}

void SDLObject::init()
{    
	/*
	if (m_pRenderer)
	{
		if (m_isFont)
		{
			//m_aLoadedFont = std::unique_ptr<TTF_Font,SDLDestroyer> (TTF_OpenFont("./Hersheys.ttf", 24));
		}
		else
		{
		}
		std::unique_ptr<SDL_Surface, SDLDestroyer> pTempSurface(IMG_Load(m_filePath.c_str()));
		if (pTempSurface)
		{
	        // the new SDL_Texture variable
	        m_pTexture.reset(SDL_CreateTextureFromSurface(m_pRenderer.get(), pTempSurface.get()));	

		}
		else
		{
			// do nothing
		}
		SDL_Color White = {255, 255, 255};
	 
	}
	else
	{
		// do nothing
	}
	*/

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
	//if (m_pRenderer)
	{
		/*

		SDL_SetRenderDrawColor(m_pRenderer.get(),0,0,255,SDL_ALPHA_OPAQUE);
	 	SDL_RenderClear(m_pRenderer.get());  
		SDL_SetRenderDrawColor(m_pRenderer.get(),0,0,0,SDL_ALPHA_OPAQUE);
		*/
/*
SDL_Rect Message_rect; //create a rect
Message_rect.x = 30;  //controls the rect's x coordinate 
Message_rect.y = 0; // controls the rect's y coordinte
Message_rect.w = 150; // controls the width of the rect
Message_rect.h = 40; // controls the height of the rect

// (0,0) is on the top left of the window/screen,
// think a rect as the text's box,
// that way it would be very simple to understand

// Now since it's a texture, you have to put RenderCopy
// in your game loop area, the area where the whole code executes

// you put the renderer's name first, the Message,
// the crop size (you can ignore this if you don't want
// to dabble with cropping), and the rect which is the size
// and coordinate of your texture
m_pRenderer->renderCopy(m_pMsgTexture.get(), nullptr, &Message_rect);
*/
		/*

	SDL_RenderDrawLine(m_pRenderer.get(),320,200,300,240);
	SDL_RenderDrawLine(m_pRenderer.get(),300, 240, 340, 240);
	SDL_RenderDrawLine(m_pRenderer.get(),340, 240, 320, 200);
	SDL_RenderDrawLine(m_pRenderer.get(),0, 240, 320, 200);
    SDL_RenderCopyEx(m_pRenderer.get(),m_pTexture.get(),&m_sourceRectangle,&m_destinationRectangle,0,0, flipVal);
    */
	}
	//else
	{
		// Do nothing
	}
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