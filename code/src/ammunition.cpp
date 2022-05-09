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

ammunition::ammunition(const std::shared_ptr<std::vector<walkPath<double> > > &refLanes, const double& scale, const point<double>& refPoint, const int& laneStarted):
motion2D(refLanes,scale,refPoint),
m_currentPosition(1.0), // 100%
m_speed(0.001),
m_beingLane(laneStarted),
m_isHit(false),
m_timeToMove(0.01),
m_maxCol(8.0),
m_minCol(0.0)
{
    m_bodyColor = g_bulletColor;
  //  randomScopeCol();
}

ammunition::ammunition(const ammunition& obj):
motion2D(obj),
m_currentPosition(obj.m_currentPosition),
m_speed(obj.m_speed),
m_beingLane(obj.m_beingLane),
m_isHit(obj.m_isHit),
m_timeToMove(obj.m_timeToMove),
m_maxCol(obj.m_maxCol),
m_minCol(obj.m_minCol)
{

}
ammunition& ammunition::operator=(const ammunition& obj)
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

void ammunition::randomScopeCol()
{
	double temp = 0.0;
	m_maxCol = randomFn(8.5,0.0);
	m_minCol = randomFn(8.5,0.0);
	if (m_minCol > m_maxCol)
	{
		temp = m_minCol;
		m_minCol = m_maxCol;
		m_maxCol = temp;
	}
	else
	{
		// Do nothing
	}
	std::cout<<" max :"<<m_maxCol<<" min:"<<m_minCol<<std::endl;

}
bool ammunition::isHitTheBullet(const point<double> &bulletPoint)
{
    return m_isHit;
}
void ammunition::move()
{
	if (isTimeup())
	{
		m_lines.clear();
		//eulidianDis
		const double widthOfBullet = 0.07;// 0.01 - 1.0  (1% to 100%)
		const double heightOfBullet = 0.07; // 0.01 - 1.0 (1% to 100%) 100% is the length of the lanes
		walkPath<double> aWalkpath = m_refLanes->at(m_beingLane);
		const double startedXPoint = (1-widthOfBullet)*0.5;
		const double endedXPoint =  widthOfBullet+startedXPoint;
		const point<double> p1 = findPointInBetweenALane(aWalkpath,m_currentPosition,startedXPoint);
		const point<double> p2 = findPointInBetweenALane(aWalkpath,m_currentPosition,endedXPoint);
		const point<double> p3 = findPointInBetweenALane(aWalkpath,m_currentPosition + heightOfBullet,startedXPoint);
		const point<double> p4 = findPointInBetweenALane(aWalkpath,m_currentPosition + heightOfBullet,endedXPoint);
	//	m_bodyColor = color::convertIntToGameColor(static_cast<int>(randomFn(m_maxCol,m_minCol)));
		//addToLineVect
		addToLineWitBodyColorVect(p1,p2);
		addToLineWitBodyColorVect(p2,p4);
		addToLineWitBodyColorVect(p4,p3);
		addToLineWitBodyColorVect(p3,p1);
		m_currentPosition -= m_speed;
		if (m_currentPosition < 0.0)
		{
			m_currentPosition = 0.0;
		}
		else
		{
			// Do nothing
		}
	}
	else
	{
		// Do norhing
	}
}


int ammunition::getCurrentBeingLane()const
{
    return m_beingLane;
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
