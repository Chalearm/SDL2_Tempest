#include "sdlObject.h"

SDLObject::SDLObject(const std::string &filePath, const bool isLoadedText):
SDLDrawnObj(),
m_sdlSimpleLib(),
m_pChildObj(),
m_filePath(filePath),
m_loadedOpt(0),
randomVal(0)
{}

SDLObject::SDLObject(const SDLObject& obj):
SDLDrawnObj(obj),
m_sdlSimpleLib(obj.m_sdlSimpleLib),
m_pChildObj(obj.m_pChildObj),
m_filePath(obj.m_filePath),
m_loadedOpt(obj.m_loadedOpt),
randomVal(obj.randomVal)
{
	if (obj.m_filePath != "")
	{
		loadParameter(obj.m_filePath,obj.m_loadedOpt);
	}
	else
	{
		// Do nothing
	}
}
SDLObject::~SDLObject()
{
}

void SDLObject::loadParameter(const std::string &txt,const int& opt)
{
	if (txt != "")
	{
		m_filePath = txt;
		m_loadedOpt = opt;
		SDLDrawnObj::loadParameter(txt,opt);
	}
	else
	{
		// Do nothing
	}
}
void SDLObject::init()
{    
	if (m_sdlSimpleLib)
	{
		//loadImage(m_filePath);
	//	SDLDrawnObj::operator=(m_sdlSimpleLib->loadImage(m_filePath,m_objectId));

	}
	else
	{
		// Do nothing
	}
}

void SDLObject::render()
{
	/*
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
*/
	if (m_sdlSimpleLib)
	{

		//m_sdlSimpleLib->setRenderDrawColor(0,255,255,255);
		//m_sdlSimpleLib->drawObj(m_objectId);
        drawImgEx();
	}
	else
	{
		// Do nothing
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

//	m_sourceRectangle.x = 128*int(((SDL_GetTicks()/100)%6));
	/*
		if (randomVal > 0) // non SDL_FLIP
	{
		m_flipOption = 0;
	}
	else
	{
		m_flipOption = 1;
	}
*/
	// move the coorinate to choose the next frame of an image 
	/*
	int newXval = 128*int(((clock()/100)%6));
    int newXVal2 = (randomVal*(clock()%101/100) )%640;
    int newYVal2 = (randomVal*(clock()%101/100) )%640;

	moveFromCurrentPos(newXVal2,newYVal2);
	setShownDimension(newXval, 0, 128, 72);

	*/

}
void SDLObject::setRandValue(const int& val)
{
    randomVal = val; 
}

void SDLObject::handleEvents(const unsigned char& keyPress)
{

}
void SDLObject::clean()
{

}
/*
void SDLObject::setGeometry(const int& x,const int& y, const int& w,const int& h)
{
	m_gameObj->setShownDimension(x, y, w, h);
}
*/
void SDLObject::setSDLHandler(const std::shared_ptr<SDLHandler> &obj)
{
	m_sdlSimpleLib = obj;
}