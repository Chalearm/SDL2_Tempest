#include "color.h"

color::color(const unsigned char& r,const unsigned char& g,const unsigned char& b,const unsigned char& a):
m_sdlColor(),
m_gradientRed(0),
m_gradientGreen(0),
m_gradientBlue(0), 
m_gradientAlpha(0)
{
	m_sdlColor.r = r;
	m_sdlColor.g = g;
	m_sdlColor.b = b;
	m_sdlColor.a = a;
}

color::color(const color& obj):
m_sdlColor(obj.m_sdlColor),
m_gradientRed(obj.m_gradientRed),
m_gradientGreen(obj.m_gradientGreen),
m_gradientBlue(obj.m_gradientBlue),
m_gradientAlpha(obj.m_gradientAlpha)
{}

color& color::operator=(const color& obj)
{
	if (this != &obj)
	{
	    m_sdlColor = obj.m_sdlColor;
	    m_gradientRed = obj.m_gradientRed;
	    m_gradientGreen = obj.m_gradientGreen;
	    m_gradientBlue = obj.m_gradientBlue;
	    m_gradientAlpha = obj.m_gradientAlpha;
	}
	else
	{
		// Do nothing
	}
	return *this;
}

void color::setGradientColor(const color& obj)
{
	if (this != &obj)
	{
	    m_gradientRed = obj.m_gradientRed;
	    m_gradientGreen = obj.m_gradientGreen;
	    m_gradientBlue = obj.m_gradientBlue;
	    m_gradientAlpha = obj.m_gradientAlpha;
	}
	else
	{
		// Do nothing
	}
}
void color::accumulateColor(const GameColor &col, const char& delCol)
{
    switch(col)
    {
    	case RED:
    	    m_sdlColor.r += delCol;
    	    m_gradientRed = delCol;
    	break;
    	case GREEN:
    	    m_sdlColor.g += delCol;
    	    m_gradientGreen = delCol;
    	break;
    	case BLUE:
    	    m_sdlColor.b += delCol;
    	    m_gradientBlue = delCol;
    	break;
    	case ALPHA:
    	    m_sdlColor.a += delCol;
    	    m_gradientAlpha = delCol;
    	break;
    	default:
    	    // Do nothing
    	break;
    }
}
void color::moveForwardColor()
{
	m_sdlColor.r += m_gradientRed;
	m_sdlColor.g += m_gradientGreen;
	m_sdlColor.b += m_gradientBlue;
	m_sdlColor.a += m_gradientAlpha;
}
void color::moveBackwardColor()
{
	m_sdlColor.r -= m_gradientRed;
	m_sdlColor.g -= m_gradientGreen;
	m_sdlColor.b -= m_gradientBlue;
	m_sdlColor.a -= m_gradientAlpha;
}
void color::changeBasecolor(const GameColor &col, const unsigned char& val)
{
    switch(col)
    {
    	case RED:
    	    m_sdlColor.r = val;
    	break;
    	case GREEN:
    	    m_sdlColor.g = val;
    	break;
    	case BLUE:
    	    m_sdlColor.b = val;
    	break;
    	case ALPHA:
    	    m_sdlColor.a = val;
    	break;
    	default:
    	    // Do nothing
    	break;
    }
}
unsigned char color::getColorVal(const GameColor &col)
{
	unsigned char ret = 0;
    switch(col)
    {
    	case RED:
    	    ret = m_sdlColor.r;
    	break;
    	case GREEN:
    	    ret = m_sdlColor.g;
    	break;
    	case BLUE:
    	    ret = m_sdlColor.b;
    	break;
    	case ALPHA:
    	    ret = m_sdlColor.a;
    	break;
    	default:
    	    // Do nothing
    	break;
    }
    return ret;
}

SDL_Color color::getSDLCol() const
{
    return m_sdlColor;
}