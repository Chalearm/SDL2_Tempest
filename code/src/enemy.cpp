#include "enemy.h"

std::random_device enemy::s_rd;
std::mt19937 enemy::s_gen;

enemy::enemy(std::shared_ptr<std::vector<walkPath<double> > > &refLanes, const double& scale, const point<double>& refPoint):
m_refPoint(refPoint),
m_scale(scale),
m_currentPosition(0),
m_speed(0),
m_refLanes(refLanes),
m_beingLane(0),
m_isAlive(true),
m_timeToMove(0.01),  // 0.3 second
m_startTime(std::clock()),
m_isTimeUp(false)
{
	//m_refLanes = refLanes;
	m_beingLane = static_cast<int>(randomFn(refLanes->size()-1,0.0));
}

enemy::enemy(const enemy& obj):
m_refPoint(obj.m_refPoint),
m_currentPosition(obj.m_currentPosition),
m_speed(obj.m_speed),
m_refLanes(obj.m_refLanes),
m_beingLane(obj.m_beingLane),
m_isAlive(obj.m_isAlive),
m_timeToMove(obj.m_timeToMove),  // 0.3 second
m_startTime(obj.m_startTime),
m_isTimeUp(obj.m_isTimeUp)
{}


enemy& enemy::operator=(const enemy& obj)
{
    if (this != &obj)
    {
    	
    	m_refPoint = obj.m_refPoint;
      m_currentPosition = obj.m_currentPosition;
      m_speed = obj.m_speed;
      m_refLanes = obj.m_refLanes;
      m_beingLane = obj.m_beingLane;    // which lane where enemy stays
      m_isAlive = obj.m_isAlive;
      m_timeToMove = obj.m_timeToMove;
      m_isTimeUp = obj.m_isTimeUp;
        
       // enemy::enemy(obj);
    }
    else
    {
    	// Do nothing
    }
    return *this;
}

enemy::~enemy()
{
	m_isAlive = false;
}
bool enemy::isHitTheBullet(const point<double> &bulletPoint)
{
   return true;
}

std::vector<aLine<double> > enemy::drawEnemy()
{
	return std::vector<aLine<double> >();
}
bool enemy::isAlive()const
{
	return m_isAlive;
}

void enemy::move()
{
	const double duration = ( std::clock() - m_startTime ) / (double) CLOCKS_PER_SEC;
	m_isTimeUp =  (duration > m_timeToMove);
	if (m_isTimeUp)
	{
		m_startTime = std::clock();
	}
	else
	{
		// Do nothing
	}

}

double enemy::randomFn(double max,double min)
{	
	std::uniform_real_distribution<> distrib(min,max);
	return distrib(s_gen);
}