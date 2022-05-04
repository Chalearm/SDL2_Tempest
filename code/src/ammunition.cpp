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

#include "ammunition.h"
class ammunition : public motion2D
{
private:
	double m_currentPosition; // h = 0 %  (0.0) - 100% (1.0) , 100% is at the top (edge of the polygon)
	double m_speed;
	int m_beingLane;    // which lane where enemy stays
	bool m_isHit;
	double m_timeToMove; // in second;

public:

};
ammunition::ammunition(std::shared_ptr<std::vector<walkPath<double> > > &refLanes, const double& scale, const point<double>& refPoint):
motion2D(refLanes,scale,refPoint),
m_currentPosition(1.0), // 100%
m_speed(0.01),
m_beingLane(0),
m_isHit(false),
m_timeToMove(0.01)
{

}
ammunition::ammunition(const ammunition& obj):
motion2D(obj),
m_currentPosition(obj.m_currentPosition),
m_speed(obj.m_speed),
m_beingLane(obj.m_beingLane),
m_isHit(obj.m_isHit),
m_timeToMove(obj.m_timeToMove)
{

}
ammunition& operator=(const ammunition& obj)
{
    if (this != &obj)
    {
        motion2D::operator=(obj);
        m_currentPosition = obj.m_currentPosition;
        m_speed = obj.m_speed;
        m_beingLane = obj.m_beingLane;
        m_isHit = obj.m_isHit;
        m_timeToMove = obj.m_timeToMove;
    }
    else
    {
        // Do nothing
    }
    return *this;
}
ammunition::~ammunition()
{

}
bool ammunition::isHitTheBullet(const point<double> &bulletPoint)
{
    return m_isHit;
}
void ammunition::move()
{
	if (isTimeup())
	{

	}
	else
	{
		// Do norhing
	}
}
std::vector<lineWithColor> ammunition::draw()
{
	return m_lines;
}
void ammunition::setCurrentPos(const double& pos)
{
	m_currentPosition = pos;
}
double ammunition::getCurrentPos()const
{
	return m_currentPosition;
}
