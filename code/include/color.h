//  
//
//     color
//
//     define in header color
//     class color
//     
//     color stores color value (Red, Green, Blue and Alpha) as the SDL_Color object and gradient color value 
//     it provides following methods:
//     setGradientColor : update gradient color = gradient (r, g, b, a)
//     accumulateColor : update color value (r, g, b or a) of SDL_Color object  and update gradient color value
//     moveForwardColor : update color values --> new color = color + gradient col
//     moveBackwardColor : update color values --> new color = color - gradient col
//     changeBasecolor : update the color value of SDL_Color object (r, g, b, or a)
//     getColorVal : return the color value (r, g, b or a)  
//     getSDLCol : return SDL_Color object
//
//
#ifndef __COLOR__
#define __COLOR__
#include <SDL2/SDL.h>
#include <map>
#include "gameDataType.h"

class color
{
private:
	SDL_Color m_sdlColor;
	char m_gradientRed;
	char m_gradientGreen;
	char m_gradientBlue;
	char m_gradientAlpha;

public:
    static std::map<GameColor,color> create_ColorMap();

	color(const unsigned char& r = 255,const unsigned char& g = 255,const unsigned char& b = 255,const unsigned char& a = 255);
	color(const color& obj);
	color& operator=(const color& obj);
	bool operator==(const color& obj);
	bool operator!=(const color& obj);

	void setGradientColor(const color& obj);
	void accumulateColor(const GameColor &col, const char& delCol);
	void changeBasecolor(const GameColor &col, const unsigned char& val);
	void moveForwardColor();
    void moveBackwardColor();
    unsigned char getColorVal(const GameColor &col);
    SDL_Color getSDLCol() const;
};

#endif /* define (__COLOR__) */
