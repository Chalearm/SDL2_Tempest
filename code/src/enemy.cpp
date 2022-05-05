#include "enemy.h"

enemy::enemy(std::shared_ptr<std::vector<walkPath<double> > > &refLanes, const double& scale, const point<double>& refPoint):
motion2D(refLanes,scale,refPoint),
m_currentPosition(0),
m_positionToTransform(0),
m_speed(0),
m_beingLane(0),
m_isAlive(false),
m_timeToMove(0.01),  // 0.3 second
m_timeToAlive(0),
m_myType(ENEMY)
{
	//m_refLanes = refLanes;
	if (refLanes)
	{
		if (refLanes->size() > 0)
		{
		    m_beingLane = static_cast<int>(randomFn(refLanes->size()-1,0.0));
		}
		else
		{
			// Do nothing
		}
	}
	else
	{
		// Do nothing
	}
	m_timeToAlive = randomFn(9.0,0.0);
	motion2D::setTimeCount(m_timeToAlive);
	m_isAlive = (m_timeToAlive == 0.0);
}

enemy::enemy(const enemy& obj):
motion2D(obj),
m_currentPosition(obj.m_currentPosition),
m_positionToTransform(obj.m_positionToTransform),
m_speed(obj.m_speed),
m_beingLane(obj.m_beingLane),
m_isAlive(obj.m_isAlive),
m_timeToMove(obj.m_timeToMove),  // 0.3 second
m_myType(obj.m_myType)
{}


enemy& enemy::operator=(const enemy& obj)
{
	if (this != &obj)
	{
		m_currentPosition = obj.m_currentPosition;
		m_positionToTransform = obj.m_positionToTransform;
		m_speed = obj.m_speed;
		m_beingLane = obj.m_beingLane;    // which lane where enemy stays
		m_isAlive = obj.m_isAlive;
		m_timeToMove = obj.m_timeToMove;
		m_myType = obj.m_myType;
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

bool enemy::isAlive()const
{	
	return m_isAlive;
}

double enemy::getCurrentPos()const
{
	return m_currentPosition;
}
bool enemy::transform()const
{
	return m_isAlive&&(m_currentPosition >= m_positionToTransform);
}
void enemy::setCurrentPos(const double& pos)
{
    m_currentPosition = pos;
}
EnemyType enemy::getMyType()const
{
     return m_myType;
}
void enemy::move()
{
	if (isTimeup())
	{
		if (m_isAlive)
		{
			// Do nothing
		}
		else if (m_timeToAlive != 0.0)
		{
			m_timeToAlive = 0.0;
			m_isAlive = true;
			motion2D::setTimeCount(m_timeToMove);
		}
		else
		{
			// Do nothing
		}
	}

}

double enemy::randomFn(const double& max,const double& min)
{
	return motion2D::randomFn(max,min);
}