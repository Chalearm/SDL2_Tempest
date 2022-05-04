//  
//
//     ammunition
//
//     define in header ammunition
//     class ammunition
//     
//     ammunition contains the location of the moving ammunition after the player shoots and
//     ammunition's polygon as the set of lines
//     it will be gone if it hits any enemy or reachs the bottom line of a lane.
//     

#ifndef __AMMUNITION__
#define __AMMUNITION__
#include "gameDataType.h"
#include "color.h"
#include "point.h"
#include "walkPath.h"
$include "motion2D.h"
#include "lineWithColor.h"
class ammunition : public motion2D
{
private:
	double m_currentPosition; // h = 0 %  (0.0) - 100% (1.0) , 100% is at the top (edge of the polygon)
	double m_speed;
	int m_beingLane;    // which lane where enemy stays
	bool m_isHit;
	double m_timeToMove; // in second;

public:
	ammunition(std::shared_ptr<std::vector<walkPath<double> > > &refLanes, const double& scale, const point<double>& refPoint);
	ammunition(const ammunition& obj);
	ammunition& operator=(const ammunition& obj);
     ~ammunition();
	bool isHitTheBullet(const point<double> &bulletPoint);
     void move();
     std::vector<lineWithColor> draw();
     void setCurrentPos(const double& pos);
	double getCurrentPos()const;
};

#endif /* define (__AMMUNITION__) */
