//  
//
//     player
//
//     define in header player
//     class player
//     
//     player is a class which is for hanndling the player 
//
//
#include "player.h"

player::player(std::shared_ptr<std::vector<walkPath<double> > > &refLanes, const double& scale, const point<double>& refPoint):
motion2D(refLanes,scale,refPoint), 
m_currentPosition(1.0),
m_numberOfLife(g_nuberOfPlayerLife),
m_beingLane(0)
{

}

player::player(const player& obj):
motion2D(obj),
m_currentPosition(obj.m_currentPosition),
m_numberOfLife(obj.m_numberOfLife),
m_beingLane(obj.m_beingLane)
{
}

player& player::operator=(const player& obj)
{
    if (this != &obj)
    {
        motion2D::operator=(obj);
        m_currentPosition = obj.m_currentPosition;
        m_numberOfLife = obj.m_numberOfLife;
        m_beingLane = obj.m_beingLane;
    }
    else
    {
    	// Do nothing
    }
    return *this;
}

player::~player()
{

}

void player::move()
{
	m_lines.clear();

}


std::vector<lineWithColor> player::draw()
{
    return m_lines;
}
