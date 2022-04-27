#include "enemy.h"


enemy::enemy(std::vector<walkPath<double> > &refLanes, const point<double>& refPoint):
m_refPoint(refPoint),
m_currentPosition(obj.m_currentPosition),
m_speed(0),
m_refLanes(refLanes),
m_beingLane(0),
m_isAlive(true),
m_rd(),
m_gen(m_rd())
{
	m_beingLane = static_cast<int>(randomFn(refLanes.size()-1,0.0));
}

enemy::~enemy()
{
	m_isAlive = false;
}
bool enemy::isHitTheBullet(const point<double> &bulletPoint)
{

}

bool enemy::isAlive()const
{
	return m_isAlive;
}

void enemy::move()
{

}

int enemy::randomFn(double max,double min)
{	
	std::uniform_real_distribution<> distrib(min,max);
	return distrib(m_gen);
}