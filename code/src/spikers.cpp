#include "spikers.h"

spikers::spikers(std::shared_ptr<std::vector<walkPath<double> > >& refLanes,const point<double>& refPoint):
enemy(refLanes,refPoint),
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
void spikers::move()
{

}