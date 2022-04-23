#ifndef __GAMECONSTANCE__
#define __GAMECONSTANCE__
#include <iostream>
#include <map> 
#include "gameDataType.h"
#include "color.h"
//enum GameColor {WHITE, BLACK, BLUE, RED, GREEN, DARK_GREEN, YELLOW, ORANGE,LIGHT_GREY,MAGENTA,ALPHA};
// constanst
std::map<GameColor, color> COLORSET(color::create_ColorMap());


#endif /* define (__GAMECONSTANCE__) */
