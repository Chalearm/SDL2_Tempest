//  
//
//     enemy
//
//     define in header enemy
//     abstract class enemy
//     
//     enemy provides the interface and common attributes for general enemy (Tankers, spikers, flippers or etc)
//     and common methods to control movement of any enemy object. 
//     it provides following methods:


#ifndef __ENEMY__
#define __ENEMY__
#include "gameDataType.h"
#include "point.h"
#include "walkPath.h"
#include "motion2D.h"
class enemy : public motion2D
{
protected:

	double m_currentPosition; // h = 0 %  (0.0) - 100% (1.0) , 100% is at the top (edge of the polygon)
	double m_positionToTransform; // h = 0 %  (0.0) - 100% (1.0) , 100% is at the top (edge of the polygon)
	double m_speed; // dh/dt (should be 1% - 10% (0.01 - 0.1) -- 100% (1.0) = the lane's length )
	int m_beingLane;    // which lane where enemy stays
	bool m_isAlive;

	double m_timeToMove; // in second;
	double m_timeToAlive; // random between 0 - 4 seconds
	EnemyType m_myType;

public:

	enemy(std::shared_ptr<std::vector<walkPath<double> > > &refLanes, const double& scale, const point<double>& refPoint);
	enemy(const enemy& obj);
	enemy& operator=(const enemy& obj);
	virtual ~enemy();
	bool isHitTheBullet(const point<double> &bulletPoint);
	bool isAlive()const;
     void move();
     virtual std::vector<lineWithColor> drawEnemy() = 0;
	virtual bool transform()const;
	virtual void setCurrentPos(const double& pos);
	double getCurrentPos()const;
	int getCurrentBeingLane()const;
	EnemyType getMyType()const;

	double randomFn(const double& max,const double& min);
};

#endif /* define (__ENEMY__) */
