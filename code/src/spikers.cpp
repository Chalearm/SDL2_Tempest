#include "spikers.h"

spikers::spikers(std::shared_ptr<std::vector<walkPath<double> > >& refLanes,const double& scale, const point<double>& refPoint):
enemy(refLanes,scale,refPoint),
m_movingTrack(),
m_trackColor(g_spikersTrackColor),
m_walkTrack(0.0),
m_moveDirection(1)
{
	// random speed 1 - 3%
	m_speed = enemy::randomFn(0.004,0.001);
	m_bodyColor = g_spikersColor;
	m_walkTrack = enemy::randomFn(0.7,0.3);
	m_timeToAlive = randomFn(8.0,2.0);


	// find the center point of the bottom line in the lane
    // to create a line of moving track
	const point<double> p1 = findPointInBetweenALane(refLanes->at(m_beingLane),0.0,0.5);
	const point<double> p2 = findPointInBetweenALane(refLanes->at(m_beingLane),m_walkTrack,0.5);
	m_movingTrack = aLine<double>(p1,p2);

}

spikers::~spikers()
{

}
spikers::spikers(const spikers& obj):
enemy(obj),
m_movingTrack(obj.m_movingTrack),
m_trackColor(obj.m_trackColor),
m_walkTrack(obj.m_walkTrack),
m_moveDirection(obj.m_moveDirection)
{}

spikers& spikers::operator=(const spikers& obj)
{
	if (this != &obj)
	{
         enemy::operator=(obj);
         m_movingTrack = obj.m_movingTrack;
         m_trackColor = obj.m_trackColor;
         m_walkTrack = obj.m_walkTrack;
         m_moveDirection = obj.m_moveDirection;
	}
	else
	{
		// Do nothing
	}
	return *this;
}


std::vector<lineWithColor> spikers::drawEnemy()
{
	return m_lines;
}

void spikers::move()
{

    if ((m_isTimeUp) && (static_cast<int>(m_currentPosition) <= m_walkTrack) )
    {
        m_lines.clear();
        addToLineVect(m_movingTrack[P1],m_movingTrack[P2],m_trackColor);
        //eulidianDis
        const double widthOfTanker = 0.4;// 0.01 - 1.0  (1% to 100%)
        const double heightOfTanker = 0.07; // 0.01 - 1.0 (1% to 100%) 100% is the length of the lanes
        walkPath<double> aWalkpath = m_refLanes->at(m_beingLane);


        const point<double> p1 = findPointInBetweenALane(aWalkpath,m_currentPosition,0.5);
        const point<double> p2 = findPointInBetweenALane(aWalkpath,m_currentPosition+0.01,0.5);
        const point<double> p3 = findPointInBetweenALane(aWalkpath,m_currentPosition+0.01,0.55);
        const point<double> p4 = findPointInBetweenALane(aWalkpath,m_currentPosition-0.01,0.55);
        const point<double> p5 = findPointInBetweenALane(aWalkpath,m_currentPosition-0.01,0.45);
        const point<double> p6 = findPointInBetweenALane(aWalkpath,m_currentPosition+0.02,0.45);
        const point<double> p7 = findPointInBetweenALane(aWalkpath,m_currentPosition+0.02,0.6);
        const point<double> p8 = findPointInBetweenALane(aWalkpath,m_currentPosition-0.02,0.6);
        const point<double> p9 = findPointInBetweenALane(aWalkpath,m_currentPosition-0.02,0.4);
        const point<double> p10 = findPointInBetweenALane(aWalkpath,m_currentPosition+0.02,0.4);

//addToLineVect
        addToLineWitBodyColorVect(p1,p2);
        addToLineWitBodyColorVect(p2,p3);
        addToLineWitBodyColorVect(p3,p4);
        addToLineWitBodyColorVect(p4,p5);
        addToLineWitBodyColorVect(p5,p6);
        addToLineWitBodyColorVect(p6,p7);
        addToLineWitBodyColorVect(p7,p8);
        addToLineWitBodyColorVect(p8,p9);
        addToLineWitBodyColorVect(p9,p10);

        //std::cout<<" sdsfdfd ";
        m_currentPosition += m_moveDirection*m_speed;
        if (m_currentPosition > m_walkTrack)
        {
            m_currentPosition = m_walkTrack;
            m_moveDirection = -1;

        }
        else if (m_currentPosition < 0.0)
        {
        	m_moveDirection = 1;
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