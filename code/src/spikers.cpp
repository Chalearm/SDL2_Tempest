#include "spikers.h"

spikers::spikers(std::shared_ptr<std::vector<walkPath<double> > >& refLanes,const double& scale, const point<double>& refPoint):
enemy(refLanes,scale,refPoint),
m_movingTrack()
{
	// random speed 1 - 3%
	m_speed = randomFn(3.0,1.0);
	// find the center point of the bottom line in the lane
    // to create a line of moving track

}

spikers::~spikers()
{

}
spikers::spikers(const spikers& obj):
enemy(obj)
{}

spikers& spikers::operator=(const spikers& obj)
{
	if (this != &obj)
	{
         enemy::operator=(obj);
	}
	else
	{
		// Do nothing
	}
	return *this;
}


std::vector<aLine<double> > spikers::drawEnemy()
{
	return std::vector<aLine<double> >();
}

void spikers::move()
{

}