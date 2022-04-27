#ifndef __GAMEOBJ__
#define __GAMEOBJ__
#include <iostream>
#include "color.h"

class gameObj
{
private: 
public:
	gameObj();
    gameObj(const gameObj &obj);
	virtual ~gameObj();

    virtual void loadParameter(const std::string &txt = "",const int& opt = 0);
    virtual void setShownDimension(const int& x = 0, const int& y = 0, const int& w = 0, const int& h = 0);
    virtual void setDrawPosition(const int& x = 0, const int& y = 0, const int& w = 0, const int& h = 0);
    virtual void setAngel(const double& ang = 0.0);
    virtual void setColor(const color& aColor);
    virtual void drawImgEx();
    virtual void rotateFromCurrentPos(const double& deltaAng = 0.0);
    virtual void moveFromCurrentPos(const int& deltaX = 0,const int& deltaY = 0);
};

#endif /* define (__GAMEOBJ__) */
