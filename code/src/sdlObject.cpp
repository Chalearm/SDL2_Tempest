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

	if (m_sdlSimpleLib)
	{
        drawImgEx();
	}
	else
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