#include "flippers.h"


flippers::flippers(std::shared_ptr<std::vector<walkPath<double> > > &refLanes,const double& scale, const point<double>& refPoint):
enemy(refLanes,scale,refPoint),
m_p1(),
m_p2(),
m_p3(),
m_p4()
{

	m_speed = enemy::randomFn(0.001,-0.01);
	m_bodyColor = g_flippersColor;
	walkPath<double> aWalkpath = m_refLanes->at(m_beingLane);
	m_p1 = findPointInBetweenALane(aWalkpath,0.0,0.0);
	m_p2 = findPointInBetweenALane(aWalkpath,0.1,0.0);
	m_p3 = findPointInBetweenALane(aWalkpath,0.0,1.0);
	m_p4 = findPointInBetweenALane(aWalkpath,0.1,1.0);
	addToLineWitBodyColorVect(m_p1,m_p4);
	addToLineWitBodyColorVect(m_p2,m_p3);
	m_timeToMove = 0.03;
	m_timeToAlive = randomFn(0.2,0.0);
	m_myType = FLIPPERS;

}

flippers::~flippers()
{

}

flippers::flippers(const flippers& obj):
enemy(obj),
m_p1(obj.m_p1),
m_p2(obj.m_p2),
m_p3(obj.m_p3),
m_p4(obj.m_p4)
{

}
std::vector<lineWithColor > flippers::drawEnemy()
{
	return m_lines;
}
flippers& flippers::operator=(const flippers& obj)
{
	if (this != &obj)
	{
		enemy::operator=(obj);
		m_p1 = obj.m_p1;
		m_p2 = obj.m_p2;
		m_p3 = obj.m_p3;
		m_p4 = obj.m_p4;
	}
	else
	{
		// Do nothing
	}
	return *this;
}
void flippers::setCurrentPos(const double& pos)
{
	m_lines.clear();
	m_currentPosition = pos;
	walkPath<double> aWalkpath = m_refLanes->at(m_beingLane);
	m_p1 = findPointInBetweenALane(aWalkpath,m_currentPosition,0.0);
	m_p2 = findPointInBetweenALane(aWalkpath,m_currentPosition+ 0.1,0.0);
	m_p3 = findPointInBetweenALane(aWalkpath,m_currentPosition,1.0);
	m_p4 = findPointInBetweenALane(aWalkpath,m_currentPosition+0.1,1.0);

	const point<double> p5 = findPointInBetweenALane(aWalkpath,m_currentPosition+0.05,0.1);
	const point<double> p6 = findPointInBetweenALane(aWalkpath,m_currentPosition+0.05,0.9);
	//eulidianDis


	//addToLineVect
	addToLineWitBodyColorVect(m_p1,m_p4);
	addToLineWitBodyColorVect(m_p2,m_p3);
	addToLineWitBodyColorVect(m_p2,p5);
	addToLineWitBodyColorVect(m_p1,p5);
	addToLineWitBodyColorVect(m_p4,p6);
	addToLineWitBodyColorVect(m_p3,p6);
}

void flippers::move()
{
    if ((m_isTimeUp) && (static_cast<int>(m_currentPosition) <= 1.0) )
    {
        m_lines.clear();
        int direction = static_cast<int>(enemy::randomFn(10.0,0.0));
        const double directionUpOrDown = enemy::randomFn(1.0,-0.7);
        if (direction < 0.3)
        {
        	direction = -1;
        }
        else if (direction < 9.7)
        {
        	direction = 0;
        }
        else
        {
        	direction = 1;
        }
        m_beingLane += direction;
        double leftOrRight = 0.1;
        if (m_beingLane < 0)
        {
        	m_beingLane =m_refLanes->size() - 1;
        }
        else if (m_beingLane >= m_refLanes->size())
        {
        	m_beingLane = 0;
        }
        else
        {
        	// Do nothing
        }
        walkPath<double> aWalkpath = m_refLanes->at(m_beingLane);
        if (direction > 0)
        {
        	leftOrRight = 0.1;
        	m_p3 = m_p1;
        	m_p4 = m_p2;
        	m_p1 = findPointInBetweenALane(aWalkpath,m_currentPosition,1.0);
        	m_p2 = findPointInBetweenALane(aWalkpath,m_currentPosition+0.1,1.0);
        }
        else if (direction < 0)
        {
        	leftOrRight = 0.9;
        	m_p1 = m_p3;
        	m_p2 = m_p4;
        	m_p3 = findPointInBetweenALane(aWalkpath,m_currentPosition,0.0);
        	m_p4 = findPointInBetweenALane(aWalkpath,m_currentPosition+0.1,0.0);
        }
        const point<double> p5 = findPointInBetweenALane(aWalkpath,m_currentPosition+0.05,1.0 -leftOrRight);
        const point<double> p6 = findPointInBetweenALane(aWalkpath,m_currentPosition+0.05,leftOrRight);
        //eulidianDis


//addToLineVect
        addToLineWitBodyColorVect(m_p1,m_p4);
        addToLineWitBodyColorVect(m_p2,m_p3);
        addToLineWitBodyColorVect(m_p2,p5);
        addToLineWitBodyColorVect(m_p1,p5);
        addToLineWitBodyColorVect(m_p4,p6);
        addToLineWitBodyColorVect(m_p3,p6);

        //std::cout<<" sdsfdfd ";
        m_currentPosition += directionUpOrDown*m_speed;
        if (m_currentPosition > 0.9)
        {
            m_currentPosition = 0.9; 

        }
        else if (m_currentPosition < 0.0)
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
        // Do nothing
    }
    enemy::move();
}
