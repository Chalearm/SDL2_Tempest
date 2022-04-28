#ifndef __ENEMY__
#define __ENEMY__
#include <random>
#include <vector>
#include <memory>
#include <ctime>
#include "gameDataType.h"
#include "color.h"
#include "point.h"
#include "walkPath.h"
#include "lineWithColor.h"
class enemy
{
protected:
	point<double> m_refPoint; // the center point of the level (polygon)
     std::vector<lineWithColor> m_lines;
	color m_bodyColor;
	double m_scale;
	double m_currentPosition; // h = 0 %  (0.0) - 100% (1.0) , 100% is at the top (edge of the polygon)
	double m_speed; // dh/dt (should be 1% - 10% (0.01 - 0.1) -- 100% (1.0) = the lane's length )
	std::shared_ptr<std::vector<walkPath<double> > >& m_refLanes; // (the reference of the lanns where enemy can go around)
	int m_beingLane;    // which lane where enemy stays
	bool m_isAlive;

	double m_timeToMove; // in second;
	std::clock_t m_startTime;
	bool m_isTimeUp;
	void addToLineVect(const point<double>& p1,const point<double>& p2, const color& col);
	void addToLineWitBodyColorVect(const point<double>& p1,const point<double>& p2);
	aLine<double> scaleAndTranslate(const aLine<double>& obj);
	point<double> findPointOnTheLine(const aLine<double> &l1, const double& distanceOnTheLine);
	point<double> findPointInBetweenALane(const walkPath<double> &w,const double& percentageOfDistance =0.0, const double& percentageOfDistBetweenRLline = 0.0); // 0 - 100% = 0.00 to 1.00
public:
     // random fundion
	static std::random_device s_rd;
	static std::mt19937 s_gen;

	enemy(std::shared_ptr<std::vector<walkPath<double> > > &refLanes, const double& scale, const point<double>& refPoint);
	enemy(const enemy& obj);
	enemy& operator=(const enemy& obj);
	virtual ~enemy();
	bool isHitTheBullet(const point<double> &bulletPoint);
	bool isAlive()const;
	virtual void move();
     virtual std::vector<lineWithColor> drawEnemy();
	static double randomFn(double max,double min);
};

#endif /* define (__ENEMY__) */
