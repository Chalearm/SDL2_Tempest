//  
//
//     player
//
//     define in header player
//     class player
//     
//     player is a class which is for hanndling the player 
//
//
#ifndef __PLAYER__
#define __PLAYER__
#include <vector>
#include <memory>
#include "walkPath.h"
//#include "ammunition.h"
#include "point.h"
#include "gameConstance.h"

class player : public motion2D
{
private:
   // std::shared_ptr<std::vector<ammunition > > m_bullets;
	double m_currentPosition; // h = 0 %  (0.0) - 100% (1.0) , 100% is at the top (edge of the polygon)
    int m_numberOfLife;
    int m_beingLane;

public:
    player(std::shared_ptr<std::vector<walkPath<double> > > &refLanes, const double& scale, const point<double>& refPoint);
    player(const player& obj);
    player& operator=(const player& obj);
    ~player();
    std::vector<lineWithColor> draw();
	void move();
};

#endif /* define (__player__) */
