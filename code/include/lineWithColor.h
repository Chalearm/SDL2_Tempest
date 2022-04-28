#ifndef __LINEWITHCOLOR__
#define __LINEWITHCOLOR__
#include "aLine.h"
#include "color.h"
#include "gameDataType.h"
#include "gameConstance.h"

class lineWithColor 
{
private:
    aLine<double> m_line;
    color m_color;

public:
	lineWithColor(const aLine<double>& l1,const color& col);
    lineWithColor(const lineWithColor& obj);
    ~lineWithColor();
    // overload functions
    lineWithColor& operator=(const lineWithColor& obj);

    aLine<double> getLine()const;
    color getColor()const;
  //  static aLine<double> operator=(const lineWithColor& obj);
   // static color operator=(const lineWithColor& obj);

};

#endif /* define (__LINEWITHCOLOR__) */
