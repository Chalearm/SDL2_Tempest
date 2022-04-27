#ifndef __ENEMY__
#define __ENEMY__
#include <random>
#include "gameDataType.h"
#include "point.h"
#include "walkPath.h"

class enemy
{
protected:
	point<double> m_refPoint; // the center point of the level (polygon)
	double m_currentPosition; // h = 0 %  (0.0) - 100% (1.0) , 100% is at the top (edge of the polygon)
	double m_speed; // dh/dt (should be 1% - 10% (0.01 - 0.1) -- 100% (1.0) = the lane's length )
    std::shared_ptr<std::vector<walkPath<double> > >& m_refLanes; // (the reference of the lanns where enemy can go around)
    int m_beingLane;    // which lane where enemy stays
    bool m_isAlive;


public:
     // random fundion
	static std::random_device s_rd;
	static std::mt19937 s_gen;

	enemy(std::shared_ptr<std::vector<walkPath<double> > > &refLanes,const point<double>& refPoint);
	enemy(const enemy& obj);
	enemy& operator=(const enemy& obj);
	virtual ~enemy();
	bool isHitTheBullet(const point<double> &bulletPoint);
	bool isAlive()const;
	virtual void move();

	static double randomFn(double max,double min);
};

#endif /* define (__ENEMY__) */
