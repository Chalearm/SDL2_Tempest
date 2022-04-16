#ifndef __GAMECONSTANCE__
#define __GAMECONSTANCE__
#include <iostream>
#include <map> 
#include "gameDataType.h"
#include "color.h"

// constanst
/*
 std::map<GameColor,color> COLORSET = {{WHITE,color()},
                                            {BLACK,color(0,0,0,255)},
                                            {BLUE, color(0,0,255,255)},
                                            {RED, color(255,0,0,255)},
                                            {GREEN, color(0,255,0,255)},
                                            {DARK_GREEN, color(0,70,0,255)},
                                            {YELLOW, color(255,255,0,255)},
                                            {ORANGE, color(255,165,0,255)},
                                            {LIGHT_GREY, color(192,192,192,255)},
                                            {MAGENTA, color(255,0,255,255)}};

*/

    //std::map<std::string, int> m { {"CPU", 10}, {"GPU", 15}, {"RAM", 20}};
   // std::map<GameColor, color> COLORSET; 
 //   COLORSET = {WHITE,color()};
struct A{
    static std::map<int,int> create_map()
        {
          std::map<int,int> m;
          m[1] = 2;
          m[3] = 4;
          m[5] = 6;
          return m;
        }
    static const std::map<int,int> myMap;

};

struct AColorPlate{
    static std::map<GameColor,color> create_map()
        {
          std::map<GameColor,color> m;
			m[WHITE] = color();
			m[BLUE] = color(0,0,255,255);
			m[RED] = color(255,0,0,255);
			m[GREEN] = color(0,255,0,255);
			m[DARK_GREEN] = color(0,70,0,255);
			m[YELLOW] = color(255,255,0,255);
			m[ORANGE] = color(255,165,0,255);
          return m;
        }
    static const std::map<GameColor,color> myMap;

};




 std::map<GameColor, color> COLORSET = AColorPlate::create_map();
 //std::map<GameColor,color> COLORSET =  std::map<GameColor,color>({ {WHITE,color()}, {BLACK,color(0,0,0,255)}, {BLUE, color(0,0,255,255)}, {RED, color(255,0,0,255)},{GREEN, color(0,255,0,255)},{DARK_GREEN, color(0,70,0,255)},{YELLOW, color(255,255,0,255)},{ORANGE, color(255,165,0,255)},{LIGHT_GREY, color(192,192,192,255)},{MAGENTA, color(255,0,255,255)}});
 //color obss;
 //COLORSET[WHITE] = obss;
 /*

 COLORSET[BLUE] = color(0,0,255,255);
 COLORSET[RED] = color(255,0,0,255);
 COLORSET[GREEN] = color(0,255,0,255);
 COLORSET[DARK_GREEN] = color(0,70,0,255);
 COLORSET[YELLOW] = color(255,255,0,255);
 COLORSET[ORANGE] = color(255,165,0,255);
*/

#endif /* define (__GAMECONSTANCE__) */
