#include "gameObj.h"
#define UNUSED(expr) do { (void)(expr); } while (0)
gameObj::gameObj()
{}

gameObj::gameObj(const gameObj &obj)
{}

gameObj::~gameObj()
{}

void gameObj::loadParameter(const std::string &txt,const int& opt)
{
    UNUSED(txt);
	UNUSED(opt);
}

void gameObj::setShownDimension(const int& x, const int& y, const int& w, const int& h)
{
    UNUSED(x);
    UNUSED(y);
    UNUSED(w);
    UNUSED(h);
}

void gameObj::setColor(const color& aColor)
{
    UNUSED(aColor);
}
void gameObj::setDrawPosition(const int& x, const int& y, const int& w, const int& h)
{
    UNUSED(x);
    UNUSED(y);
    UNUSED(w);
    UNUSED(h);
}
void gameObj::setAngel(const double& ang)
{
    UNUSED(ang);
}
void gameObj::drawImgEx()
{}

void gameObj::rotateFromCurrentPos(const double& deltaAng)
{
	UNUSED(deltaAng);
}

void gameObj::moveFromCurrentPos(const int& deltaX,const int& deltaY)
{
	UNUSED(deltaX);
	UNUSED(deltaY);
}