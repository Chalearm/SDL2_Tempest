#include "lineWithColor.h"

lineWithColor::lineWithColor(const aLine<double>& l1,const color& col):
m_line(l1),
m_color(col)
{}

lineWithColor::lineWithColor(const lineWithColor& obj):
m_line(obj.m_line),
m_color(obj.m_color)
{

}

lineWithColor::~lineWithColor()
{

}
// overload functions
lineWithColor& lineWithColor::operator=(const lineWithColor& obj)
{
    if (this != &obj)
    {
        m_line = obj.m_line;
        m_color = obj.m_color;
    }
    else
    {
        // Do nothing
    }
    return *this;
}

aLine<double> lineWithColor::getLine()const
{
    return m_line;
}
color lineWithColor::getColor()const
{
    return m_color;
}