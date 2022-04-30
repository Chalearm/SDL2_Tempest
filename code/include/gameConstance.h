//  
//
//     gameConstance
//     
//     provides all constances for the game : color and dimension
//
//
#ifndef __GAMECONSTANCE__
#define __GAMECONSTANCE__
#include <iostream>
#include <map> 
#include "gameDataType.h"
#include "color.h"
#include "point.h"
//enum GameColor {WHITE, BLACK, BLUE, RED, GREEN, DARK_GREEN, YELLOW, ORANGE,LIGHT_GREY,MAGENTA,ALPHA};
// constanst
std::map<GameColor, color> COLORSET(color::create_ColorMap());

const color g_tankerColor = COLORSET[MAGENTA];
const color g_spikersColor = COLORSET[GREEN];
const color g_spikersTrackColor = COLORSET[ORANGE];
const color g_flippersColor = COLORSET[RED];


const int g_window_height = 600;
const int g_window_width = 800;
const double g_lvScale = 4.6;
const double g_ratioScreen = g_window_width/640.0;
const point<double> g_refPoint((g_window_width - g_lvScale*100.0)/2.0,(g_window_height - g_lvScale*100.0)/2.0);

#endif /* define (__GAMECONSTANCE__) */
