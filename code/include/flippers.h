#ifndef __FLIPPERS__
#define __FLIPPERS__
#include "enemy.h"
#include "point.h"

class flippers : public enemy
{
private:
    point<double> m_p1;
    point<double> m_p2;
    point<double> m_p3;
    point<double> m_p4;

public:
	flippers(std::shared_ptr<std::vector<walkPath<double> > > &refLanes, const double& scale, const point<double>& refPoint);
	~flippers();
	flippers(const flippers& obj);
	flippers& operator=(const flippers& obj);
	std::vector<aLine<double> > drawEnemy();
	void move();
};

#endif /* define (__FLIPPERS__) */
